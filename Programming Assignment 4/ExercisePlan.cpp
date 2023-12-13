#include "ExercisePlan.hpp"

/*************************************************************
 * Function: ExercisePlan::ExercisePlan ()                   *
 * Date Created: 2/17/2022                                   *
 * Date Last Modified:                                       *
 * Description: This is the constructor for the ExercisePlan *
 * class, so it will make an object with default values      *
 * (refer the class for default values) if none are applied. *
 * Input parameters: const int newStepsGoal,                 *
 * const string newNamePlan, const string newDatePlan        *
 * Returns: Nothing                                          *
 * Preconditions: it requires all the variables to be a      *
 * constant                                                  *
 * Postconditions: It will create an object                  *
 *************************************************************/

ExercisePlan::ExercisePlan(const int newStepsGoal, const string newNamePlan, const string newDatePlan)
{
	this->steps_Goal = newStepsGoal;

	this->name_Plan = newNamePlan;

	this->date_Plan = newDatePlan;
}

ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	//copies the value of copy to whatever object called this function

	this->steps_Goal = copy.steps_Goal;

	this->name_Plan = copy.name_Plan;

	this->date_Plan = copy.date_Plan;
}

ExercisePlan::~ExercisePlan()
{
}

/*************************************************************
 * Function: int ExercisePlan::getStepsGoals() const         *
 * Date Created: 2/17/2022                                   *
 * Date Last Modified:                                       *
 * Description: it will get the integer value within the     *
 * object.                                                   *
 * Input parameters: Nothing                                 *
 * Returns: int this->steps_Goal                             *
 * Preconditions: Any functions that uses this function must *
 * have the parameter of const int.                          *
 * Postconditions: gets the vaule of steps_Goal within the   *
 * object.													 *
 *************************************************************/

int ExercisePlan::getStepsGoals() const
{
	return this->steps_Goal;
}

/*************************************************************
 * Function: int ExercisePlan::getNamePlan() const           *
 * Date Created: 2/17/2022                                   *
 * Date Last Modified:                                       *
 * Description: it will get the string within the            *
 * object                                                    *
 * Input parameters: Nothing                                 *
 * Returns: string this->name_Plan                           *
 * Preconditions: Any functions that uses this function must *
 * have the parameter of const string                        *
 * Postconditions: gets the string of name_Plan within the   *
 * object.													 *
 *************************************************************/

string ExercisePlan::getNamePlan() const
{
	return this->name_Plan;
}

/*************************************************************
 * Function: int ExercisePlan::getDatePlan() const           *
 * Date Created: 2/17/2022                                   *
 * Date Last Modified:                                       *
 * Description: it will get the string within the            *
 * object                                                    *
 * Input parameters: Nothing                                 *
 * Returns: string this->date_Plan                           *
 * Preconditions: Any functions that uses this function must *
 * have the parameter of const string                        *
 * Postconditions: gets the string of date_Plan within the   *
 * object.													 *
 *************************************************************/

string ExercisePlan::getDatePlan() const
{
	return this->date_Plan;
}

/*************************************************************
 * Function: ExercisePlan::setStepsGoals ()                  *
 * Date Created: 2/18/2022                                   *
 * Date Last Modified:                                       *
 * Description: Accepts an integer that will be set as       *
 * steps_Goal                                                *
 * Input parameters: const int newStepGoal                   *
 * Returns: Nothing                                          *
 * Preconditions: An integer that must be a constant.        *
 * Postconditions: The objects value, steps_Goal, will be set*
 * to whatever the value newStepGoal is.                     *
 *************************************************************/

void ExercisePlan::setStepsGoals(const int newStepGoal)
{
	this->steps_Goal = newStepGoal;
}

/*************************************************************
 * Function: ExercisePlan::setNamePlan ()                    *
 * Date Created: 2/18/2022                                   *
 * Date Last Modified:                                       *
 * Description: Accepts an string that will be set as        *
 * name_Plan                                                 *
 * Input parameters: const string newNamePlan                *
 * Returns: Nothing                                          *
 * Preconditions: An string that must be a constant.         *
 * Postconditions: The objects string, name_Plan, will be    *
 * set to whatever the string newNamePlan is.                *
 *************************************************************/

void ExercisePlan::setNamePlan(const string newNamePlan)
{
	this->name_Plan = newNamePlan;
}

/*************************************************************
 * Function: ExercisePlan::setDatePlan ()                    *
 * Date Created: 2/18/2022                                   *
 * Date Last Modified:                                       *
 * Description: Accepts an string that will be set as        *
 * date_Plan                                                 *
 * Input parameters: const string newDatePlan                *
 * Returns: Nothing                                          *
 * Preconditions: An string that must be a constant.         *
 * Postconditions: The objects string, date_Plan, will be    *
 * set to whatever the string newDatePlan is.                *
 *************************************************************/

void ExercisePlan::setDatePlan(const string newDatePlan)
{
	this->date_Plan = newDatePlan;
}

ostream& operator<<(ostream& lhs, const ExercisePlan& rhs)
{

	lhs << rhs.getNamePlan() << endl;
	
	lhs << rhs.getStepsGoals() << endl;

	lhs << rhs.getDatePlan() << endl << endl;

	return lhs;
}

ifstream& operator>>(ifstream& lhs, ExercisePlan& rhs)
{
	int steps_goals = 0;
	string date = "\0", name = "\0";

	lhs >> name;
	if (name == "\0")
	{
		lhs >> name;
	}
	rhs.setNamePlan(name);
	lhs >> steps_goals;
	rhs.setStepsGoals(steps_goals);
	lhs >> date;
	rhs.setDatePlan(date);


	return lhs;
}

void ExercisePlan::editGoal()
{
	int steps_goals = 0;
	string date = "\0", name = "\0";;

	cout << "Calories Planned To Burn:  ";
	cin >> steps_goals;
	this->steps_Goal = steps_goals;
	cout << "How Long do you plan to have this diet (01/01/20XX): ";
	cin >> date;
	this->date_Plan = date;
	cout << "What is the name of this diet: ";
	cin >> name;
	this->name_Plan = name;
}

