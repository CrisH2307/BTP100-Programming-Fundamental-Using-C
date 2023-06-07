/*
*****************************************************************************
                        Assignment 1 - Milestone 2
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

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
#include <string.h>
#include "core.h"

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

char* cus_strcpy(char* Str2, const char* Str1)
{
    char* Str = Str2;

    while ((*Str2++ = *Str1++) != '\0');

    return Str;
}

int cus_strlen(char* Str1)
{
    int Length = 0;
    while (*Str1 != '\0')
    {
        Str1++;
        Length++;
    }
    return Length;
}

int inputInt(void)
{
    int Char = 0;
    char NewLine = 'x';
    if (NewLine == '\n')
        return Char;
    else {
        do {
            scanf("%d%c", &Char, &NewLine);
            if (NewLine != '\n')
            {
                clearInputBuffer();
                printf("Error! Input a whole number: ");
            }
        } while (NewLine != '\n');
        return Char;
    }
}

int inputIntPositive(void)
{
    int IntegerPositive = 0;
    do
    {
        IntegerPositive = inputInt();

        if (IntegerPositive < 0)
            printf("ERROR! Value must be > 0: ");

    } while (IntegerPositive < 0);

    return IntegerPositive;
} // Return IntegerPositive with no argunment

int inputIntRange(int Min, int Max)
{
    int IntRange = 0;
    do
    {
        IntRange = inputInt();

        if (IntRange < Min || IntRange > Max)
            printf("ERROR! Value must be between %d and %d inclusive: ", Min, Max);

    } while (IntRange < Min || IntRange > Max);

    return IntRange;
}

char inputCharOption(const char CStringArray[])
{
    char CharOption = 'a';
    char newline2 = 'x';
    int i;
    int WhiteFlag = 0;
    int stringLength = strlen(CStringArray);

    if (newline2 == '\n')
        return CharOption;

    else
    {
        do
        {
            scanf("%c", &CharOption);

            for (i = 0; i < stringLength; i++)
            {
                if (CharOption == CStringArray[i])
                    WhiteFlag = 1;
            }
            if (WhiteFlag == 0)
            {
                clearInputBuffer();
                printf("ERROR: Character must be one of [%s]: ", CStringArray);
            }

        } while (WhiteFlag == 0);
	clearInputBuffer();

    } // end of else statement

    return CharOption;
}

void inputCString(char* stringPtr, int Min, int Max)
{
    int WhiteFlag = 0;
    int stringLength = 0;
    char userInput[99];
    do {
        scanf("%[^\n]%*c", userInput);

        int i;

        for (i = 0; userInput[i] != '\0'; i++)
        {
            stringLength = i + 1;
        }
        if (Min == Max && stringLength != Min)
        {
            printf("ERROR: String length must be exactly %d chars: ", Min);
            WhiteFlag = 1;
        }
        else if (stringLength < Min)
        {
            printf("ERROR: String length must be between %d and %d chars: ", Min, Max);
            WhiteFlag = 1;
        }
        else if (stringLength > Max)
        {
            printf("ERROR: String length must be no more than %d chars: ", Max);
            WhiteFlag = 1;
        }
        else
        {
            WhiteFlag = 0;
            cus_strcpy(stringPtr, userInput);
        }
    } while (WhiteFlag != 0);

}

void displayFormattedPhone(const char* CStringParameter)
{
    int i;
    int Length;
    int GreenFlag = 0;

    if (CStringParameter) Length = strlen(CStringParameter);

    if (CStringParameter == NULL)
    {
        printf("(___)___-____");
    }
    else if (Length < 10 || Length > 10)
    {
        printf("(___)___-____");
    }
    else
    {
        for (i = 0; i < Length; i++)
        {
            if (CStringParameter[i] < '0' || CStringParameter[i] > '9')
            {
                GreenFlag = 1;
            }
        } // End of for loop

        if (GreenFlag == 0)
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", CStringParameter[0], CStringParameter[1], CStringParameter[2], CStringParameter[3], CStringParameter[4], CStringParameter[5], CStringParameter[6], CStringParameter[7], CStringParameter[8], CStringParameter[9]);
        }
        else
        {
            printf("(___)___-____");
        }
    } // End of If statement

} // End of the program

