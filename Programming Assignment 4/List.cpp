#include "List.hpp"

List::List(Node* newpHead, Node* newpCur)
{
	this->pHead = newpHead;
	this->pCur = newpCur;
}

List::List(List& copy)
{
	setpCur(copy.getpCur());
	setpHead(copy.getpHead());
}

List::~List()
{
}

void List::setpCur(Node* newpCur)
{
	this->pCur = newpCur;
}

void List::setpHead(Node* newpHead)
{
	this->pHead = newpHead;
}

Node* List::getpCur()
{
	return this->pCur;
}

Node* List::getpHead()
{
	return this->pHead;
}

bool List::insertFront(DietPlan dietPlan)
{
	Node* pMem = new Node(dietPlan);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;

		if (isEmpty())
		{
			this->pHead = pMem;
		}
		else
		{
			Node* pTemp = this->pHead;
			this->pHead->setpNext(pMem);
			this->pHead = pMem;
			this->pHead->setpPrev(pTemp);
		}

	}

	return success;
}

bool List::insertFront(ExercisePlan exercisePlan)
{
	Node* pMem = new Node(exercisePlan);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;

		if (isEmpty())
		{
			this->pHead = pMem;
		}
		else
		{
			Node* pTemp = this->pHead;
			this->pHead->setpNext(pMem);
			this->pHead = pMem;
			this->pHead->setpPrev(pTemp);
		}

	}

	return success;
}

bool List::isEmpty()
{
	return this->pHead == nullptr;
}

void List::deleteNode()
{
	Node* pTemp = this->pHead;

	this->pHead = this->pHead->getpPrev();
	this->pHead->setpNext(nullptr);

	delete pTemp;
}

Node* List::searchPlanNode(string planName)
{
	this->pCur = this->pHead;
	Node* pCur = this->pCur;

	while (pCur != nullptr)
	{
		DietPlan dp = pCur->getDietPlan();
		ExercisePlan ep = pCur->getExercisePlan();

		if (planName == ep.getNamePlan())
		{
			return pCur;
		}

		if (planName == dp.getNamePlan())
		{
			return pCur;
		}

		else
		{
			pCur = pCur->getpPrev();
		}
	}
	return nullptr;
}