#include "matrixClass.h"
#include <gtest/gtest.h>

TEST(MatrixTest, 1th_Ans) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 1.);
  A.set(0, 1, 0.);
  A.set(0, 2, 0.);
  A.set(0, 3, 0.);

  A.set(1, 0, 0.);
  A.set(1, 1, 1.);
  A.set(1, 2, 0.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 0.);
  A.set(2, 2, 1.);
  A.set(2, 3, 0.);

  A.set(3, 0, 0.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 1.);

  std::vector<double> b = {1.0, 2.0, 3.0, 4.0};
  std::vector<double> x = A.solve(b);

  std::vector<double> Ans = {1.0, 2.0, 3.0, 4.0};

  ASSERT_TRUE(x == Ans);
}

TEST(MatrixTest, 1th_Inv) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 1.);
  A.set(0, 1, 0.);
  A.set(0, 2, 0.);
  A.set(0, 3, 0.);

  A.set(1, 0, 0.);
  A.set(1, 1, 1.);
  A.set(1, 2, 0.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 0.);
  A.set(2, 2, 1.);
  A.set(2, 3, 0.);

  A.set(3, 0, 0.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 1.);

  Matrix A_inv = A.inverse();

  Matrix A_inv_ans(4);
  A_inv_ans.set(0, 0, 1.);
  A_inv_ans.set(0, 1, 0.);
  A_inv_ans.set(0, 2, 0.);
  A_inv_ans.set(0, 3, 0.);
  A_inv_ans.set(1, 0, 0.);
  A_inv_ans.set(1, 1, 1.);
  A_inv_ans.set(1, 2, 0.);
  A_inv_ans.set(1, 3, 0.);
  A_inv_ans.set(2, 0, 0.);
  A_inv_ans.set(2, 1, 0.);
  A_inv_ans.set(2, 2, 1.);
  A_inv_ans.set(2, 3, 0.);
  A_inv_ans.set(3, 0, 0.);
  A_inv_ans.set(3, 1, 0.);
  A_inv_ans.set(3, 2, 0.);
  A_inv_ans.set(3, 3, 1.);

  ASSERT_TRUE(A_inv == A_inv_ans);
}

TEST(MatrixTest, 2th_Ans) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 1.);
  A.set(0, 1, 0.);
  A.set(0, 2, 0.);
  A.set(0, 3, 0.);

  A.set(1, 0, 0.);
  A.set(1, 1, 2.);
  A.set(1, 2, 0.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 0.);
  A.set(2, 2, 3.);
  A.set(2, 3, 0.);

  A.set(3, 0, 0.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 4.);

  std::vector<double> b = {1.0, 2.0, 3.0, 4.0};
  std::vector<double> x = A.solve(b);

  std::vector<double> Ans = {1.0, 1.0, 1.0, 1.0};

  ASSERT_TRUE(x == Ans);
}

TEST(MatrixTest, 2th_Inv) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 1.);
  A.set(0, 1, 0.);
  A.set(0, 2, 0.);
  A.set(0, 3, 0.);

  A.set(1, 0, 0.);
  A.set(1, 1, 2.);
  A.set(1, 2, 0.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 0.);
  A.set(2, 2, 3.);
  A.set(2, 3, 0.);

  A.set(3, 0, 0.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 4.);

  Matrix A_inv = A.inverse();

  Matrix A_inv_ans(4);
  A_inv_ans.set(0, 0, 1.);
  A_inv_ans.set(0, 1, 0.);
  A_inv_ans.set(0, 2, 0.);
  A_inv_ans.set(0, 3, 0.);
  A_inv_ans.set(1, 0, 0.);
  A_inv_ans.set(1, 1, 0.5);
  A_inv_ans.set(1, 2, 0.);
  A_inv_ans.set(1, 3, 0.);
  A_inv_ans.set(2, 0, 0.);
  A_inv_ans.set(2, 1, 0.);
  A_inv_ans.set(2, 2, 0.3333333333333333);
  A_inv_ans.set(2, 3, 0.);
  A_inv_ans.set(3, 0, 0.);
  A_inv_ans.set(3, 1, 0.);
  A_inv_ans.set(3, 2, 0.);
  A_inv_ans.set(3, 3, 0.25);

  ASSERT_TRUE(A_inv == A_inv_ans);
}

TEST(MatrixTest, 3th_Ans) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 0.);
  A.set(0, 1, 0.);
  A.set(0, 2, 0.);
  A.set(0, 3, 1.);

  A.set(1, 0, 0.);
  A.set(1, 1, 0.);
  A.set(1, 2, 2.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 3.);
  A.set(2, 2, 0.);
  A.set(2, 3, 0.);

  A.set(3, 0, 4.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 0.);

  std::vector<double> b = {1.0, 1.0, 1.0, 1.0};
  std::vector<double> x = A.solve(b);

  std::vector<double> Ans = {0.250, 0.3333333333333333, 0.5, 1.0};

  ASSERT_TRUE(x == Ans);
}

TEST(MatrixTest, 3th_Inv) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 0.);
  A.set(0, 1, 0.);
  A.set(0, 2, 0.);
  A.set(0, 3, 1.);

  A.set(1, 0, 0.);
  A.set(1, 1, 0.);
  A.set(1, 2, 2.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 3.);
  A.set(2, 2, 0.);
  A.set(2, 3, 0.);

  A.set(3, 0, 4.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 0.);

  Matrix A_inv = A.inverse();

  Matrix A_inv_ans(4);
  A_inv_ans.set(0, 0, 0.);
  A_inv_ans.set(0, 1, 0.);
  A_inv_ans.set(0, 2, 0.);
  A_inv_ans.set(0, 3, 0.25);
  A_inv_ans.set(1, 0, 0.);
  A_inv_ans.set(1, 1, 0.);
  A_inv_ans.set(1, 2, 0.3333333333333333);
  A_inv_ans.set(1, 3, 0.);
  A_inv_ans.set(2, 0, 0.);
  A_inv_ans.set(2, 1, 0.5);
  A_inv_ans.set(2, 2, 0.);
  A_inv_ans.set(2, 3, 0.);
  A_inv_ans.set(3, 0, 1.);
  A_inv_ans.set(3, 1, 0.);
  A_inv_ans.set(3, 2, 0.);
  A_inv_ans.set(3, 3, 0.);

  ASSERT_TRUE(A_inv == A_inv_ans);
}

TEST(MatrixTest, 4th_Ans) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 1.);
  A.set(0, 1, 2.);
  A.set(0, 2, 0.);
  A.set(0, 3, 0.);

  A.set(1, 0, 2.);
  A.set(1, 1, 4.);
  A.set(1, 2, 3.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 2.);
  A.set(2, 2, 0.);
  A.set(2, 3, 0.);

  A.set(3, 0, 0.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 4.);

  std::vector<double> b = {1.0, 1.0, 1.0, 1.0};
  std::vector<double> x = A.solve(b);

  std::vector<double> Ans = {0.0, 0.5, -0.3333333333333333, 0.25};

  ASSERT_TRUE(x == Ans);
}

TEST(MatrixTest, 4th_Inv) {
  int n = 4; // matrix size
  Matrix A(n);

  // set matrix values
  A.set(0, 0, 1.);
  A.set(0, 1, 2.);
  A.set(0, 2, 0.);
  A.set(0, 3, 0.);

  A.set(1, 0, 2.);
  A.set(1, 1, 4.);
  A.set(1, 2, 3.);
  A.set(1, 3, 0.);

  A.set(2, 0, 0.);
  A.set(2, 1, 2.);
  A.set(2, 2, 0.);
  A.set(2, 3, 0.);

  A.set(3, 0, 0.);
  A.set(3, 1, 0.);
  A.set(3, 2, 0.);
  A.set(3, 3, 4.);

  Matrix A_inv = A.inverse();

  Matrix A_inv_ans(4);
  A_inv_ans.set(0, 0, 1.);
  A_inv_ans.set(0, 1, 0.);
  A_inv_ans.set(0, 2, -1.);
  A_inv_ans.set(0, 3, 0.);
  A_inv_ans.set(1, 0, 0.);
  A_inv_ans.set(1, 1, 0.);
  A_inv_ans.set(1, 2, 0.5);
  A_inv_ans.set(1, 3, 0.);
  A_inv_ans.set(2, 0, -0.6666666666666666);
  A_inv_ans.set(2, 1, 0.3333333333333333);
  A_inv_ans.set(2, 2, 0.);
  A_inv_ans.set(2, 3, 0.);
  A_inv_ans.set(3, 0, 0.);
  A_inv_ans.set(3, 1, 0.);
  A_inv_ans.set(3, 2, 0.);
  A_inv_ans.set(3, 3, 0.25);

  ASSERT_TRUE(A_inv == A_inv_ans);
}

 TEST(MatrixTest, 5th_Ans) {
 int n = 4; // matrix size
 Matrix A(n);

// set matrix values
 A.set(0, 0, 1.);
 A.set(0, 1, 2.);
 A.set(0, 2, 3.);
 A.set(0, 3, 4.);

 A.set(1, 0, 5.);
 A.set(1, 1, 6.);
 A.set(1, 2, 7.);
 A.set(1, 3, 8.);

 A.set(2, 0, 9.);
 A.set(2, 1, 10.);
 A.set(2, 2, 11.);
 A.set(2, 3, 12.);

 A.set(3, 0, 16.);
 A.set(3, 1, 15.);
 A.set(3, 2, 14.);
 A.set(3, 3, 13.);

 std::vector<double> b = {1.0, 1.0, 1.0, 1.0};
 std::vector<double> x = A.solve(b);

 std::vector<double> Ans = {0.0, 0.0, 0.0, 0.0};

 ASSERT_TRUE(x == Ans);
 }

 TEST(MatrixTest, 5th_Inv) {
 int n = 4; // matrix size
 Matrix A(n);

// set matrix values
 A.set(0, 0, 1.);
 A.set(0, 1, 2.);
 A.set(0, 2, 3.);
 A.set(0, 3, 4.);

 A.set(1, 0, 5.);
 A.set(1, 1, 6.);
 A.set(1, 2, 7.);
 A.set(1, 3, 8.);

 A.set(2, 0, 9.);
 A.set(2, 1, 10.);
 A.set(2, 2, 11.);
 A.set(2, 3, 12.);

 A.set(3, 0, 16.);
 A.set(3, 1, 15.);
 A.set(3, 2, 14.);
 A.set(3, 3, 13.);

 Matrix A_inv = A.inverse();

 Matrix A_inv_ans(4);
 A_inv_ans.set(0, 0, 0.);
 A_inv_ans.set(0, 1, 0.);
 A_inv_ans.set(0, 2, 0.);
 A_inv_ans.set(0, 3, 0.);
 A_inv_ans.set(1, 0, 0.);
 A_inv_ans.set(1, 1, 0.);
 A_inv_ans.set(1, 2, 0.);
 A_inv_ans.set(1, 3, 0.);
 A_inv_ans.set(2, 0, 0.);
 A_inv_ans.set(2, 1, 0.);
 A_inv_ans.set(2, 2, 0.);
 A_inv_ans.set(2, 3, 0.);
 A_inv_ans.set(3, 0, 0.);
 A_inv_ans.set(3, 1, 0.);
 A_inv_ans.set(3, 2, 0.);
 A_inv_ans.set(3, 3, 0.);

 ASSERT_TRUE(A_inv == A_inv_ans);
 }

TEST(MatrixTest, 6th_Ans) {
int n = 4; // matrix size
Matrix A(n);

// set matrix values
A.set(0, 0, 1.);
A.set(0, 1, 2.);
A.set(0, 2, 3.);
A.set(0, 3, 4.);

A.set(1, 0, -1.);
A.set(1, 1, -2.);
A.set(1, 2, 0.);
A.set(1, 3, 3.);

A.set(2, 0, 0.);
A.set(2, 1, 6.);
A.set(2, 2, 11.);
A.set(2, 3, 2.);

A.set(3, 0, 4.);
A.set(3, 1, -2.);
A.set(3, 2, 1.);
A.set(3, 3, 0.);

std::vector<double> b = {5.0, -2.0, 14.0, 4.0};
std::vector<double> x = A.solve(b);

std::vector<double> Ans = {1.0, 0.5, 1., 0.};

ASSERT_TRUE(x == Ans);
}

TEST(MatrixTest, 6th_Inv) {
int n = 4; // matrix size
Matrix A(n);

// set matrix values
A.set(0, 0, 1.);
A.set(0, 1, 2.);
A.set(0, 2, 3.);
A.set(0, 3, 4.);

A.set(1, 0, -1.);
A.set(1, 1, -2.);
A.set(1, 2, 0.);
A.set(1, 3, 3.);

A.set(2, 0, 0.);
A.set(2, 1, 6.);
A.set(2, 2, 11.);
A.set(2, 3, 2.);

A.set(3, 0, 4.);
A.set(3, 1, -2.);
A.set(3, 2, 1.);
A.set(3, 3, 0.);

Matrix A_inv = A.inverse();
//A_inv.print();

Matrix A_inv_ans(4);
A_inv_ans.set(0, 0, 0.164179);
A_inv_ans.set(0, 1, -0.179104);
A_inv_ans.set(0, 2, -0.0597015);
A_inv_ans.set(0, 3, 0.164179);
A_inv_ans.set(1, 0, 0.242537);
A_inv_ans.set(1, 1, -0.287313);
A_inv_ans.set(1, 2, -0.0541045);
A_inv_ans.set(1, 3, -0.132463);
A_inv_ans.set(2, 0, -0.171642);
A_inv_ans.set(2, 1, 0.141791);
A_inv_ans.set(2, 2, 0.130597);
A_inv_ans.set(2, 3, 0.0783582);
A_inv_ans.set(3, 0, 0.216418);
A_inv_ans.set(3, 1, 0.0820896);
A_inv_ans.set(3, 2, -0.0559701);
A_inv_ans.set(3, 3, -0.0335821);

ASSERT_NEAR(A_inv[0][0], A_inv_ans[0][0], 1e-5);
ASSERT_NEAR(A_inv[0][1], A_inv_ans[0][1], 1e-5);
ASSERT_NEAR(A_inv[0][2], A_inv_ans[0][2], 1e-5);
ASSERT_NEAR(A_inv[0][3], A_inv_ans[0][3], 1e-5);
ASSERT_NEAR(A_inv[1][0], A_inv_ans[1][0], 1e-5);
ASSERT_NEAR(A_inv[1][1], A_inv_ans[1][1], 1e-5);
ASSERT_NEAR(A_inv[1][2], A_inv_ans[1][2], 1e-5);
ASSERT_NEAR(A_inv[1][3], A_inv_ans[1][3], 1e-5);
ASSERT_NEAR(A_inv[2][0], A_inv_ans[2][0], 1e-5);
ASSERT_NEAR(A_inv[2][1], A_inv_ans[2][1], 1e-5);
ASSERT_NEAR(A_inv[2][2], A_inv_ans[2][2], 1e-5);
ASSERT_NEAR(A_inv[2][3], A_inv_ans[2][3], 1e-5);
ASSERT_NEAR(A_inv[3][0], A_inv_ans[3][0], 1e-5);
ASSERT_NEAR(A_inv[3][1], A_inv_ans[3][1], 1e-5);
ASSERT_NEAR(A_inv[3][2], A_inv_ans[3][2], 1e-5);
ASSERT_NEAR(A_inv[3][3], A_inv_ans[3][3], 1e-5);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
