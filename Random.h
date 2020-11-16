#pragma once
#include "MinSquare.h"

double CalcPoints(double P, double q) {
	double numerator = log(1 - P);
	double denominator = log(1 - q);
	return (numerator / denominator);
}
double FindMinX(vvalues val, double N, int a, int b) {
	double delta = (b - a) / N;
	double min_x = a + delta;
	for (size_t i = 2; i <= N; ++i) {
		double temp_x = a + delta * i;
		if (MinSquare(val, 0, min_x) < MinSquare(val, 0, temp_x)) {
			continue;
		}
		else {
			min_x = temp_x;
		}
	}
	return min_x;
}
double RandomSearch(vvalues& val, int a, int b) { // finding D. Arguments dmin, dmax
	std::vector<std::vector<double>> values(10);
	std::vector<std::vector<int>> arguments(10);
	double P = 0.9;
	for (size_t i = 0; i < 10; ++i) {
		double q = 0.005;
		for (size_t j = 0; j < 20; ++j) {
			double N = CalcPoints(P, q);
			arguments[i].push_back(floor(N));
			values[i].push_back(FindMinX(val, N, a, b));
			q += 0.005;
		}
		P += 0.01;
	}
	return values[0][0];
}