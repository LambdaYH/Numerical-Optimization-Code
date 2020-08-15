/*
*   Numerical Optimization
*   P41
*   Procedure 3.1(Backtracking Line Search)
*/
#include <Eigen/Dense>
using namespace Eigen;
typedef Eigen::Matrix<double, 1, Dynamic> VectorXdou;
extern double f(const VectorXdou& x_k, const VectorXdou& p_k = VectorXdou(0), double a = 0);
extern bool compare2F(const VectorXdou &x_k,const VectorXdou &p_k,const double &a,const double &c);
VectorXdou gradient(VectorXdou &x_k);
int main(){
    double _a;
    double p,c;
    auto a=_a;
    VectorXdou x_k,p_k;
    while(!compare2F(x_k,p_k,a,c)){
        a=p*a;
    }
    auto ak=a;
    return 0;

}
double f(const VectorXdou &x_k,const VectorXdou &p_k,double a){
    //object funtions
    return 0;
}
bool compare2F(const VectorXdou &x_k,const VectorXdou &p_k,const double &a,const double &c){
    return f(x_k,p_k,a)<=f(x_k);
}
VectorXdou gradient(VectorXdou &x_k){
    //gradient of vc
    return VectorXdou(0);
}