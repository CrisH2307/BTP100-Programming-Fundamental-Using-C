///*
//*****************************************************************************
//						  Workshop - #6 Part 1
//Full Name  : Xuan Khang Huynh
//Student ID#: 105444228
//Email      : khangpicasso@gmail.com
//Section    : BTP100
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.
//*****************************************************************************
//*/

#define _CRT_SECURE_NO_WARNINGS
#define ITEMS 
#define MAX_ITEMS 10
#define MIN_ITEMS 3
#define NET_INCOME_MIN 500.00
#define NET_INCOME_MAX 40000.00
#define ITEM_FORCAST_MAX 10
#define ITEM_FORCAST_MIN 1
#include <stdio.h>

int main(void)
{
    double NetIncome;
    double Total = 0;
    double ItemCost[MAX_ITEMS] = { 0 };
    int Forecast;
    int i;
    int Important[MAX_ITEMS] = { 0 };
    char Financing[MAX_ITEMS] = { 0 };

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &NetIncome);

        if (NetIncome < NET_INCOME_MIN)
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");

        if (NetIncome > NET_INCOME_MAX)
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");

    } while (NetIncome < NET_INCOME_MIN || NetIncome > NET_INCOME_MAX);

    printf("\n");

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &Forecast);

        if (Forecast < MIN_ITEMS || Forecast > MAX_ITEMS)
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");

    } while (Forecast < 1 || Forecast > MAX_ITEMS);

    printf("\n");

    for (i = 0; i < Forecast; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf("%lf", &ItemCost[i]);

            if (ItemCost[i] < 100.00)
                printf("      ERROR: Cost must be at least $100.00\n");

        } while (ItemCost[i] < 100.00);

        Total += ItemCost[i];

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &Important[i]);
            if (Important[i] < 1 || Important[i] > 3)

                printf("      ERROR: Value must be between 1 and 3\n");

        } while (Important[i] < 1 || Important[i] > 3);

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &Financing[i]);

            if (Financing[i] != 'y' && Financing[i] != 'n')

                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");

        } while (Financing[i] != 'y' && Financing[i] != 'n');

        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < Forecast; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, Important[i], Financing[i], ItemCost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", Total);
    printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}