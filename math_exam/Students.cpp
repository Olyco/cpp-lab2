#include "Students.h"

Solution BadStudent::SolveEquation(const QuadEquation& equation) {
	Solution badSolution;
	badSolution.numOfRoots = ONE;
	badSolution.root1 = 0;
	return badSolution;
}

Solution NormalStudent::SolveEquation(const QuadEquation& equation) {
	int chance = rand() % 2;
	if (chance == 0)
		return equation.Solver();
	else {
		Solution badSolution;
		badSolution.numOfRoots = ONE;
		badSolution.root1 = 0;
		return badSolution;
	}
}

Solution GoodStudent::SolveEquation(const QuadEquation& equation) {
	return equation.Solver();
}

vector<Solution> Student::SolveExam(const vector<QuadEquation>& tasks) {
	vector<Solution> answers;
	for (size_t i = 0; i < tasks.size(); ++i)
		answers.push_back(SolveEquation(tasks[i]));
	return answers;
}

