#pragma once

#include <iostream>
#include "Equation.h"
#include <vector>

using std::vector;

class Letter {
public:
	vector<Solution> answers;
	std::string studentName;
};

class Student {
private:
	std::string name;
public:
	Student(std::string name) : name(name) {}
	virtual Solution SolveEquation(const QuadEquation& equation) = 0;
	vector<Solution> SolveExam(const vector<QuadEquation>& tasks);
};

class BadStudent: public Student {
public:
	BadStudent(std::string name) : Student(name) {}
	Solution SolveEquation(const QuadEquation& equation)override;
};

class NormalStudent : public Student {
public:
	NormalStudent(std::string name) : Student(name) {}
	Solution SolveEquation(const QuadEquation& equation)override;
};

class GoodStudent : public Student {
public:
	GoodStudent(std::string name) : Student(name) {}
	Solution SolveEquation(const QuadEquation& equation)override;
};