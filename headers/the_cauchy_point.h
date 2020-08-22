#ifndef THE_CAUCHY_POINT_H
#define THE_CAUCHY_POINT_H
#include<Eigen/Dense>
class theCauchyPoint {
public:
	theCauchyPoint(const Eigen::VectorXd& g_fk, const Eigen::MatrixXf& Bk, const double& delta_k): g_fk(g_fk),Bk(Bk),delta_k(delta_k) {}
	Eigen::VectorXd getPk() {

	}
private:
	Eigen::VectorXd g_fk;
	Eigen::MatrixXf Bk;
	double delta_k;
	double gettk();
	double min();
};
#endif