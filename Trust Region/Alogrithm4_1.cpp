/*
*
*Algorithm4.1(Trust Region)
*P68
*
*Untested yet
*/
#include <Eigen/Dense>
#include<iostream>
#include<utility>

using std::cout;
using std::cin;
using std::endl;

using Eigen::VectorXd;
using Eigen::MatrixXf;

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
            if (0 < inputTemp < args[0]) {
                args[1] = inputTemp;
                ++i;
            }
            else {
                cout << "invalidate value, pls input again" << endl;
            }
            break;
        case 2:
            cout << "pls input the eta" << endl;
            if (0 <= inputTemp < 1 / 4) {
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
    
}

//The cauchy point
VectorXd getPk(){
    
}

double gettk(const VectorXd &g_fk,const MatrixXf &Bk, const double &delta_k){
    if ((g_fk.transpose() * Bk * g_fk)(0,0) <= 0) {
        return 1;
    }
    else {
        return min(g_fk, Bk, std::forward<double>(delta_k));
    }

}
double min(const VectorXd& g_fk, const MatrixXf& Bk, const double &delta_k) {
    //
}