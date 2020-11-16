#pragma once
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using vvalues = std::vector<std::pair <double, double>>;

double function(double x, double c, double d) {
	return (c * x + d);
}


double MinSquare(vvalues val, double w1, double w0) { // c    d
	double sum = 0;
	for (const auto& p : val) {
		sum += (function(p.first, w1, w0) - p.second) * (function(p.first, w1, w0) - p.second);
	}
	return sum;
}