#ifndef ZOOM_H
#define ZOOM_H
#include<math.h>
double c1,c2;
double zoom(double alo,double ahi) {
	while (true) {
		auto aj = generate_aip1(alo, ahi);
		if ((phi(aj) > phi(0) + c1 * aj * derivation_phi(0)) | (phi(aj) >= phi(alo)))
			ahi = aj;
		else {
			auto d_phi = derivation_phi(aj);
			if (fabs(d_phi) <= -c2 * derivation_phi(0))
				return aj;
			if (d_phi * (ahi - alo) >= 0)
				ahi = alo;
			alo = aj;
		}
	}
	return 0;
}
//the object funtion f(x)
double object_function() {

}
//phi=f(xk+apk)
double phi(double a) {

}
//the derivation of phi
double derivation_phi(double a) {

}
//use interpolate to find a step length between a and b
double generate_aip1(const double a,const double b) {

}
#endif