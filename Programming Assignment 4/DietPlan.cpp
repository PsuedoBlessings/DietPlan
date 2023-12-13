#include "DietPlan.hpp"

/*************************************************************
 * Function: DietPlan::DietPlan ()                           *
 * Date Created: 2/15/2022                                   *
 * Date Last Modified:                                       *
 * Description: This is the constructor for the DietPlan     *
 * class, so it will make an object with default values      *
 * (refer the class for default values) if none are applied. *
 * Input parameters: const int newCaloriesGoal,              * 
 * const string newNamePlan, const string newDatePlan        *
 * Returns: Nothing                                          *
 * Preconditions: it requires all the variables to be a      *
 * constant                                                  *
 * Postconditions: It will create an object                  *
 *************************************************************/

DietPlan::DietPlan(const int newCaloriesGoal, const string newNamePlan, const string newDatePlan)
{
	this->calories_Goal = newCaloriesGoal;

	this->name_Plan = newNamePlan;

	this->date_Plan = newDatePlan;
}



DietPlan::DietPlan(const DietPlan& copy)
{
	//copies the value of copy to whatever object called this function
	
	this->calories_Goal = copy.calories_Goal;

	this->name_Plan = copy.name_Plan;

	this->date_Plan = copy.date_Plan;
}



DietPlan::~DietPlan()
{

}

/*************************************************************
 * Function: int DietPlan::getCaloriesGoal() const           *
 * Date Created: 2/15/2022                                   *
 * Date Last Modified:                                       *
 * Description: it will get the integer value within the     *
 * object                                                    *
 * Input parameters: Nothing                                 *
 * Returns: int this->calories_goal                          *
 * Preconditions: Any functions that uses this function must *
 * have the parameter of const int                           *
 * Postconditions: gets the vaule of calories_Goal within the*
 * object.													 *
 *************************************************************/

int DietPlan::getCaloriesGoal() const
{
	return this->calories_Goal;
}

/*************************************************************
 * Function: int DietPlan::getNamePlan() const               *
 * Date Created: 2/15/2022                                   *
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

string DietPlan::getNamePlan() const
{
	return this->name_Plan;
}

/*************************************************************
 * Function: int DietPlan::getDatePlan() const               *
 * Date Created: 2/15/2022                                   *
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

string DietPlan::getDatePlan() const
{
	return this->date_Plan;
}

/*************************************************************
 * Function: ExercisePlan::setCaloriesGoal ()                *
 * Date Created: 2/18/2022                                   *
 * Date Last Modified:                                       *
 * Description: Accepts an integer that will be set as       *
 * calories_Goal                                             *
 * Input parameters: const int newCaloriesGoal               *
 * Returns: Nothing                                          *
 * Preconditions: An integer that must be a constant.        *
 * Postconditions: The objects value, calories_Goal, will be *
 * set to whatever the value newCaloriesGoal is.             *
 *************************************************************/

void DietPlan::setCaloriesGoal(const int newCaloriesGoal)
{
	// sets the calories_Goal within the object 
	this->calories_Goal = newCaloriesGoal;
}

/*************************************************************
 * Function: DietPlan::setNamePlan ()                        *
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

void DietPlan::setNamePlan(const string newNamePlan)
{
	// sets the name_Plan within the object 
	this->name_Plan = newNamePlan;
}

/*************************************************************
 * Function: DietPlan::setDatePlan ()                        *
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

void DietPlan::setDatePlan(const string newDatePlan)
{
	// sets the date_Plan within the object 
	this->date_Plan = newDatePlan;
}

ostream& operator<<(ostream& lhs, const DietPlan& rhs)
{

	lhs << rhs.getNamePlan() << endl;

	lhs << rhs.getCaloriesGoal() << endl;

	lhs << rhs.getDatePlan() << endl << endl;

	return lhs;
}

ifstream& operator>>(ifstream& lhs, DietPlan& rhs)
{
	int cal_goals = 0;
	string date = "\0", name = "\0";


	lhs >> name;
	if (name == "\0")
	{
		lhs >> name;
	}
	rhs.setNamePlan(name);
	lhs >> cal_goals;
	rhs.setCaloriesGoal(cal_goals);
	lhs >> date;
	rhs.setDatePlan(date);
	
	

	return lhs;
}

void DietPlan::editGoal()
{
	int cal_goals = 0;
	string date = "\0", name = "\0";

	cout << "How many calories do plan to burn:  ";
	cin >> cal_goals;
	this->calories_Goal = cal_goals;
	cout << "How Long do you plan to have this diet (01/01/20XX): ";
	cin >> date;
	this->date_Plan = date;
	cout << "What is the name of this diet: ";
	cin >> name;
	this->name_Plan = name;
}