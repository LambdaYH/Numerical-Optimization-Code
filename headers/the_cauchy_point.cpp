#include<the_cauchy_point.h>
#include<utility>
#include<cmath>

using Eigen::VectorXd;
using Eigen::MatrixXf;

VectorXd theCauchyPoint::getPk() {
    return -gettk() * delta_k * g_fk / g_fk.norm();
}

double theCauchyPoint::gettk() {
    if ((g_fk.transpose() * Bk * g_fk)(0, 0) <= 0) {
        return 1;
    }
    else {
        return min();
    }

}
double theCauchyPoint::min() {
    auto cal_temp = pow(g_fk.norm(), 3) / (delta_k * (g_fk.transpose() * Bk * g_fk)(0, 0));
    if (cal_temp > 1)
        return 1;
    else
        return cal_temp;
}