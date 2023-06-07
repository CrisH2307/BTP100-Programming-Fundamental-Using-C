/*
*****************************************************************************
						  Workshop - #5 (P1)
Full Name  : Xuan Khang Huynh
Student ID#: 10544228
Email      : xhuynh@myseneca.ca
Section    : BTP100
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)

{
	int Year;
	int Month;
	int JAN = 1;
	int DEC = 12;

	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf(" %d %d", &Year, &Month);

		if ((Year < MIN_YEAR) || (Year > MAX_YEAR))
		{
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");

		}
		if ((Month < JAN) || (Month > DEC))
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
	} while (((Year < MIN_YEAR) || (Year > MAX_YEAR)) || ((Month < JAN) || (Month > DEC)));

	printf("\n*** Log date set! ***\n\n");
	printf("Log starting date: 2022-FEB-01\n");
		
	return 0;
}


/*
int done = 0;
int n = 0;
int i = 0;
int sum = 0;
int numPays = 0;
double pay1 = 0.0;
double pay2 = 0.0;
double pay3 = 0.0;
double pay4 = 0.0;
double paySum = 0.0;
double avgPay = 0.0;

//declare an array
double pay[MAX_PAY] = 0;

do
{
	printf("Enter pay, zero to stop!");
	scanf("%lf", &pay[numPays]);
	if (pay[numPays] != 0.0);
	{
		if (numPays >= MAX_PAYS) printf("Array full\n");
		done = 1;
	}
	else
	{
		paySum += pay[numPays];
		numPays++;

	}
		else
		{
		done = 1;
		}
} while (!done);
avgPay = paySum / numPays;
printf("Average pay is %.2lf\n", avgPay);

for (i = 0, )


printf("Enter pay 1: ");
scanf("%lf", &pay1);
printf("Enter pay 2: ");
scanf("%lf", &pay2);
printf("Enter pay 3: ");
scanf("%lf", &pay3);
printf("Enter pay 4: ");
scanf("%lf", &pay4);

paySum = pay1 + pay2 + pay3 + pay4;

printf("Average pay is %.2lf", paySum / 4.0);


do
{
	printf("Enter a number, zero to stop: \n");
	scanf("%d", &n);
	done = n == o;
	if (!done) sum != 0;
} while (!done);
printf("The sum is %d\n", sum);
return 0;
*/