#pragma once
#include "ListNode.hpp"
#include <iostream>
#include <fstream>

class List
{
public:

	List(Node* newpHead = nullptr, Node* newpCur = nullptr);
	
	List(List& copy);

	~List();
	
	void setpCur(Node* newpCur);

	void setpHead(Node* newpHead);

	Node* getpCur();

	Node* getpHead();
	
	bool insertFront(DietPlan dietPlan);
	bool insertFront(ExercisePlan exercisePlan);
	bool isEmpty();
	void deleteNode();
	Node* searchPlanNode(string planName);

private:
	Node* pHead; //  the adderess of the first node

	Node* pCur; // use this position to find certain elements within the list

};