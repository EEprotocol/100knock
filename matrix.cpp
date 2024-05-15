#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <cmath>
#include <ctime>
#include <iostream>
#include <ostream>
#include <random>

using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;

int randomint(int arg1 = -3, int arg2 = 3) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(arg1, arg2);
  return dis(gen);
}

int main() {
  for (int k = 0; k < 1; k = k) {

    MatrixXd m(3, 3);
    m(0, 0) = randomint(-9, 9);
    m(1, 0) = 0;
    m(2, 0) = 0;
    m(0, 1) = 0;
    m(1, 1) = randomint(-9, 9);
    m(2, 1) = 0;
    m(0, 2) = 0;
    m(1, 2) = 0;
    m(2, 2) = randomint(-9, 9);

    MatrixXd P(3, 3);
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 3; i++) {
        P(i, j) = randomint();
      }
    }

    MatrixXd Pinv(3, 3);
    if (P.determinant() == 1) {
      Pinv = P.inverse();
      MatrixXd Normp(3, 3);
      Normp = m * P;
      MatrixXd Norm(3, 3);
      Norm = Pinv * Norm;
      int check = 1;
      for (int l = 0; l < 3; l++) {
        for (int m = 0; m < 3; m++) {
          if (Norm(l, m) > 9 || Norm(l, m) < -9) {
            check = 0;
          } else {
            check = check;
          }
          if (Norm(l, m) < 0.01) {
            Norm(l, m) = 0;
          }
        }
      }
      if (check == 1) {
        std::cout << "Pinv" << std::endl << Pinv << std::endl;
        std::cout << "m" << std::endl << m << std::endl;
        std::cout << "P is" << std::endl << P << std::endl;
        std::cout << "Normp is " << std::endl << Normp << std::endl;
        std::cout << "Norm is " << std::endl << Norm << std::endl;
        std::cout << "\\item \\begin{pmatrix}" << std::endl;
        for (int l = 0; l < 3; l++) {
          std::cout << Norm(l, 0) << "&" << Norm(l, 1) << "&" << Norm(l, 2);
          std::cout << "\\\\" << endl;
        }
        std::cout << "\\end{pmatrix}" << std::endl;
        k = k + 1;
      } else {
        k = k;
      }
    }
  }
}
