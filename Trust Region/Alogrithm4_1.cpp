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
#include"someFuntions.h"

using std::cout;
using std::cin;
using std::endl;

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
    Eigen::Matrix<double, 3, 1> g_fk;
    Eigen::Matrix<double, 3, 1> xk0;
    std::vector < Eigen::Matrix<double, 3, 1>, Eigen::aligned_allocator<Eigen::Matrix<double, 3, 1>>> xk_s;
    Eigen::Matrix<double, 3, 3> Bk;

    g_fk << 1, 2, 3;
    xk0 << 1, 2, 3;
    Bk << 1, 2, 3, 
        4, 5, 6,
        7, 8, 9;
    double deltak = args[1];
    double deltakp = deltak;
    int limit = 5;
    for (int k = 0;k <= limit ; ++k) {
        theCauchyPoint<3> TCP{g_fk, Bk, deltak};
        auto pk = TCP.getPk();
        someFunctions<3> sf{ pk,xk_s[k],Bk };
        auto rhopk = sf.get_rhok();
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
