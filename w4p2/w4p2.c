
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
    /*
        ****************************************************************************
        < assessment name example : Workshop - #4 (Part - 2) >
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

int main()
{
    // Need the groceries
    int needApples;
    int needOranges;
    int needPears;
    int needTomatoes;
    int needCabbages;

    // Pick the groceries
    int pickApples;
    int pickOranges;
    int pickPears;
    int pickTomatoes;
    int pickCabbages;
    int i1 = 1, i2 = 1, i3 = 1, i4 = 1, i5 = 1, i6 = 1, i7 = 1, i8 = 1, i9 = 1, i10 = 1;

    // Do you wanna shop again ?
    int continuetoShop;

    printf("Grocery Shopping\n");
    printf("================\n");

    do 
    {

        printf("How many APPLES do you need? : ");
        scanf("%d", &needApples);

        if (needApples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        else if (needApples >= 0) 
        {
            i1 = 0;
        }
    } while (i1 == 1);
    
    do 
    {

        printf("\nHow many ORANGES do you need? : ");
        scanf("%d", &needOranges);

        if (needOranges < 0) 
        {
            printf("ERROR: Value must be 0 or more.");
        }
        else if (needOranges >= 0)
        {
            i2 = 0;
        }

    } while (i2 == 1);

    do 
    {

        printf("\nHow many PEARS do you need? : ");
        scanf("%d", &needPears);

        if (needPears < 0)
        {
            printf("ERROR: Value must be 0 or more.");
        }
        else if (needPears >= 0)
        {
            i3 = 0;
        }

    } while (i3 == 1);

    do 
    {
        printf("\nHow many TOMATOES do you need? : ");
        scanf("%d", &needTomatoes);

        if (needTomatoes < 0) 
        {
            printf("ERROR: Value must be 0 or more.");
        }
        else if (needTomatoes >= 0) 
        {
            i4 = 0;
        }

    } while (i4 == 1);

    do
    {
        printf("\nHow many CABBAGES do you need? : ");
        scanf("%d", &needCabbages);

        if (needCabbages < 0) {
            printf("ERROR: Value must be 0 or more.");
        }
        else if (needCabbages >= 0) {
            i5 = 0;
        }
    } while (i5 == 1);

    printf("\n--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n");

    do 
    {

        if (needApples > 0)
            printf("\nPick some APPLES... how many did you pick? : ");
        scanf("%d", &pickApples);

        if (pickApples > needApples)
        {
            printf("You picked too many... only %d more APPLE(S) are needed.", needApples);
        }
        else if (pickApples == needApples)
        {
            printf("Great, that's the apples done!");
            i6 = 0;
        }
        else if (pickApples < 1)
        {
            printf("ERROR: You must pick at least 1!");
        }
        else if (pickApples >= 1 && pickApples <= needApples)
        {
            needApples = needApples - pickApples;
            printf("Looks like we still need some APPLES...");
        }
        else if (pickApples > needApples)
        {
            printf("You picked too many... only %d more APPLE(S) are needed.", pickApples);
        }

    } while (i6 == 1);

    printf("\n");

    do {
        if (needPears > 0)

            printf("\nPick some PEARS... how many did you pick? : ");
        scanf("%d", &pickPears);

        if (pickPears > needPears) 
        {
            printf("You picked too many... only %d more PEAR(S) are needed.", needPears);
        }
        else if (pickPears == needPears)
        {
            printf("Great, that's the pears done!");
            i7 = 0;
        }
        else if (pickPears < 1) 
        {
            printf("ERROR: You must pick at least 1!");
        }
        else if (pickPears >= 1 && pickPears <= needPears)        
        {
            needPears = needPears - pickPears;
            printf("Looks like we still need some PEARS...");
        }
        else if (pickPears > needPears) 
        {
            printf("You picked too many... only %d more PEAR(S) are needed.", pickPears);
        }

    } while (i7 == 1);

    printf("\n");

    do
    {
        if (needCabbages > 0)
        printf("\nPick some CABBAGES... how many did you pick? : ");
        scanf("%d", &pickCabbages);

        if (pickCabbages > needCabbages)
        {
            printf("You picked too many... only %d more CABBAGE(S) are needed.", needCabbages);
        }
        else if (pickCabbages == needCabbages)
        {
            printf("Great, that's the cabbages done!");
            i8 = 0;
        }
        else if (pickCabbages < 1) 
        {
            printf("ERROR: You must pick at least 1!");
        }
        else if (pickCabbages >= 1 && pickCabbages <= needCabbages)
        {
            needCabbages = needCabbages - pickCabbages;
            printf("Looks like we still need some CABBAGES...");
        }
        else if (pickCabbages > needCabbages)
        {
            printf("You picked too many... only %d more CABBAGE(S) are needed.", pickCabbages);
        }

    } while (i8 == 1);

    printf("\n\n");
    printf("All the items are picked!\n\n");
    printf("Do another shopping? (0=NO): ");
    scanf("%d", &continuetoShop);
    printf("\n");

    if (continuetoShop == 1)
    {
        printf("Grocery Shopping\n");
        printf("================\n");
        printf("How many APPLES do you need? : ");
        scanf("%d", &needApples);
        printf("\n");
        printf("How many ORANGES do you need? : ");
        scanf("%d", &needOranges);
        printf("\n");
        printf("How many PEARS do you need? : ");
        scanf("%d", &needPears);
        printf("\n");
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &needTomatoes);
        printf("\n");
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &needCabbages);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");

        do
        {
            if (needOranges > 0)
                printf("\nPick some ORANGES... how many did you pick? : ");
            scanf("%d", &pickOranges);

            if (pickOranges > needOranges) 
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.", needOranges);
            }
            else if (pickOranges == needOranges) 
            {
                printf("Great, that's the oranges done!");
                i9 = 0;
            }
            else if (pickOranges < 1) 
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pickOranges >= 1 && pickOranges <= needOranges) 
            {
                needOranges = needOranges - pickOranges;
                printf("Looks like we still need some ORANGES...");
            }
            else if (pickOranges > needOranges) 
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.", pickOranges);
            }
        } while (i9 == 1);

        printf("\n");

        do 
        {
            if (needTomatoes > 0)
            printf("\nPick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pickTomatoes);

            if (pickTomatoes > needTomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.", needTomatoes);
            }
            else if (pickTomatoes == needTomatoes)
            {
                printf("Great, that's the tomatoes done!");
                i10 = 0;
            }
            else if (pickTomatoes < 1) 
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pickTomatoes >= 1 && pickTomatoes <= needTomatoes)
            {
                needTomatoes = needTomatoes - pickTomatoes;
                printf("Looks like we still need some TOMATOES...");
            }
            else if (pickTomatoes > needTomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.", pickTomatoes);
            }
        } while (i10 == 1);

        printf("\n\n");
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continuetoShop);
        printf("\n");

        if (continuetoShop == 0)
            printf("Your tasks are done for today - enjoy your free time!\n\n");

    }
    else if (continuetoShop == 0)
    {
        printf("Your tasks are done for today - enjoy your free time!");
    }

    return 0;
}
