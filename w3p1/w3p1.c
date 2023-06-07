/*
	****************************************************************************
	< assessment name example : Workshop - #3 (Part - 1) >
	Full Name : Xuan Khang Huynh
	Student ID# : 105444228
	Email : xhuynh@myseneca.ca
	Section : BTP 100 NCC
	Authenticity Declaration :
	I declare this submission is the result of my own work and has not been
	shared with any other student or 3rd party content provider.This submitted
	piece of work is entirely of my own creation.
	* ****************************************************************************\n");

*/

#include <stdio.h>

	int main(void)
	{
		// You must use this variable in #3 data analysis section!
		const double TestValue = 330.99;
		const int Product1ID = 111;
		const int Product2ID = 222;
		const int Product3ID = 111;
		const double Product1Price = 111.49;
		const double Product2Price = 222.99;
		const double Product3Price = 334.49;
		const char Product1Taxed = 'Y';
		const char Product2Taxed = 'N';
		const char Product3Taxed = 'N';
		const double AveragePrice = (double)((int)(((Product1Price + Product2Price + Product3Price) / 3) * 100 + 0.5)) / 100;

		printf("Product Information\n");
		printf("===================\n");
		printf("Product-1 (ID:%d)\n", Product1ID);
		printf("  Taxed: %c\n", Product1Taxed);
		printf("  Price: $%.4lf\n\n", Product1Price);
		printf("Product-2 (ID:%d)\n", Product2ID);
		printf("  Taxed: %c\n", Product2Taxed);
		printf("  Price: $%.4lf\n\n", Product2Price);
		printf("Product-3 (ID:%d)\n", Product3ID);
		printf("  Taxed: %c\n", Product3Taxed);
		printf("  Price: $%.4lf\n\n", Product3Price);
		printf("The average of all prices is: $%.4lf\n\n", AveragePrice);

		printf("About Relational and Logical Expressions!\n");
		printf("========================================\n");
		printf("1. These expressions evaluate to TRUE or FALSE\n");
		printf("2. FALSE: is always represented by integer value 0\n");
		printf("3. TRUE : is represented by any integer value other than 0\n\n");
		printf("Some Data Analysis...\n");
		printf("=====================\n");
		printf("1. Is product 1 taxable? -> %d\n\n", Product1Taxed == 'Y');
		printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n",(Product2Taxed == 'n' || Product2Taxed == 'N') && (Product3Taxed == 'n' || Product3Taxed == 'N'));
		printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", TestValue, Product3Price < TestValue );
		printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", Product3Price > (Product1Price + Product2Price));
		printf("5. Is the price of product 1 equal to or more than the price difference\n");
		printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", Product1Price >= Product3Price - Product2Price, Product3Price - Product2Price);
		printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", Product2Price >= AveragePrice);
		printf("7. Based on product ID, product 1 is unique -> %d\n\n", Product1ID != Product2ID && Product1ID != Product3ID);
		printf("8. Based on product ID, product 2 is unique -> %d\n\n", Product2ID != Product1ID && Product2ID != Product3ID);
		printf("9. Based on product ID, product 3 is unique -> %d\n\n", Product3ID != Product1ID && Product3ID != Product2ID);

		return 0;
	}
