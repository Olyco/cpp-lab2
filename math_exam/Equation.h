#pragma once

#include <cmath>

enum SolutionCase {
	ZERO = 0, //No roots
	ONE,
	TWO,
	INF, //Inf number of roots
};

struct Solution {
	SolutionCase numOfRoots;
	double root1;
	double root2;
};

class  QuadEquation {
private:
	double A;
	double B;
	double C;
	double Discriminant()const {
		return B * B - 4 * A * C;
	}
public:
	QuadEquation(double a, double b, double c) {
		A = a;
		B = b;
		C = c;
	}
	Solution Solver()const;
};