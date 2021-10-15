#pragma once

#include "Equation.h"
#include "Students.h"
#include <fstream>

using std::vector;

class Teacher{
private:
    vector<Solution> correctAnswers;
    vector<Letter> inbox;
    bool Comparator(const Solution& studentAnswer, const Solution& correct)const;
public:
    Teacher(const vector<QuadEquation>& tasks);
    void GetLetter(const Letter& studentsAnswers) {
        inbox.push_back(studentsAnswers);
    }
    void PublishResults(std::ofstream& resFile);
};
