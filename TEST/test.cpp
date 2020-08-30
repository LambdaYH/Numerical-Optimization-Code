#include<Eigen/Dense>
#include<iostream>
using Eigen::VectorXd;
using Eigen::MatrixXf;
using std::cout;
using std::endl;
int main() {
	Eigen::VectorXf a(3);
	Eigen::MatrixXf b(3,3); //should init in this way
	a << 1,
		4,
		7;
	b << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	cout << b << endl;
	cout << a.transpose() * b * a << endl;
	
}