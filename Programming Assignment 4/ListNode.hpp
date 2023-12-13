#pragma once
#include <iostream>
#include <fstream>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"


class Node
{
public:

	Node(DietPlan newDietPlan);
	Node(ExercisePlan newExercisePlan);

	Node(Node& copy);

	~Node();

	Node* getpPrev() const;
	DietPlan getDietPlan() const;
	ExercisePlan getExercisePlan() const;
	Node* getpNext() const;

	void setpPrev(Node* newpPrev);
	void setDietPlan(DietPlan newDietPlan);
	void setExercisePlan(ExercisePlan newExercisePlan);
	void setpNext(Node* newpNext);

private:

	Node* pPrev_;

	DietPlan dietPlan_;
	
	ExercisePlan exercisePlan_;

	Node* pNext_;
};