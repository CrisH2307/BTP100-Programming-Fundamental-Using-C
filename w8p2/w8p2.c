/*
*****************************************************************************
						  Workshop - #8 (P2)
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Section    : BTP100 NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


// System Libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"


// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* OhHell)
{
	
	int IntPositive;
	int SilverFlag = 0;

	do {
		scanf("%d", &IntPositive);

		if (IntPositive <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			SilverFlag = 1;
		}

		else
		{
			SilverFlag = 0;
			if (OhHell != NULL) 
				*OhHell = IntPositive;
			OhHell = &IntPositive;
		}

	} while (SilverFlag != 0);

	return IntPositive;
/*
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
	*/
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* OhGod)
{
	double DoublePositive;
	int PurpleFlag = 0;

	do {
		scanf("%lf", &DoublePositive);
		if (DoublePositive <= 0)
		{
			printf("ERROR: Enter a positive value: ");
			PurpleFlag = 1;
		}
		else
		{
			PurpleFlag = 0;
			if (OhGod) *OhGod = DoublePositive;
			OhGod = &DoublePositive;
		}
	} while (PurpleFlag != 0);

	return DoublePositive;

	/*
	Double DoublePositive;

	do {
		scanf("%lf", &DoublePositive);

		if (DoublePositive <= 0)
			printf("ERROR: Enter a positive value: ");
	} while (DoublePositive <= 0);

	if (number != NULL)
		*number = DoublePositive;
	return DoublePositive;
	*/
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int Product, const int Serving)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", Product);
	printf("NOTE: A 'serving' is %dg\n", Serving);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int CatFoodProduct)
{
	struct CatFoodInfo Food;
	printf("SKU           : ");
	getIntPositive(&Food.SKU);
	printf("PRICE         : $");
	getDoublePositive(&Food.Price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&Food.LBS);
	printf("CALORIES/SERV.: ");
	getIntPositive(&Food.Calo);
	return Food;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int SKU, const double Price, const double LBS, const int Calo) 
{
	printf("%07d %10.2lf %10.1lf %8d\n", SKU, Price, LBS, Calo);
}



// ----------------------------------------------------------------------------
// PART-2



// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* YellowFlag, double* BlueFlag)
{
	double x, y;

	x = *YellowFlag;
	y = x / LBS_KG;
	YellowFlag = &x;

	if (BlueFlag) *BlueFlag = y;
	BlueFlag = &y;

	return y;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* RedLight, int* GreenLight)
{
	double x;
	int y;

	x = *RedLight;
	y = (int)(x / LBS_KG * 1000);
	RedLight = &x;

	if (GreenLight) *GreenLight = y;
	GreenLight = &y;

	return y;
}


// 10. convert lbs: kg and g
void convertLbs(const double* Line1, double* Line2, int* Line3)
{
	double y;
	int z;

	y = convertLbsKg(Line1, Line2);
	if (Line2) *Line2 = y;
	Line2 = &y;

	z = convertLbsG(Line1, Line3);
	if (Line3) *Line3 = z;
	Line3 = &z;
	return;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int ServingSize, const int TotalGrams, double* NumServings)
{
	double z;

	z = (float)TotalGrams / (float)ServingSize;
	NumServings = &z;
	if (NumServings) *NumServings = z;

	return z;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* prodPrice, const double* noOfServing, double* costPerServing)
{
	double x, y, z;

	x = *prodPrice;
	y = *noOfServing;
	z = x / y;
	costPerServing = &z;

	if (costPerServing) *costPerServing = z;

	return z;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* ProductPrice, const double* Calories, double* CostPerCalories)
{
	double x, y, z;

	x = *ProductPrice;
	y = *Calories;
	z = x / y;
	CostPerCalories = &z;

	if (CostPerCalories) *CostPerCalories = z;

	return z;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo FoodII)
{
	double PKg = 0.0;
	double Total = 0.0;
	double Cost = 0.0;
	double CaloPerSer = 0.0;
	double Calculation; 
	int PG = 0;

	struct ReportData Report;
	Report.SKU = FoodII.SKU;
	Report.Price = FoodII.Price;
	Report.Calo = FoodII.Calo;
	Report.LBS = FoodII.LBS;
	Report.ProductKg = convertLbsKg(&FoodII.LBS, &PKg);
	Report.ProductG = convertLbsG(&FoodII.LBS, &PG);
	Report.TotalServings = calculateServings(GRAM_SERVING, Report.ProductG, &Total);
	Report.CostPerServing = calculateCostPerServing(&Report.Price, &Report.TotalServings, &Cost);

	// This is the calculation of the Total calories on the serving
	Calculation = (Report.TotalServings * Report.Calo);


	Report.CostCaloriesPerServing = calculateCostPerCal(&Report.Price, &Calculation, &CaloPerSer);

	return Report;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAM_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Report, const int Cheapest)
{
	struct ReportData ReportII;
	ReportII.SKU = Report.SKU;
	ReportII.Price = Report.Price;
	ReportII.Calo = Report.Calo;
	ReportII.LBS = Report.LBS;
	ReportII.ProductKg = Report.ProductKg;
	ReportII.ProductG = Report.ProductG;
	ReportII.TotalServings = Report.TotalServings;
	ReportII.CostPerServing = Report.CostPerServing;
	ReportII.CostCaloriesPerServing = Report.CostCaloriesPerServing;

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", ReportII.SKU, ReportII.Price, ReportII.LBS, ReportII.ProductKg, ReportII.ProductG, ReportII.Calo, ReportII.TotalServings, ReportII.CostPerServing, ReportII.CostCaloriesPerServing);

	if (Cheapest == 1)
	{
		printf(" ***");
	}
	printf("\n");
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo FoodII)
{
	struct CatFoodInfo FoodIII;
	FoodIII.SKU = FoodII.SKU;
	FoodIII.Price = FoodII.Price;
	printf("\nFinal Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\nHappy shopping!\n", FoodIII.SKU, FoodIII.Price);
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start() 
{
	struct CatFoodInfo FoodII[MAX_PRODUCT];
	struct ReportData ReportII[MAX_PRODUCT];

	openingMessage(MAX_PRODUCT, GRAM_SERVING);

	int i;
	int Cheapest[MAX_PRODUCT] = { 0 };
	int l = 0;

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		printf("\nCat Food Product #%d\n", (i + 1));
		printf("--------------------\n");
		FoodII[i] = getCatFoodInfo(1);
	}
	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayCatFoodData(FoodII[i].SKU, FoodII[i].Price, FoodII[i].LBS, FoodII[i].Calo);
	}

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		ReportII[i] = calculateReportData(FoodII[i]);
		int GoldFlag;
		for (GoldFlag = 1; GoldFlag < MAX_PRODUCT; GoldFlag++)
		{
			if (ReportII[GoldFlag].CostCaloriesPerServing < ReportII[l].CostCaloriesPerServing)
			{
				l = GoldFlag;
				Cheapest[GoldFlag] = 1;
			}

			else {
				Cheapest[GoldFlag] = 0;
				Cheapest[l] = 1;
			}
		}

	}
	displayReportHeader();

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayReportData(ReportII[i], Cheapest[i]);

	}
	displayFinalAnalysis(FoodII[l]);

}