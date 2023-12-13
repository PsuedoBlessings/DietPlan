#pragma once
#include <iostream>
#include <fstream>

#include"List.hpp"

class FitnessAppWrapper
{
public:

	FitnessAppWrapper(List weeklyDietPlan, List weeklyExercisePlan);

	~FitnessAppWrapper();

	void runApp();
	

	void loadDailyPlan(ifstream& fileStream, DietPlan& plan);
	void loadDailyPlan(ifstream& fileStream, ExercisePlan& plan);

	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	void storeDailyPlan(ostream& fileStream, DietPlan& plan);
	void storeDailyPlan(ostream& fileStream, ExercisePlan& plan);

	void EditDailyPlan(DietPlan& plan);
	void EditDailyPlan(ExercisePlan& plan);

	void addDailyPlan(ExercisePlan& plan);
	void addDailyPlan(DietPlan& plan);

	void loadWeeklyPlan(ifstream& fileStream, DietPlan& plan);
	void loadWeeklyPlan(ifstream& fileStream, ExercisePlan& plan);

	void displayWeeklyPlan(DietPlan& plan);
	void displayWeeklyPlan(ExercisePlan& plan);

	void storeWeeklyPlan(ostream& fileStream, DietPlan& plan);
	void storeWeeklyPlan(ostream& fileStream, ExercisePlan& plan);

	List getweeklyDietPlan();
	List getweeklyExercisePlan();

	void displayMenu();

private:

	List weeklyDietPlan_;

	List weeklyExercisePlan_;

};

