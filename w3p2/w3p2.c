/*
    ****************************************************************************
    < assessment name example : Workshop - #3 (Part - 2) >
    Full Name : Xuan Khang Huynh (Cris Huynh)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    /*char coffee1_type, coffee2_type, coffee3_type;
    char coffee1_grindsize, coffee2_grindsize, coffee3_grindsize;
    int coffee1_bagweight, coffee2_bagweight, coffee3_bagweight;
    char coffee1_withcream, coffee2_withcream, coffee3_withcream;
    float coffee1_servetemp, coffee2_servetemp, coffee3_servetemp;
    char coffee_strength;
    char withcream;
    int daily_servings;
    char maker;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\nCOFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffee1_type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffee1_grindsize);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee1_bagweight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1_withcream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &coffee1_servetemp);
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffee2_type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffee2_grindsize);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee2_bagweight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2_withcream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &coffee2_servetemp);
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffee3_type);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffee3_grindsize);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee3_bagweight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3_withcream);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %f", &coffee3_servetemp);
    printf("\n---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", \
        coffee1_type == 'l' || coffee1_type == 'L', coffee1_type == 'b' || coffee1_type == 'B',
        coffee1_grindsize == 'C' || coffee1_grindsize == 'c', coffee1_grindsize == 'F' || coffee1_grindsize == 'f',
        coffee1_bagweight, coffee1_bagweight / GRAMS_IN_LBS,
        coffee1_withcream == 'y' || coffee1_withcream == 'Y',
        coffee1_servetemp, 9 * coffee1_servetemp / 5 + 32);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", \
        coffee2_type == 'l' || coffee2_type == 'L', coffee2_type == 'b' || coffee2_type == 'B',
        coffee2_grindsize == 'C' || coffee2_grindsize == 'c', coffee2_grindsize == 'F' || coffee2_grindsize == 'f',
        coffee2_bagweight, coffee2_bagweight / GRAMS_IN_LBS,
        coffee2_withcream == 'y' || coffee2_withcream == 'Y',
        coffee2_servetemp, 9 * coffee2_servetemp / 5 + 32);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", \
        coffee3_type == 'l' || coffee3_type == 'L', coffee3_type == 'b' || coffee3_type == 'B',
        coffee3_grindsize == 'C' || coffee3_grindsize == 'c', coffee3_grindsize == 'F' || coffee3_grindsize == 'f',
        coffee3_bagweight, coffee3_bagweight / GRAMS_IN_LBS,
        coffee3_withcream == 'y' || coffee3_withcream == 'Y',
        coffee3_servetemp, 9 * coffee3_servetemp / 5 + 32);
    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &withcream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &daily_servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       ");
    if (coffee_strength == 'm' || coffee_strength == 'M')
        printf("%d", coffee1_type == 'l' || coffee1_type == 'L');
    else
        printf("%d", coffee1_type == 'b' || coffee1_type == 'B');
    printf("         |         ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee1_grindsize == 'c' || coffee1_grindsize == 'C');
    else
        printf("%d", coffee1_grindsize == 'f' || coffee1_grindsize == 'F');
    printf("          |      ");
    if (daily_servings >= 1 && daily_servings <= 4)
        printf("%d", coffee1_bagweight <= 250 && coffee1_bagweight >= 0);
    else if (daily_servings >= 5 && daily_servings <= 9)
        printf("%d", coffee1_bagweight == 500);
    else
        printf("%d", coffee1_bagweight == 1000);
    printf("      |   ");
    if (withcream == 'y' || withcream == 'Y')
        printf("%d", coffee1_withcream == 'y' || coffee1_withcream == 'Y');
    else
        printf("%d", coffee1_withcream == 'n' || coffee1_withcream == 'N');
    printf("   |      ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee1_servetemp <= 69.9 && coffee1_servetemp >= 60.0);
    else
        printf("%d", coffee1_servetemp >= 70.0);
    printf("\n 2|       ");
    if (coffee_strength == 'm' || coffee_strength == 'M')
        printf("%d", coffee2_type == 'l' || coffee2_type == 'L');
    else
        printf("%d", coffee2_type == 'b' || coffee2_type == 'B');
    printf("         |         ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee2_grindsize == 'c' || coffee2_grindsize == 'C');
    else
        printf("%d", coffee2_grindsize == 'f' || coffee2_grindsize == 'F');
    printf("          |      ");
    if (daily_servings >= 1 && daily_servings <= 4)
        printf("%d", coffee2_bagweight <= 250 && coffee2_bagweight >= 0);
    else if (daily_servings >= 5 && daily_servings <= 9)
        printf("%d", coffee2_bagweight == 500);
    else
        printf("%d", coffee2_bagweight == 1000);
    printf("      |   ");
    if (withcream == 'y' || withcream == 'Y')
        printf("%d", coffee2_withcream == 'y' || coffee2_withcream == 'Y');
    else
        printf("%d", coffee2_withcream == 'n' || coffee2_withcream == 'N');
    printf("   |      ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee2_servetemp <= 69.9 && coffee2_servetemp >= 60.0);
    else
        printf("%d", coffee2_servetemp >= 70.0);
    printf("\n 3|       ");
    if (coffee_strength == 'm' || coffee_strength == 'M')
        printf("%d", coffee3_type == 'l' || coffee3_type == 'L');
    else
        printf("%d", coffee3_type == 'b' || coffee3_type == 'B');
    printf("         |         ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee3_grindsize == 'c' || coffee3_grindsize == 'C');
    else
        printf("%d", coffee3_grindsize == 'f' || coffee3_grindsize == 'F');
    printf("          |      ");
    if (daily_servings >= 1 && daily_servings <= 4)
        printf("%d", coffee3_bagweight <= 250 && coffee3_bagweight >= 0);
    else if (daily_servings >= 5 && daily_servings <= 9)
        printf("%d", coffee3_bagweight == 500);
    else
        printf("%d", coffee3_bagweight == 1000);
    printf("      |   ");
    if (withcream == 'y' || withcream == 'Y')
        printf("%d", coffee3_withcream == 'y' || coffee3_withcream == 'Y');
    else
        printf("%d", coffee3_withcream == 'n' || coffee3_withcream == 'N');
    printf("   |      ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee3_servetemp <= 69.9 && coffee3_servetemp >= 60.0);
    else
        printf("%d", coffee3_servetemp >= 70.0);
    printf("\n\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffee_strength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &withcream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &daily_servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       ");
    if (coffee_strength == 'm' || coffee_strength == 'M')
        printf("%d", coffee1_type == 'l' || coffee1_type == 'L');
    else
        printf("%d", coffee1_type == 'b' || coffee1_type == 'B');
    printf("         |         ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee1_grindsize == 'c' || coffee1_grindsize == 'C');
    else
        printf("%d", coffee1_grindsize == 'f' || coffee1_grindsize == 'F');
    printf("          |      ");
    if (daily_servings >= 1 && daily_servings <= 4)
        printf("%d", coffee1_bagweight <= 250 && coffee1_bagweight >= 0);
    else if (daily_servings >= 5 && daily_servings <= 9)
        printf("%d", coffee1_bagweight == 500);
    else
        printf("%d", coffee1_bagweight == 1000);
    printf("      |   ");
    if (withcream == 'y' || withcream == 'Y')
        printf("%d", coffee1_withcream == 'y' || coffee1_withcream == 'Y');
    else
        printf("%d", coffee1_withcream == 'n' || coffee1_withcream == 'N');
    printf("   |      ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee1_servetemp <= 69.9 && coffee1_servetemp >= 60.0);
    else
        printf("%d", coffee1_servetemp >= 70.0);
    printf("\n 2|       ");
    if (coffee_strength == 'm' || coffee_strength == 'M')
        printf("%d", coffee2_type == 'l' || coffee2_type == 'L');
    else
        printf("%d", coffee2_type == 'b' || coffee2_type == 'B');
    printf("         |         ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee2_grindsize == 'c' || coffee2_grindsize == 'C');
    else
        printf("%d", coffee2_grindsize == 'f' || coffee2_grindsize == 'F');
    printf("          |      ");
    if (daily_servings >= 1 && daily_servings <= 4)
        printf("%d", coffee2_bagweight <= 250 && coffee2_bagweight >= 0);
    else if (daily_servings >= 5 && daily_servings <= 9)
        printf("%d", coffee2_bagweight == 500);
    else
        printf("%d", coffee2_bagweight == 1000);
    printf("      |   ");
    if (withcream == 'y' || withcream == 'Y')
        printf("%d", coffee2_withcream == 'y' || coffee2_withcream == 'Y');
    else
        printf("%d", coffee2_withcream == 'n' || coffee2_withcream == 'N');
    printf("   |      ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee2_servetemp <= 69.9 && coffee2_servetemp >= 60.0);
    else
        printf("%d", coffee2_servetemp >= 70.0);
    printf("\n 3|       ");
    if (coffee_strength == 'm' || coffee_strength == 'M')
        printf("%d", coffee3_type == 'l' || coffee3_type == 'L');
    else
        printf("%d", coffee3_type == 'b' || coffee3_type == 'B');
    printf("         |         ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee3_grindsize == 'c' || coffee3_grindsize == 'C');
    else
        printf("%d", coffee3_grindsize == 'f' || coffee3_grindsize == 'F');
    printf("          |      ");
    if (daily_servings >= 1 && daily_servings <= 4)
        printf("%d", coffee3_bagweight <= 250 && coffee3_bagweight >= 0);
    else if (daily_servings >= 5 && daily_servings <= 9)
        printf("%d", coffee3_bagweight == 500);
    else
        printf("%d", coffee3_bagweight == 1000);
    printf("      |   ");
    if (withcream == 'y' || withcream == 'Y')
        printf("%d", coffee3_withcream == 'y' || coffee3_withcream == 'Y');
    else
        printf("%d", coffee3_withcream == 'n' || coffee3_withcream == 'N');
    printf("   |      ");
    if (maker == 'r' || maker == 'R')
        printf("%d", coffee3_servetemp <= 69.9 && coffee3_servetemp >= 60.0);
    else
        printf("%d", coffee3_servetemp >= 70.0);
    printf("\n\nHope you found a product that suits your likes!\n");*/

    // You will need this when converting from grams to pounds (lbs)

char sizecoffee1, sizecoffee2, sizecoffee3;
double coffee1_weight, coffee2_weight, coffee3_weight;
char coffee1_cream, coffee2_cream, coffee3_cream;
char strength;
char withcream, withcream2;
int dailyservings;


printf("Take a Break - Coffee Shop\n");
printf("==========================\n\n");
printf("Enter the coffee product information being sold today...\n");
printf("\nCOFFEE-1...\n");
printf("Type ([L]ight,[M]edium,[R]ich): ");
scanf(" %c", &sizecoffee1);
printf("Bag weight (g): ");;
scanf(" %lf", &coffee1_weight);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c", &coffee1_cream);

printf("\nCOFFEE-2...\n");
printf("Type ([L]ight,[M]edium,[R]ich): ");
scanf(" %c", &sizecoffee2);
printf("Bag weight (g): ");
scanf(" %lf", &coffee2_weight);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c", &coffee2_cream);

printf("\nCOFFEE-3...\n");
printf("Type ([L]ight,[M]edium,[R]ich): ");
scanf(" %c", &sizecoffee3);
printf("Bag weight (g): ");;
scanf(" %lf", &coffee3_weight);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c", &coffee3_cream);


printf("\n---+------------------------+---------------+-------+\n");
printf("   |    Coffee              |   Packaged    | Best  |\n");
printf("   |     Type               |  Bag Weight   | Served|\n");
printf("   +------------------------+---------------+ With  |\n");
printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
printf("---+------------------------+---------------+-------|\n");
printf(" 1 |   %d   |   %d    |   %d   |  %0.lf | %6.3lf |   %d   |\n",
    sizecoffee1 == 'l' || sizecoffee1 == 'L', 
    sizecoffee1 == 'm' || sizecoffee1 == 'M',
    sizecoffee1 == 'r' || sizecoffee1 == 'R',
    coffee1_weight, coffee1_weight / GRAMS_IN_LBS,
    coffee1_cream == 'y' || coffee1_cream == 'Y');

printf(" 2 |   %d   |   %d    |   %d   |  %0.lf | %6.3lf |   %d   |\n",
    sizecoffee2 == 'l' || sizecoffee2 == 'L', 
    sizecoffee2 == 'm' || sizecoffee2 == 'M',
    sizecoffee2 == 'r' || sizecoffee2 == 'R',
    coffee2_weight, coffee2_weight / GRAMS_IN_LBS,
    coffee2_cream == 'y' || coffee2_cream == 'Y');

printf(" 3 |   %d   |   %d    |   %d   | %0.lf | %6.3lf |   %d   |\n",
    sizecoffee3 == 'l' || sizecoffee3 == 'L', 
    sizecoffee3 == 'm' || sizecoffee3 == 'M',
    sizecoffee3 == 'r' || sizecoffee3 == 'R',
    coffee3_weight, coffee3_weight / GRAMS_IN_LBS,
    coffee3_cream == 'y' || coffee3_cream == 'Y');

printf("\nEnter how you like your coffee...\n\n");
printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
scanf(" %c", &strength);
printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c", &withcream);
printf("Typical number of daily servings: ");
scanf(" %d", &dailyservings);


printf("\nThe below table shows how your preferences align to the available products:\n\n");
printf("--------------------+-------------+-------+\n");
printf("  |     Coffee      |  Packaged   | With  |\n");
printf("ID|      Type       | Bag Weight  | Cream |\n");
printf("--+-----------------+-------------+-------+\n");

printf(" 1|       %d         |      %d      |   %d   |\n",
    0 < dailyservings && dailyservings < 4, 0 < dailyservings && dailyservings < 4, withcream == 'y' || withcream == 'Y');
printf(" 2|       %d         |      %d      |   %d   |\n",
    5 < dailyservings && dailyservings < 9, 5 < dailyservings && dailyservings < 9, withcream == 'n' || withcream == 'N');
printf(" 3|       %d         |      %d      |   %d   |\n",
    dailyservings > 10, dailyservings > 10, withcream == 'n' || withcream == 'N');

printf("\nEnter how you like your coffee...\n\n");
printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
scanf(" %c", &strength);
printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c", &withcream2);
printf("Typical number of daily servings: ");
scanf(" %d", &dailyservings);


printf("\nThe below table shows how your preferences align to the available products:\n\n");
printf("--------------------+-------------+-------+\n");
printf("  |     Coffee      |  Packaged   | With  |\n");
printf("ID|      Type       | Bag Weight  | Cream |\n");
printf("--+-----------------+-------------+-------+\n");

printf(" 1|       %d         |      %d      |   %d   |\n",
    0 < dailyservings && dailyservings < 4, 0 < dailyservings && dailyservings < 4, withcream2 == 'y' || withcream2 == 'Y');
printf(" 2|       %d         |      %d      |   %d   |\n",
    5 < dailyservings && dailyservings < 9, 5 < dailyservings && dailyservings < 9, withcream2 == 'n' || withcream2 == 'N');
printf(" 3|       %d         |      %d      |   %d   |\n",
    dailyservings > 10, dailyservings > 10, withcream2 == 'n' || withcream2 == 'N');

printf("\nHope you found a product that suits your likes!\n");

return 0;
}