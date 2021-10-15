#include "Equation.h"
#include "Teacher.h"
#include "Students.h"

void ReadExamTasks(vector<QuadEquation>& tasks, std::ifstream& tasksFile) {
	double a, b, c;
	do {
		tasksFile >> a >> b >> c;
		QuadEquation curEquation(a, b, c);
		tasks.push_back(curEquation);
	} while (!tasksFile.eof());
}

int main(void) {
	std::ifstream ExamTasks("Exam.txt");
	std::ifstream Students("Students.txt");
	std::ofstream Results("Results.txt");

	vector<QuadEquation> tasks;
	ReadExamTasks(tasks, ExamTasks);
	Teacher teacher(tasks);

	std::string name;
	std::string rating;
	do {
		Students >> name >> rating;
		Letter studentAnswers;

		if (rating == "bad") {
			BadStudent student(name);
			studentAnswers.answers = student.SolveExam(tasks);
		}
		else if (rating == "normal") {
			NormalStudent student(name);
			studentAnswers.answers = student.SolveExam(tasks);
		}

		else if (rating == "good") {
			GoodStudent student(name);
			studentAnswers.answers = student.SolveExam(tasks);
		}

		studentAnswers.studentName = name;
		teacher.GetLetter(studentAnswers);
	} while (!Students.eof());

	teacher.PublishResults(Results);

	ExamTasks.close();
	Students.close();
	Results.close();
	return 0;
}