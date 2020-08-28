#include<Eigen/Dense>
#include<iostream>
using Eigen::VectorXd;
using Eigen::MatrixXf;

int main() {
	Eigen::Vector4d xk;
	MatrixXf pk(4,4);
	for (int i = 0; i < 5; ++i) {
		xk(i) = i;
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			pk(i, j) = i + j;
		}
	}
	auto temp = pk * pk;
	std::cout << temp << std::endl;
}