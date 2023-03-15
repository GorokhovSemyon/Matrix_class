#ifndef DETERMINANT_MATRIXCLASS_H
#define DETERMINANT_MATRIXCLASS_H
#include <iostream>
#include <vector>
#include <cmath>

class Matrix {
    std::vector<std::vector<double>> data;
    int n; // matrix size

public:
    Matrix(int n);

    void set(int i, int j, double value);
    double get(int i, int j);
    void print();
    int size() const;
    bool isDegenerate() const;

    std::vector<double> solve(std::vector<double> b);
    Matrix inverse() const;

    bool operator==(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    std::vector<double>& operator[](int i);
    const std::vector<double>& operator[](int i) const;
};

#endif //DETERMINANT_MATRIXCLASS_H
