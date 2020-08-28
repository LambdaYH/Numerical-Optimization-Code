/*
*
*Algorithm4.1(Trust Region)
*P68
*
*Untested yet
*/
#include <Eigen/Dense>
#include <Eigen/StdVector>
#include<iostream>
#include<utility>
#include<vector>
#include"the_cauchy_point.h"

using std::cout;
using std::cin;
using std::endl;

using Eigen::VectorXd;
using Eigen::MatrixXf;

extern double mk(const VectorXd& pk, const VectorXd& xk, const MatrixXf& Bk);
extern double function(const VectorXd& xk);
extern VectorXd cal_gradient(const VectorXd& xk);
extern double getrhok(const VectorXd& xk, const VectorXd& pk, const MatrixXf& Bk);

//given delta delta0 and eta
int main() {

    //given delta delta0 and eta
    double args[]{ 0,0,0 };
    double inputTemp;
    int i = 0;
    while (i < 3)
    {
        cin >> inputTemp;
        switch (i)
        {
        case 0:
            cout << "pls input the delta:" << endl;
            if (inputTemp > 0) {
                args[0] = inputTemp;
                ++i;
            }
            else {
                cout << "invalidate value, pls input again" << endl;
            }
            break;
        case 1:
            cout << "pls input the delta0:" << endl;
            if (0 < inputTemp && inputTemp < args[0]) {
                args[1] = inputTemp;
                ++i;
            }
            else {
                cout << "invalidate value, pls input again" << endl;
            }
            break;
        case 2:
            cout << "pls input the eta" << endl;
            if (0 <= inputTemp && inputTemp < 1 / 4) {
                args[2] = inputTemp;
                ++i;
            }
            else {
                cout << "invalidate value, pls input again" << endl;
            }
            break;
        }
    }
    //start ciculation
    VectorXd g_fk;
    VectorXd xk0;
    std::vector < Eigen::VectorXd, Eigen::aligned_allocator<Eigen::VectorXd>> xk_s;
    MatrixXf Bk;
    double deltak = args[1];
    double deltakp = deltak;
    int limit;
    for (int k = 0;k < limit ; ++k) {
        theCauchyPoint TCP{g_fk, Bk, deltak};
        auto pk = TCP.getPk();
        auto rhopk = getrhok(xk_s[k], pk, Bk);
        if (rhopk < 1 / 4)
            deltakp = 1 / 4 * pk.norm();
        else {
            if (rhopk > 3 / 4 && pk.norm() == deltak)
                deltakp = 2 * deltak > args[0] ? args[0] : 2 * deltak;
            else
                deltakp = deltak;
            if (rhopk > args[2])
                xk_s.push_back(xk_s[k] + pk);
            else
                xk_s.push_back(xk_s[k]);
        }//notes 
        /*"[]{ return double{ 2 }; }" is a function object, you can't store that into a variable of type double.
            If you want to call the function, you need to use the function call operator():
            double random_number = []{ return 2.0; }();
        */
    }
}
//mk(p) = fk + (gradient_fk)^T*P + 1/2 * P^T*BK*P
double mk(const VectorXd &pk,const VectorXd& xk,const MatrixXf& Bk) {
    return function(xk) + (cal_gradient(xk).transpose() * pk).norm() + ((1 / 2) * pk.transpose() * Bk * pk)(0, 0);
}
//object function's gradient of the point in which x = xk
VectorXd cal_gradient(const VectorXd& xk) {
    
}
double function(const VectorXd& xk) {
    return 0;
}

double getrhok(const VectorXd& xk, const VectorXd& pk, const MatrixXf& Bk) {
    return (function(xk) - function(xk + pk)) / (function(xk) - mk(pk, xk, Bk));
}
