#include<Eigen/Dense>
#include<iostream>
#include<typeinfo>
#include<the_cauchy_point.h>

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::cout;
using std::endl;
template<int T> class test_for_eigen;
auto testFunction(VectorXd& a, MatrixXd& b) -> decltype(a.transpose() * 1);
template<int T>
class test_for_eigen {
public:
	test_for_eigen(Eigen::Matrix<double, T, T>& b, Eigen::Matrix<double, T, 1>& a) :mat1(b), mat2(a) {}
	~test_for_eigen() {}
	double cal_test_mat();
private:
	Eigen::Matrix<double, T, T> mat1;
	Eigen::Matrix<double, T, 1> mat2;
};
template<int T>
inline double test_for_eigen<T>::cal_test_mat() {
	return static_cast<double>(mat2.transpose() * mat1 * mat2);
}
int main() {
	Eigen::Matrix<double, 3, 1> a;
	Eigen::Matrix<double, 3, 3> b; //should init in this wa
	a << 1, 2, 3;
	b << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	cout << a << "\n" << b <<endl;
	theCauchyPoint<3> testCaughypoint{ a,b,1 };
	auto test_ = testCaughypoint.getPk();
}

auto testFunction(VectorXd &a, MatrixXd &b) -> decltype(a.transpose() * 1){
	auto c = a.transpose() * 1 ;
	return c;
}


