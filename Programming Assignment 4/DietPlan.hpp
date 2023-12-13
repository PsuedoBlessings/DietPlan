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

class DietPlan
{
public:

	//constructor with the default value 
	DietPlan(const int newCaloriesGoal = 2000, const string newNamePlan = "Diet Plan", const string newDatePlan = "01/01/20XX");
	//the copy constructor
	DietPlan(const DietPlan& copy);
	// the deconstrutor of this class
	~DietPlan();

	
	// the getters
	int getCaloriesGoal() const;
	string getNamePlan() const;
	string getDatePlan() const;

	//the setters
	void setCaloriesGoal(const int newCaloriesGoal);
	void setNamePlan(const string newNamePlan);
	void setDatePlan(const string newDatePlan);

	// the other functions of this class
	void editGoal();

private:

	int calories_Goal;
	
	string name_Plan;

	string date_Plan;
};

ostream& operator<<(ostream& lhs, const DietPlan& rhs);

ifstream& operator>>(ifstream& lhs, DietPlan& rhs);
