#pragma once
#ifndef SOMEFUNCTIONS_H
#define SOMEFUNCTIONS_H
#include<Eigen/Dense>
template<int T>
class someFunctions {
public:
    someFunctions(const Eigen::Matrix<double, T, 1>& pk, const Eigen::Matrix<double, T, 1>& xk, const Eigen::Matrix<double, T, T> Bk) :pk(pk), xk(xk), Bk(Bk) {};
    double get_mk();
    Eigen::Matrix<double, T, 1> cal_gradient();
    double object_function(int model);
    double get_rhok();
private:
    Eigen::Matrix<double, T, 1> pk;
    Eigen::Matrix<double, T, 1> xk;
    Eigen::Matrix<double, T, T> Bk;
};

template<int T>
Eigen::Matrix<double, T, 1> someFunctions<T>::cal_gradient() {
    /*
    * calculate gradient of object funtions and return a vector
    */

    // return xk temporarily for debugging
    return xk;
}
template<int T>
double someFunctions<T>::object_function(int model) {
    /*
    * if(model == 1){
    *   return object_function(xk);
    * else{
    *   return object_function(xk)
    * }
    * }
    * return the object funtion value at specific xk
    */

    // return 0 temporatily for debugging
    return 0;
}

template<int T>
double someFunctions<T>::get_rhok() {
    return static_cast<double>((object_function(1) - object_function(2)) / (object_function(1) - get_mk()));
}

template<int T>
double someFunctions<T>::get_mk() {
    return static_cast<double>(object_function(1) + (cal_gradient().transpose() * pk).norm() + ((1 / 2) * pk.transpose() * Bk * pk));
}
#endif // !SOMEFUNTIONS_H



