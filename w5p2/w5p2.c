/*
*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Xuan Khang Huynh
Student ID#: 105444228
Email      : khangpicasso@gmail.com
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
#define LOG_DAYS 3

int main(void)
{
	int i = 0;
	int Year = 0;
	int Month;
	int JAN = 1;
	int DEC = 12;
	double Morningrating = 0.0;
	double Eveningrating = 0.0;
	double AverageMorning = 0.0;
	double AverageEvening = 0.0;
	double OverallTotal = 0.0;
	double AverageTotal = 0.0;
	double MorningTotal = 0.0;
	double EveningTotal = 0.0;

	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &Year, &Month);

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

	for (i = 1; i <= LOG_DAYS; i++) {
		printf("%d-FEB-%02d\n", Year, i);
		do {
			printf("   Morning rating (0.0-5.0): ");
			scanf(" %lf", &Morningrating);
			if ((Morningrating < 0.0) || (Morningrating > 5.0))
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
			else
			{
				MorningTotal += Morningrating;
			}
		} while ((Morningrating < 0.0) || (Morningrating > 5.0));
		do
		{
			printf("   Evening rating (0.0-5.0): ");
			scanf(" %lf", &Eveningrating);
			if ((Eveningrating < 0.0) || (Eveningrating > 5.0))
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
			else
			{
				EveningTotal += Eveningrating;
			}
		} while ((Eveningrating < 0.0) || (Eveningrating > 5.0));
		printf("\n");
	}

		OverallTotal = MorningTotal + EveningTotal;
		AverageMorning = MorningTotal / LOG_DAYS;
		AverageEvening = EveningTotal / LOG_DAYS;
		AverageTotal = (AverageMorning + AverageEvening) / 2;
		printf("Summary\n");
		printf("=======\n");
		printf("Morning total rating: %.3lf\n", MorningTotal);
		printf("Evening total rating:  %.3lf\n", EveningTotal);
		printf("----------------------------\n");
		printf("Overall total rating: %.3lf\n\n", OverallTotal);
		printf("Average morning rating:  %.1lf\n", AverageMorning);
		printf("Average evening rating:  %.1lf\n", AverageEvening);
		printf("----------------------------\n");
		printf("Average overall rating:  %.1lf\n", AverageTotal);
    return 0;
}


