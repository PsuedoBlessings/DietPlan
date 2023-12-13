#pragma once
#include <iostream>
#include <fstream>

using std::string;
using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::ifstream;
using std::istream;

class ExercisePlan
{
public:

	// the constructor of the class 
	ExercisePlan(const int newStepsGoal = 1000, const string newNamePlan = "Steps Goal", const string newDatePlan = "01/01/20XX");
	// the copy constructor of the class
	ExercisePlan(const ExercisePlan& copy);
	// the deconstrutor of this class
	~ExercisePlan();

	// the getters of this class
	int getStepsGoals() const;
	string getNamePlan() const;
	string getDatePlan() const;

	// the getters of this vlass
	void setStepsGoals(const int newStepGoal);
	void setNamePlan(const string newNamePlan);
	void setDatePlan(const string newDatePlan);

	//the other functions of this class
	void editGoal();

private:

	int steps_Goal;

	string name_Plan;

	string date_Plan;
};

ostream& operator<<(ostream& lhs, const ExercisePlan& rhs);

ifstream& operator>>(ifstream& lhs, ExercisePlan& rhs);