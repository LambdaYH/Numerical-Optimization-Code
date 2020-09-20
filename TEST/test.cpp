#include<Eigen/Dense>
#include<iostream>
#include<vector>
using Eigen::VectorXd;
using Eigen::MatrixXf;
using std::cout;
using std::endl;
using namespace std;
/*
int main() {
	Eigen::VectorXf a(3);
	Eigen::MatrixXf b(3,3); //should init in this way
	a << 1,
		4,
		7;
	b << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	cout << b << endl;
	cout << a.transpose() * b * a << endl;
	
}
*/
int main() {
	int i;
	vector<int> v_i;
	while (cin >> i) {
		v_i.push_back(i);
	}
	for (auto& j : v_i) {
		cout << j << endl;
	}
}