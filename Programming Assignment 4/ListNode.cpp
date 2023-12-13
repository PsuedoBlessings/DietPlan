#include "ListNode.hpp"

Node::Node(DietPlan newDietPlan)
{
	this->dietPlan_ = newDietPlan;
	this->pNext_ = nullptr;
	this->pPrev_ = nullptr;
}

Node::Node(ExercisePlan newExercisePlan)
{
	this->exercisePlan_ = newExercisePlan;
	this->pNext_ = nullptr;
	this->pPrev_ = nullptr;
}

Node::Node(Node& copy)
{
	setpPrev(copy.getpPrev());
	setDietPlan(copy.getDietPlan());
	setExercisePlan(copy.getExercisePlan());
	setpPrev(copy.getpNext());
}

Node::~Node()
{
}

Node* Node::getpPrev() const
{
	return this->pPrev_;
}

DietPlan Node::getDietPlan() const
{
	return this->dietPlan_;
}

ExercisePlan Node::getExercisePlan() const
{
	return this->exercisePlan_;
}

Node* Node::getpNext() const
{
	return this->pNext_;
}

void Node::setpPrev(Node* newpPrev)
{
	this->pPrev_ = newpPrev;
}

void Node::setDietPlan(DietPlan newDietPlan)
{
	this->dietPlan_ = newDietPlan;
}

void Node::setExercisePlan(ExercisePlan newExercisePlan)
{
	this->exercisePlan_ = newExercisePlan;
}

void Node::setpNext(Node* newpNext)
{
	this->pNext_ = newpNext;
}