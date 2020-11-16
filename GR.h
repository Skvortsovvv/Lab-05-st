#pragma once
#include "MinSquare.h"

double GoldenRatio(vvalues& val, int a, int b) { // finding C. Arguments cmin, cmax.

	/*const double t = 0.5 * (1 + std::sqrt(5));
	const double eps = 0.01;
	double xL = a + (1 - 1 / t) * b;
	double xR = a + b / t;
	double w1 = 0;
	while ((b - a) > eps) {
		if (MinSquare(val,0, xL) < MinSquare(val,0, xR)) {
			b = xR;
			xR = a + b - xL;
		}
		else {
			a = xL;
			xL = a + b - xR;
		}
		if (xL > xR) {
			std::swap(xL, xR);
		}
	}
	if (MinSquare(val,0, a) < MinSquare(val, 0 , b)) {
		return a;
	}
	else {
		return b;
	}*/


	double epsilon = 0.01;
	bool flag = true;
	double tau = 1.618034;
	double _a = a;
	double _b = b;
	double len = std::abs(b - a);
	double len_k = len / tau;
	double left = b - len_k;
	double right = a + len_k;
	double L = _b - _a;
	while (flag) {
		if (MinSquare(val, left, 0) < MinSquare(val, right, 0)) {
			_b = right;
			right = left;
			left = _a + _b - right;
		}
		else {
			_a = left;
			left = right;
			right = _a + _b - left;
		}
		double L = _b - _a;
		if (L < epsilon) {
			flag = false;
		}
	}
	double x_min = (_a + _b) / 2;
	return x_min;
}