/*
	****************************************************************************
	< assessment name example : Workshop - #2 (Part - 1) >
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
int main()
{

	const double Tax = 0.13;

	double SsizePrice = 0.0;
	double MsizePrice = 0.0;
	double LsizePrice = 0.0;

	int numberofShirt = 0;

	printf("Set Shirt Prices\n");
	printf("================\n");

	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &SsizePrice);

	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &MsizePrice);

	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &LsizePrice);

	printf("\nShirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2lf\n", SsizePrice);
	printf("MEDIUM : $%.2lf\n", MsizePrice);
	printf("LARGE  : $%.2lf\n", LsizePrice);

	printf("\nPatty's shirt size is 'S'\n");
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &numberofShirt);

	// calculation
	double subTotal = ((int)(numberofShirt * SsizePrice * 100 + 0.5)) / 100.0;
	double Taxes = ((int)(Tax * subTotal * 100 + 0.5)) / 100.0;
	double Total = ((int)((subTotal + Taxes) * 100 + 0.5))/ 100.0;

	printf("\nPatty's shopping cart...\n");
	printf("Contains : %d shirts\n", numberofShirt);
	printf("Sub-total: $%8.4f\n", subTotal);
	printf("Taxes    : $%8.4lf\n", Taxes);
	printf("Total    : $%8.4lf\n", Total);

	return 0;


}