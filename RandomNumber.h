#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include <map>
#include <algorithm>
#include <fstream>


int GetRandomFromRange(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	srand(std::chrono::steady_clock::now().time_since_epoch().count());
	return static_cast<int>(rand() * fraction * (max - min) + min);
}

double average_distance(const std::vector<int>& permutation) {
	double distance_sum = 0;
	for (int i = 0; i < 1000; i++)
		distance_sum += abs(permutation[i] - i);

	return distance_sum / 1000;
}


double NumberConstructor(int a, int b, int number) {
	double result = number;
	while (result >= 1) {
		result /= 10;
	}
	int temp = GetRandomFromRange(a, b);
	if (temp == b) {
		temp -= 1;
	}
	return temp + result;
}

double RandomNumberGenerator(double a, double b) {
	std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::vector<int> permutation(1000);

	for (int i = 0; i < 1000; i++)
		permutation[i] = i;
	shuffle(permutation.begin(), permutation.end(), rng);
	double part1 = average_distance(permutation);
	shuffle(permutation.begin(), permutation.end(), rng);
	double part2 = average_distance(permutation);
	int index = permutation[static_cast<int>(abs(a) + abs(b) + 1) % 1000] + 1;
	double a_ = part1 * part2;
	int b_ = ceil(a_);
	int result = b_ % index;
	return NumberConstructor(a, b, result);
}