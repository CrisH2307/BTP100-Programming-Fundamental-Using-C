/*
*****************************************************************************
					Workshop - #8 (P1)
Full Name : Xuan Khang Huynh(Cris Huynh)
Student ID# : 10544428
Email : xhuynh@myseneca.ca
Section : BTP100 NCC
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************
*/
// System Libraries


// User Libraries


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)


// 3. Opening Message (include the number of products that need entering)


// 4. Get user input for the details of cat food product


// 5. Display the formatted table header

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int* number)
{
	int IntPositive;

	do {
		scanf("%d", &IntPositive);

		if (IntPositive <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (IntPositive <= 0);

	if (number != NULL)
		*number = IntPositive;

	return IntPositive;
}

double getDoublePositive(double* number)
{
	double DoublePositive;

	do {
		scanf("%lf", &DoublePositive);

		if (DoublePositive <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (DoublePositive <= 0);

	if (number != NULL)
		*number = DoublePositive;
	return DoublePositive;
}

void openingMessage(const int number)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", number);
	printf("NOTE: A 'serving' is %dg\n", WEIGHT_SERVING);
	return;
}

struct TomandJerryInfo getCatFoodInfo(const int n)
{
	struct TomandJerryInfo Food;

	printf("\n");
	printf("Cat Food Product #%d\n", n + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&Food.SKU);
	printf("PRICE         : $");
	getDoublePositive(&Food.Price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&Food.Kg);
	printf("CALORIES/SERV.: ");
	getIntPositive(&Food.Calo);

	return Food;
}

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int SKU, double* Price, int Calo, double* Kg)
{
	printf("%07d %10.2lf %10.1lf %8d\n", SKU, *Price, *Kg, Calo);
	return;
}

void start()
{
	struct TomandJerryInfo Food[CAT_FOOD_PRODUCT] = { {0} };

	int FoodProduct = 3;
	int i; 
	openingMessage(FoodProduct);

	for (i = 0; i < FoodProduct; i++)
		Food[i] = getCatFoodInfo(i);

	printf("\n");

	displayCatFoodHeader();

	for (i = 0; i < FoodProduct; i++)
		displayCatFoodData(Food[i].SKU, &Food[i].Price, Food[i].Calo, &Food[i].Kg);

	return;
}

// 6. Display a formatted record of cat food data

// 7. Logic entry point
