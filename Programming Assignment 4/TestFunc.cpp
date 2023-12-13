#include "TestFunc.hpp"

void Test_Weekly_Load()
{
	ifstream it("InputTest.txt", std::ios_base::in);
	
	DietPlan dp;

	List weeklyDietPlan;

	List weeklyExercisePlan;

	if (it.is_open())
	{
		FitnessAppWrapper app(weeklyDietPlan, weeklyDietPlan);

		app.loadWeeklyPlan(it, dp);

		app.displayWeeklyPlan(dp);
	}

	else
	{
		cout << "file didn't open" << endl;
	}

						/******Expected Result*****/
/*
			Terminal
	Help
	1500
	07/11/2045

	How
	1200
	06/29/4021
*/
}

void Test_Weekly_Store()
{
	std::ofstream ot("OutputTest.txt", std::ios_base::out);

	ifstream it("InputTest.txt", std::ios_base::in);

	DietPlan dp;

	List weeklyDietPlan;

	List weeklyExercisePlan;

	if (it.is_open() && ot.is_open())
	{
		FitnessAppWrapper app(weeklyDietPlan, weeklyExercisePlan);

		app.loadWeeklyPlan(it, dp);

		app.displayWeeklyPlan(dp);

		app.storeWeeklyPlan(ot, dp);
	}

	else
	{
		cout << "file didn't open" << endl;
	}

									/******Expected Result*****/
	/*			OutputText.txt
		Help
		1500
		07/11/2045

		How
		1200
		06/29/4021
	
				Terminal
		Help
		1500
		07/11/2045

		How
		1200
		06/29/4021
	*/
}

void Test_Weekly_Edit()
{
	ifstream it("InputTest.txt", std::ios_base::in);

	DietPlan dp;

	List weeklyDietPlan;

	List weeklyExercisePlan;

	if (it.is_open())
	{
		FitnessAppWrapper app(weeklyDietPlan, weeklyDietPlan);

		app.loadWeeklyPlan(it, dp);

		app.EditDailyPlan(dp);
	}

	else
	{
		cout << "file didn't open" << endl;
	}

	/******Expected Result*****/
/*
			Terminal
	Help
	1500
	07/11/2045

	How
	1200
	06/29/4021
*/
}