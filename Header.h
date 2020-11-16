#pragma once
#include "RandomNumber.h"
#include "GR.h"
#include "Random.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define EPSILON 0.001

std::ofstream if1("values.txt");
std::ofstream if2("values_wn.txt");


struct NN {
	double c = -0.5;
	int d = 2;
	int a = -2;
	int b = 1;
	double A = 0.4;
	vvalues values;
	vvalues values_wn;

	void MainFun() {
		FillMap();
		auto pair_c = CI(values);
		auto pair_ce = CI(values_wn);
		double c_n = GoldenRatio(values_wn, pair_ce.first, pair_ce.second);
		double d_n = RandomSearch(values_wn, a, b);
		std::cout << "Standart: C = " << c << " , D = " << d << std::endl;
		std::cout << "Without noise: C = " << c_n << ", D = " << d_n << std::endl;
		double c_ = GoldenRatio(values, pair_c.first, pair_c.second);
		double d_ = RandomSearch(values, a, b);
		std::cout << "With noise: C = " << c_ << ", D = " << d_ << std::endl;
	}

	void FillMap() {
		for (double i = -2; i < b + 0.14; i += 0.15) {
			double x = i;
			double y = Calculate_ti(x);
			double y_ = c * x + d;
			if1 << "(" << x << "," << y << ") ";
			values.push_back({ x, y });
			if2 << "(" << x << "," << y_ << ") ";
			values_wn.push_back({ x, y });
		}
	}

	double Calculate_ti(double x) {
		double t;
		double e = A * RandomNumberGenerator(-5, 5) / 10;
		t = c * x + d + e;
		return t;
	}


	double MIN(std::vector<double>& ci) {
		double min = ci[0];
		for (int i = 1; i < ci.size(); ++i) {
			if (ci[i] < min) {
				min = ci[i];
			}
		}
		return min;
	}

	double MAX(std::vector<double>& ci) {
		double max = ci[0];
		for (int i = 1; i < ci.size(); ++i) {
			if (ci[i] > max) {
				max = ci[i];
			}
		}
		return max;
	}


	std::pair<double,double> CI(const vvalues& val) {
		std::vector<double> ci;
		for (const auto& p : val) {
			if (p.first != 0) {
				ci.push_back(p.second / p.first);
			}
			else {
				ci.push_back(p.second);
			}
		}
		auto ci_min = MIN(ci);
		auto ci_max = MAX(ci);
		return { ci_min, ci_max };
	}

};
