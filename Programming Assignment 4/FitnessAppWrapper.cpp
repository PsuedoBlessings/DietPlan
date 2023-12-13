#include "FitnessAppWrapper.hpp"

FitnessAppWrapper::FitnessAppWrapper(List weeklyDietPlan, List weeklyExercisePlan)
{
	this->weeklyDietPlan_ = weeklyDietPlan;
	this->weeklyExercisePlan_= weeklyExercisePlan;
}

FitnessAppWrapper::~FitnessAppWrapper()
{

}

void FitnessAppWrapper::runApp()
{
	
	enum Option 
	{LoadDietPlan, LoadExercisePlan, 
	StoreDietPlan, StoreExercisePlan,
	DisplayDietPlan, DisplayExercisePlan,
	EditDietPlan, EditExercisePlan,
	AddDietPlan, AddExercisePlan, 
	Exit};
	
	DietPlan emptydplan;
	ExercisePlan emptyeplan;

	DietPlan newdplan;
	ExercisePlan neweplan;

	int loadedDietPlan = false;
	int loadedExercisePlan = false;
	int option = 0;

	ifstream InputDP;
	ifstream InputEP;

	std::ofstream OutputDP;
	std::ofstream OutputEP;
	
	
	do
	{
		displayMenu();
		cout << "Option: ";
		cin >> option;

		while (option < 1 || option > 11)
		{
			cout << "You've inputed the wrong option, please try again: ";
			cin >> option;
		}

		switch (option -1)
		{
		case LoadDietPlan:
			system("cls");
			InputDP.open("dietPlans.txt", std::ios_base::in);
			loadWeeklyPlan(InputDP, emptydplan);
			loadedDietPlan = true;
			InputDP.close();
			break;
		case LoadExercisePlan:
			system("cls");
			InputEP.open("exercisePlans.txt", std::ios_base::in);
			loadWeeklyPlan(InputEP, emptyeplan);
			loadedExercisePlan = true;
			InputEP.close();
			break;
		case StoreDietPlan:
			if (loadedDietPlan)
			{
				system("cls");
				OutputDP.open("dietPlans.txt", std::ios_base::out);
				storeWeeklyPlan(OutputDP, emptydplan);
				OutputDP.close();
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case StoreExercisePlan:
			if (loadedExercisePlan)
			{
				system("cls");
				OutputEP.open("exercisePlans.txt", std::ios_base::out);
				storeWeeklyPlan(OutputEP, emptyeplan);
				OutputEP.close();
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case DisplayDietPlan:
			if (loadedDietPlan)
			{
				system("cls");
				displayDailyPlan(emptydplan);
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case DisplayExercisePlan:
			if (loadedExercisePlan)
			{
				system("cls");
				displayDailyPlan(emptyeplan);
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case EditDietPlan:
			if (loadedDietPlan)
			{
				system("cls");
				EditDailyPlan(emptydplan);
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case EditExercisePlan:
			if (loadedExercisePlan)
			{
				system("cls");
				EditDailyPlan(emptyeplan);
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case AddDietPlan:
			if (loadedDietPlan)
			{
				system("cls");
				addDailyPlan(newdplan);
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case AddExercisePlan:
			if (loadedExercisePlan)
			{
				system("cls");
				addDailyPlan(neweplan);
			}

			else
			{
				system("cls");
				cout << "you've not loaded the Plans" << endl;
			}
			break;
		case Exit:
			system("cls");
			if (loadedDietPlan)
			{
				OutputDP.open("dietPlans.txt", std::ios_base::out);
				storeWeeklyPlan(OutputDP, emptydplan);
				OutputDP.close();
			}

			if (loadedExercisePlan)
			{
				OutputEP.open("exercisePlans.txt", std::ios_base::out);
				storeWeeklyPlan(OutputEP, emptyeplan);
				OutputEP.close();
			}
			
			return;
		}
	} while (option != 11);
	
	
}


void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
	this->weeklyDietPlan_.insertFront(plan);
}

void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
	this->weeklyExercisePlan_.insertFront(plan);
}


void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{
	if (this->weeklyDietPlan_.getpCur() == nullptr)
	{
		// checks to see if this is the first node and if pCur has been used yet
		Node* pCur = this->weeklyDietPlan_.getpHead();

		cout << pCur->getDietPlan();

		this->weeklyDietPlan_.setpCur(pCur->getpPrev());
	}
	
	else
	{
		Node* pCur = this->weeklyDietPlan_.getpCur();

		cout << pCur->getDietPlan();
		this->weeklyDietPlan_.setpCur(pCur->getpPrev());
	}
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	if (this->weeklyExercisePlan_.getpCur() == nullptr)
	{
		// checks to see if this is the first node and if pCur has been used yet
		Node* pCur = this->weeklyExercisePlan_.getpHead();

		cout << pCur->getExercisePlan();

		this->weeklyExercisePlan_.setpCur(pCur->getpPrev());
	}

	else
	{
		Node* pCur = this->weeklyExercisePlan_.getpCur();

		cout << pCur->getExercisePlan();
		this->weeklyExercisePlan_.setpCur(pCur->getpPrev());
	}

}

void FitnessAppWrapper::storeDailyPlan(ostream& fileStream, DietPlan& plan)
{
	if (this->weeklyDietPlan_.getpCur() == nullptr)
	{
		// checks to see if this is the first node and if pCur has been used yet
		Node* pCur = this->weeklyDietPlan_.getpHead();

		fileStream << pCur->getDietPlan();

		this->weeklyDietPlan_.setpCur(pCur->getpPrev());
	}

	else
	{
		Node* pCur = this->weeklyDietPlan_.getpCur();

		fileStream << pCur->getDietPlan();

		this->weeklyDietPlan_.setpCur(pCur->getpPrev());
	}
}

void FitnessAppWrapper::storeDailyPlan(ostream& fileStream, ExercisePlan& plan)
{
	if (this->weeklyExercisePlan_.getpCur() == nullptr)
	{
		// checks to see if this is the first node and if pCur has been used yet
		Node* pCur = this->weeklyExercisePlan_.getpHead();

		fileStream << pCur->getExercisePlan();

		this->weeklyExercisePlan_.setpCur(pCur->getpPrev());
	}

	else
	{
		Node* pCur = this->weeklyExercisePlan_.getpCur();

		cout << pCur->getExercisePlan();

		this->weeklyExercisePlan_.setpCur(pCur->getpPrev());
	}
}

void FitnessAppWrapper::EditDailyPlan(DietPlan& plan)
{
	if (!this->weeklyDietPlan_.isEmpty())
	{
		string planName;
		cout << "********************************************" << endl;
		displayWeeklyPlan(plan);
		cout << "********************************************" << endl;
		cout << "which Plan do you wish to edit: ";
		cin >> planName;
		Node* Plan = this->weeklyDietPlan_.searchPlanNode(planName);
		if (Plan != nullptr)
		{
			system("cls");
			cout << "Plan Found!" << endl << endl;
			cout << "********************************************" << endl;
			DietPlan dp = Plan->getDietPlan();
			cout << dp;
			cout << "********************************************" << endl;
			enum Option { PlanName, CalorieGoal, Date, AddPlan, Exit };
			int option = 0;
			DietPlan newdp;

			do
			{
				cout << "****Edit Menu****" << endl << endl;
				cout << "1. Plan Name" << endl;
				cout << "2. Calorie Goal" << endl;
				cout << "3. Date" << endl;
				cout << "4. Add Plan" << endl;
				cout << "5. Exit" << endl;
				cin >> option;
				string newPlanName;
				int newCalorieGoal = 0;
				string newDatePlan;

				while (option < 1 || option > 4)
				{
					cout << "You've inputed the wrong option, please try again: ";
					cin >> option;
				}

				switch (option - 1)
				{
				case PlanName:
					system("cls");
					cout << "What would you like to name the Diet Plan: ";
					cin >> newPlanName;
					dp.setNamePlan(newPlanName);
					break;
				case CalorieGoal:
					system("cls");
					cout << "What would you like the calorie goal to be: ";
					cin >> newCalorieGoal;
					dp.setCaloriesGoal(newCalorieGoal);
					break;
				case Date:
					system("cls");
					cout << "What would you like the new date be: ";
					cin >> newDatePlan;
					dp.setDatePlan(newDatePlan);
					break;
				case AddPlan:
					system("cls");
					newdp.editGoal();
					this->weeklyDietPlan_.insertFront(newdp);
					break;
				case Exit:
					system("cls");
					cout << "Leaving Edit Menu...";
					return;
				}
			} while (option - 1 != Exit);

		}

		else
		{
			cout << "Plan was not found! Try again!" << endl;
		}
	}
}

void FitnessAppWrapper::EditDailyPlan(ExercisePlan& plan)
{
	if (!this->weeklyDietPlan_.isEmpty())
	{
		string planName;
		cout << "********************************************" << endl;
		displayWeeklyPlan(plan);
		cout << "********************************************" << endl;
		cout << "which Plan do you wish to edit: ";
		cin >> planName;
		Node* Plan = this->weeklyExercisePlan_.searchPlanNode(planName);
		if (Plan != nullptr)
		{
			system("cls");
			cout << "Plan Found!" << endl << endl;
			cout << "********************************************" << endl;
			ExercisePlan ep = Plan->getExercisePlan();
			cout << ep;
			cout << "********************************************" << endl;
			enum Option { PlanName, ExerciseGoal, Date, AddPlan, Exit };
			int option = 0;
			ExercisePlan newep;

			do
			{
				cout << "****Edit Menu****" << endl << endl;
				cout << "1. Plan Name" << endl;
				cout << "2. Calorie Goal" << endl;
				cout << "3. Date" << endl;
				cout << "4. Add Plan" << endl;
				cout << "5. Exit" << endl;
				cin >> option;
				string newPlanName;
				int newStepGoal = 0;
				string newDatePlan;

				while (option < 1 || option > 4)
				{
					cout << "You've inputed the wrong option, please try again: ";
					cin >> option;
				}

				switch (option - 1)
				{
				case PlanName:
					system("cls");
					cout << "What would you like to name the Exercise Plan: ";
					cin >> newPlanName;
					ep.setNamePlan(newPlanName);
					break;
				case ExerciseGoal:
					system("cls");
					cout << "What would you like the steps goal to be: ";
					cin >> newStepGoal;
					ep.setStepsGoals(newStepGoal);
					break;
				case Date:
					system("cls");
					cout << "What would you like the new date be: ";
					cin >> newDatePlan;
					ep.setDatePlan(newDatePlan);
					break;
				case AddPlan:
					system("cls");
					newep.editGoal();
					this->weeklyExercisePlan_.insertFront(newep);
					break;
				case Exit:
					system("cls");
					cout << "Leaving Edit Menu...";
					return;
				}
			} while (option - 1 != Exit);

		}
	}
}

void FitnessAppWrapper::addDailyPlan(ExercisePlan& plan)
{
	ExercisePlan newep;
	newep.editGoal();
	this->weeklyExercisePlan_.insertFront(newep);
}

void FitnessAppWrapper::addDailyPlan(DietPlan& plan)
{
	DietPlan newdp;
	newdp.editGoal();
	this->weeklyDietPlan_.insertFront(newdp);
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, DietPlan& plan)
{
	while(!fileStream.eof())
	{
		loadDailyPlan(fileStream, plan);
	}
	
}
void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, ExercisePlan& plan)
{
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, plan);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan& plan)
{
	this->weeklyDietPlan_.setpCur(this->weeklyDietPlan_.getpHead());
	while(this->weeklyDietPlan_.getpCur() != nullptr)
	{
		displayDailyPlan(plan);
	}

	this->weeklyDietPlan_.setpCur(nullptr);
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan& plan)
{
	this->weeklyExercisePlan_.setpCur(this->weeklyExercisePlan_.getpHead());
	while (this->weeklyExercisePlan_.getpCur() != nullptr)
	{
		displayDailyPlan(plan);
	}

	this->weeklyExercisePlan_.setpCur(nullptr);
}

void FitnessAppWrapper::storeWeeklyPlan(ostream& fileStream, DietPlan& plan)
{
	this->weeklyDietPlan_.setpCur(this->weeklyDietPlan_.getpHead());
	while (this->weeklyDietPlan_.getpCur() != nullptr)
	{
		storeDailyPlan(fileStream, plan);
	}

	this->weeklyDietPlan_.setpCur(nullptr);
}

void FitnessAppWrapper::storeWeeklyPlan(ostream& fileStream, ExercisePlan& plan)
{
	this->weeklyExercisePlan_.setpCur(this->weeklyExercisePlan_.getpHead());
	while (this->weeklyExercisePlan_.getpCur() != nullptr)
	{
		storeDailyPlan(fileStream, plan);
	}

	this->weeklyExercisePlan_.setpCur(nullptr);
}

List FitnessAppWrapper::getweeklyDietPlan()
{
	return this->weeklyDietPlan_;
}

List FitnessAppWrapper::getweeklyExercisePlan()
{
	return this->weeklyExercisePlan_;
}

void FitnessAppWrapper::displayMenu()
{
	cout << "1.    Load weekly diet plan from file." << endl << "2.    Load weekly exercise plan from file." << endl << "3.    Store weekly diet plan to file." << endl;
	cout << "4.    Store weekly exercise plan to file." << endl << "5.    Display weekly diet plan to screen." << endl << "6.    Display weekly exercise plan to screen." << endl;
	cout << "7.    Edit daily diet plan." << endl << "8.    Edit daily exercise plan." << endl;
	cout << "9.    Add daily diet plan." << endl << "10.   Add daily exercise plan" << endl << "11.   Exit" << endl;
}