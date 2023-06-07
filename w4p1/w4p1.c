/*
    ****************************************************************************
    < assessment name example : Workshop - #4 (Part - 1) >
    Full Name : Xuan Khang Huynh (Cris)
    Student ID# : 105444228
    Email : xhuynh@myseneca.ca
    Section : BTP 100 NCC
    Authenticity Declaration :
    I declare this submission is the result of my own work and has not been
    shared with any other student or 3rd party content provider.This submitted
    piece of work is entirely of my own creation.
    * ****************************************************************************\n");

*/



#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int main(void)
{
	int times;
	int i = 1;
	char loopchar;

	printf("+----------------------+\n");
	printf("Loop application STARTED\n");
	printf("+----------------------+\n\n");

	// Loops
	do
	{
		printf("D = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &loopchar, &times);
		if ((loopchar == 'D' || loopchar == 'W' || loopchar == 'F') && (times >= 3 && times <= 20))
		{
			switch (loopchar)
			{
			case 'D':

				printf("DO-WHILE: ");

				do 
				{
					times--;

					printf("D");

				} 
				while (times > 0);

				printf("\n\n");

				break;

			case 'W':
				printf("WHILE   : ");
				while (times > 0)

				{
					times--;

					printf("W");
				}

				printf("\n\n");
				break;

			default:
				printf("FOR     : ");
				for (times = times; times > 0; times--)

				{

					printf("F");

				}

				printf("\n\n");
				break;

			}
		}

		else if (loopchar == 'Q')
		{

			if (times == 0)

			{

				i = times;
				printf("\n+--------------------+\n");
				printf("Loop application ENDED\n");
				printf("+--------------------+\n");

			}

			else

			{
				printf("ERROR: To quit, the number of iterations should be 0!\n\n");
			}
		}
		// ERRORS
		else if ((loopchar != 'D' && loopchar != 'W' && loopchar != 'F' && loopchar != 'Q') || (times < 3 || times > 20))

		{

			if ((loopchar != 'D' && loopchar != 'W' && loopchar != 'F' && loopchar != 'Q') && (times < 3 || times > 20))

			{
				printf("ERROR: Invalid entered value(s)!\n\n");
			}

			else if ((times < 3 || times > 20))

			{
				printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
			}

			else

			{
				printf("ERROR: Invalid entered value(s)!\n\n");
			}
		}

	} while (i);
	return 0;
	// end the program
}