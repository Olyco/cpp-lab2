#include "Teacher.h"

bool Teacher::Comparator(const Solution& studentAnswer, const Solution& correct)const {
	int numOfRoots = studentAnswer.numOfRoots;
	if (numOfRoots == ZERO || numOfRoots == INF)
		return (numOfRoots == correct.numOfRoots);
	else if (numOfRoots == ONE)
		return (numOfRoots == correct.numOfRoots) && (studentAnswer.root1 == correct.root1);
	else if(numOfRoots ==TWO)
		return (numOfRoots == correct.numOfRoots) && (studentAnswer.root1 == correct.root1)\
		&& (studentAnswer.root2 == correct.root2);
}

Teacher:: Teacher(const vector<QuadEquation>& tasks) {
	for (size_t i = 0; i < tasks.size(); ++i)
		correctAnswers.push_back(tasks[i].Solver());
}

void Teacher::PublishResults(std::ofstream& resFile) {
	int numOfStudents = inbox.size();
	int numOfEquations = correctAnswers.size();
	int score = 0;
	resFile << "Student name	" << "Score" << std::endl;
	for (int i = 0; i < numOfStudents; ++i) {
		score = 0;
		for (int n = 0; n < numOfEquations; ++n) {
			if (Comparator(inbox[i].answers[n], correctAnswers[n]))
				++score;
		}
		resFile << inbox[i].studentName <<"		"<< score << std::endl;
	}
}