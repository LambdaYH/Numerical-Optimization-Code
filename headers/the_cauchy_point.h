#ifndef THE_CAUCHY_POINT_H
#define THE_CAUCHY_POINT_H
#include<Eigen/Dense>
#include<utility>
#include<cmath>

template<int T>
class theCauchyPoint {
public:
	theCauchyPoint(const Eigen::Matrix<double, T, 1>& g_fk, const Eigen::Matrix<double, T, T> Bk, const double& delta_k): g_fk(g_fk),Bk(Bk),delta_k(delta_k) {}
	Eigen::Matrix<double, 3, 1> getPk();
private:
	Eigen::Matrix<double, T, 1> g_fk;
	Eigen::Matrix<double, T, T> Bk;
	double delta_k;
	double gettk();
	double min();
};

template<int T>
double theCauchyPoint<T>::min() {
    auto cal_temp = pow(g_fk.norm(), 3) / (delta_k * (g_fk.transpose() * Bk * g_fk).norm());
    if (cal_temp > 1)
        return 1;
    else
        return cal_temp;
}
template<int T>
double theCauchyPoint<T>::gettk() {
    if ((g_fk.transpose() * Bk * g_fk).norm() <= 0) {
        return 1;
    }
    else {
        return min();
    }

}
template<int T>
Eigen::Matrix<double, 3, 1> theCauchyPoint<T>::getPk() {
    return -gettk() * delta_k * g_fk / g_fk.norm();
}
#endif