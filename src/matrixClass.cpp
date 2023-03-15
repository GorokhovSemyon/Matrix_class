#include "matrixClass.h"

Matrix::Matrix(int n) : n(n) {
  // initialize matrix with zeros
  for (int i = 0; i < n; i++) {
    std::vector<double> row(n, 0.0);
    data.push_back(row);
  }
}

void Matrix::set(int i, int j, double value) { data[i][j] = value; }

double Matrix::get(int i, int j) { return data[i][j]; }

void Matrix::print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << data[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

int Matrix::size() const { return n; }

std::vector<double> &Matrix::operator[](int i) { return data[i]; }
const std::vector<double> &Matrix::operator[](int i) const { return data[i]; }

Matrix Matrix::operator*(const Matrix &other) const {
  if (n != other.n) {
    throw std::invalid_argument("Matrices must be the same size");
  }
  Matrix result(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double sum = 0;
      for (int k = 0; k < n; k++) {
        sum += (*this)[i][k] * other[k][j];
      }
      result[i][j] = sum;
    }
  }
  return result;
}

// overload the == operator for matrix equality
bool Matrix::operator==(const Matrix &other) const {
    if (n != other.n) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

std::vector<double> Matrix::solve(std::vector<double> b) {
    std::vector<double> x(n, 0.0);
    if(this->isDegenerate()) return x;

    // Gaussian elimination with partial pivoting
  for (int k = 0; k < n; k++) {
    // find pivot row with largest absolute value
    int max_row = k;
    for (int i = k + 1; i < n; i++) {
      if (std::abs(data[i][k]) > std::abs(data[max_row][k])) {
        max_row = i;
      }
    }

    // swap rows if necessary
    if (max_row != k) {
      swap(data[k], data[max_row]);
      std::swap(b[k], b[max_row]);
    }

    // elimination
    for (int i = k + 1; i < n; i++) {
      double factor = data[i][k] / data[k][k];
      b[i] -= factor * b[k];
      for (int j = k + 1; j < n; j++) {
        data[i][j] -= factor * data[k][j];
      }
      data[i][k] = 0.0; // zero out lower triangle
    }
  }

  // back substitution
  for (int i = n - 1; i >= 0; i--) {
    x[i] = b[i];
    for (int j = i + 1; j < n; j++) {
      x[i] -= data[i][j] * x[j];
    }
    x[i] /= data[i][i];
  }

  return x;
}

// method for checking if the matrix is degenerate
bool Matrix::isDegenerate() const {
    // create a copy of the original matrix
    Matrix copy(*this);

    // perform Gaussian elimination with partial pivoting
    for (int j = 0; j < n; j++) {
        // find pivot element
        int max_row = j;
        for (int i = j + 1; i < n; i++) {
            if (std::abs(copy[i][j]) > std::abs(copy[max_row][j])) {
                max_row = i;
            }
        }
        if (max_row != j) {
            // swap rows j and max_row
            std::swap(copy[j], copy[max_row]);
        }

        // divide row j by pivot element
        double pivot = copy[j][j];
        if (pivot == 0) {
            // matrix is singular
            return true;
        }
        for (int k = 0; k < n; k++) {
            copy[j][k] /= pivot;
        }

        // subtract row j from all other rows
        for (int i = 0; i < n; i++) {
            if (i != j) {
                double factor = copy[i][j];
                for (int k = 0; k < n; k++) {
                    copy[i][k] -= factor * copy[j][k];
                }
            }
        }
    }

    // if the matrix is not singular, it is not degenerate
    return false;
}

// method for inverting the matrix
Matrix Matrix::inverse() const {
  // create an identity matrix of the same size
  Matrix identity(n);

  if(this->isDegenerate()) return identity;

  for (int i = 0; i < n; i++) {
    identity[i][i] = 1.0;
  }

  // create a copy of the original matrix
  Matrix copy(*this);

  // perform Gaussian elimination with partial pivoting
  for (int j = 0; j < n; j++) {
    // find pivot element
    int max_row = j;
    for (int i = j + 1; i < n; i++) {
      if (std::abs(copy[i][j]) > std::abs(copy[max_row][j])) {
        max_row = i;
      }
    }
    if (max_row != j) {
      // swap rows j and max_row
      std::swap(copy[j], copy[max_row]);
      std::swap(identity[j], identity[max_row]);
    }

    // divide row j by pivot element
    double pivot = copy[j][j];
    if (pivot == 0) {
      // matrix is singular
      throw std::runtime_error("matrix is singular");
    }
    for (int k = 0; k < n; k++) {
      copy[j][k] /= pivot;
      identity[j][k] /= pivot;
    }

    // subtract row j from all other rows
    for (int i = 0; i < n; i++) {
      if (i != j) {
        double factor = copy[i][j];
        for (int k = 0; k < n; k++) {
          copy[i][k] -= factor * copy[j][k];
          identity[i][k] -= factor * identity[j][k];
        }
      }
    }
  }

  return identity;
}
