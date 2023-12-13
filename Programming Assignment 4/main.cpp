/*******************************************************************************
 * Programmer: Zvikomborero Masike                                             *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 4                                                   *
 * Date: 2/16/2022                                                             *
 *                                                                             *
 * Description: This programs makes goals for both diets and excersice and     *
 * stores them within a file to be accessed later.                             *
 *                                                                             *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record input & output file (dietPlans.txt & exercisePlans.txt):   *
 *                     Plan Name (name_Plan string)                            *
 *					   Goal (calories_Goal int steps_Goal int)                 *
 *					   mm/dd/yyyy (date_Plan string)						   *
 *                                                                             *
 * Revision History:														   *
 * 2/17/2022 -  I've added the functions getters and setters of the class      *
 * ExercisePlan. I've also added the constuctor and deconstructor of the same  *
 * class                                                                       *
 * 2/18/2022 -	I've implemented the setters within the classes ExercisePlan   *
 * and Diet plan. I've also implemented the deconstuctors and copy constructors*
 * 2/19/2022 -                                                                 *
 ******************************************************************************/

// headers of all the relavent classes
#include "TestFunc.hpp"
#include "FitnessAppWrapper.hpp"

int main(void)
{
	/*
	Test Functions:
	
	Test_Weekly_Load();

	Test_Weekly_Store()
	
	Test_Weekly_Edit();
	*/
	
	List weeklyDietPlan;

	List weeklyExercisePlan;


	FitnessAppWrapper app (weeklyDietPlan, weeklyExercisePlan);
	app.runApp();

	return 0;
}
