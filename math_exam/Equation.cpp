#include "Equation.h"

Solution QuadEquation::Solver()const {
	double x = 0.0, x1 = 0.0, x2 = 0.0;
	Solution solution;
	solution.numOfRoots = ZERO;
	if (A == 0) {
		if (B == 0) {
			if (C == 0)
				solution.numOfRoots = INF;
			else
				solution.numOfRoots = ZERO;
		}
		else {
			solution.root1 = -C / B;
			solution.numOfRoots = ONE;
		}
	}
	else {
		double D = Discriminant();
		if (D < 0)
			solution.numOfRoots = ZERO;
		else if (D == 0) {
			solution.root1 = -B / (2 * A);
			solution.numOfRoots = ONE;
		}
		else {
			solution.numOfRoots = TWO;
			solution.root1 = (-B + sqrt(D)) / (2 * A);
			solution.root2 = (-B - sqrt(D)) / (2 * A);
		}
	}

	return solution;
}