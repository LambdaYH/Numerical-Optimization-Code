#ifndef THE_DOGLEG_METHOD_H
#define THE_DOGLEG_METHOD_H
#include<Eigen/Dense>
template<int T>
class the_dogleg_method {
public:
	the_dogleg_method(Eigen::Matrix<double, T, T> & B, Eigen::Matrix<double, T, 1> & g, double tao) :B(B), g(g), tao(tao) {}
	Eigen::Matrix<double, T, 1> getpt();
private:
	Eigen::Matrix<double, T, T> B;
	Eigen::Matrix<double, T, 1> g;
	double tao = 0;
	Eigen::Matrix<double, T, 1> get_pb();
	Eigen::Matrix<double, T, 1> get_pu();
};

template<int T>
Eigen::Matrix<double, T, 1> the_dogleg_method<T>::getpt() {
	if (tao >= 0 && tao <= 1) {
		return tao * get_pu();
	}
	else if (tao >= 1 && tao <= 2) {
		return get_pu() + (tao - 1)(get_pb() - get_pu());
	}
}

template<int T>
Eigen::Matrix<double, T, 1> the_dogleg_method<T>:: get_pb() {
	pb = -B.norm() / B.adjoin() * g;
	return pb;
}
template<int T>
Eigen::Matrix<double, T, 1> the_dogleg_method<T>::get_pu() {
	pu = -(g.transpose() * g / g.transpose() * B * g) * g;
	return pu;
}
#endif