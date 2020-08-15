#include"zoom.h"
#include<iostream>
#include<math.h>
using namespace std;
int main() {
	const double a0 = 0;

	//get the value of a1 & amax
	double a1, amax, _a;
A:	cout << "please enter the a1(a1>0) and amax" << endl;
	cin >> a1;
	if (a1 <= 0) goto A;
	cin >> amax;

	//start circulation
	double ai=a1,ai_1=a0;
	int i = 1;
	while (true) {
		if ((phi(ai) > phi(0) + c1 * ai * derivation_phi(0))|(phi(ai)>=phi(ai_1)&& i>1))
			_a = zoom(ai_1, ai); break;
		if (fabs(derivation_phi(ai)) <= -c2 * derivation_phi(0))
			_a = ai; break;
		if (derivation_phi(ai) >= 0)
			_a = zoom(ai, ai_1); break;
		ai_1 = ai;
		ai = generate_aip1(ai,amax);//use the approaches like the interpolation procedures, or simply set ai+1 to some constant multiple of ai
		++i;
	}

}

