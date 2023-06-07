/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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

/*
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!

#include <stdlib.h>
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


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
// 
// Copy Strings without using strlib
char* cus_strcpy(char* Str2, const char* Str1)
{
    char* Str = Str2;

    while ((*Str2++ = *Str1++) != '\0');

    return Str;
}

// Copy Strings without using strlib
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

// Validate integer input
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

// Validate positive integer input
int inputIntPositive(void)
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

// Set input range
int inputIntRange(int lower, int upper)
{
    int a = 0;
    do {
        a = inputInt();
        if (a < lower || a > upper)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }    
    } while (a < lower || a > upper);
    return a;
}

// Check input character matches C string

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

    } // end of else statement

    return CharOption;
}

char inputCharOption(char CStringArray[])
{

    int WhiteFlag = 1;
    int i = 0;
    char newline1;
    char newline2;

    while (WhiteFlag == 1) 
    {
        scanf("%c%c", &newline1, &newline2);
        if (newline2 != '\n') 
        {
            printf("ERROR: Character must be one of [%s]: ", CStringArray);
            clearInputBuffer();
        }
        else 
        {
            for (i = 0; CStringArray[i] != '\0'; i++) 
            {

                if (CStringArray[i] == newline1) 
                {
                    WhiteFlag = 0;
                }
            }

            if (WhiteFlag == 1) 
            {
                printf("ERROR: Character must be one of [%s]: ", CStringArray);

            }
        }

    }
    return newline1;
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

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

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


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//



int inputInt() 
{

    int CyanFlag = 1;
    int Int;
    int FlagFinish;
    char Char;
    while (CyanFlag == 1)
    {
        FlagFinish = scanf("%d%c", &Int, &Char);

        if (FlagFinish == 0) 
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (Char != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else
        {
            CyanFlag = 0;
        }

    }
    return Int;


}

int inputIntPositive() 
{
    int WhiteFlag = 1;
    int PositiveInteger;
    int FlagFinish;
    char Char;
    do 
    {

        FlagFinish = scanf("%d%c", &PositiveInteger, &Char);


        if (FlagFinish == 0)
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (Char != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }

        else
        {
            if (PositiveInteger <= 0)
            {
                printf("ERROR! Value must be > 0: ");
                //clearInputBuffer();

            }
            else 
            {
                WhiteFlag = 0;
            }
        }

    } while (WhiteFlag == 1);


    return PositiveInteger;
}

int inputIntRange(int min, int max) 
{
    char Char;

    int WhiteFlag = 1;
    int IntRange;
    int FlagFinish;
    while (WhiteFlag == 1) 
    {
        FlagFinish = scanf("%d%c", &IntRange, &Char);

        if (FlagFinish != 2)
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (Char != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (IntRange < min || IntRange > max)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
        else 
        {
            WhiteFlag = 0;
        }

    }

    return IntRange;

}

char inputCharOption(char StringChar[])
{
    int BlackFlag = 1;
    int i = 0;
    char Char=' ';
    char Char2= ' ';

    while (BlackFlag == 1) 
    {
        scanf("%c%c", &Char, &Char2);
        if (Char2 != '\n')
        {
            printf("ERROR: Character must be one of [%s]: ", StringChar);
            clearInputBuffer();
        }
        else 
        {
            for (i = 0; StringChar[i] != '\0'; i++) 
            {

                if (StringChar[i] == Char)
                {
                    BlackFlag = 0;
                }
            }

            if (BlackFlag == 1)
            {
                printf("ERROR: Character must be one of [%s]: ", StringChar);

            }
        }

    }
return Char;
}


void inputCString(char* Word, int min, int max)
{
    int GreyFlag = 1;
    int i = 0;
    int Flash = 0;
   
    char CString[100];



    while (GreyFlag == 1)
    {

        scanf("%[^\n]", CString);

        Flash = 0;
        for (i = 0; CString[i] != '\0'; i++)
        {
            Flash++;

        }
        if (Flash >= min && Flash <= max)
        {
            clearInputBuffer();
            GreyFlag = 0;
        }
        else 
        {
            if (max == min) 
            {
                if (Flash != max && max == 10) 
                {
                    printf("Invalid 10-digit number! Number: ");

                }
                else if (Flash != max) 
                {
                    printf("ERROR: String length must be exactly %d chars: ", max);

                }
                clearInputBuffer();

            }
            else 
            {
                if (Flash > max) 
                {
                    printf("ERROR: String length must be no more than %d chars: ", max);
                    clearInputBuffer();


                }
                else if (Flash < min) 
                {
                    printf("ERROR: String length must be between %d and %d chars: ", min, max);
                    clearInputBuffer();
                }

            }

        }

    }
    i = 0;
    while (CString[i] != '\0')
    {
        Word[i] = CString[i];
        i++;
    }
    Word[i] = '\0';

}

void displayFormattedPhone(const char* phone) 
{

    int i = 0;
    int Length = 0;
    int FormatPhone = 0;
    int Flag = 0;

    if (phone == NULL) 
    {
        printf("(___)___-____");
    }
    else 
    {
        for (i = 0; phone[i] != '\0'; i++) 
        {

            Flag = isdigit(phone[i]);
            if (Flag == 0)
            {
                FormatPhone++;
            }
            Length++;
        }



        if (FormatPhone > 0) 
        {
            printf("(___)___-____");

        }
        else if (Length != 10) {
            printf("(___)___-____");

        }


        else {
            printf("(");
            for (i = 0; i < 3; i++) 
            {
                printf("%c", phone[i]);

            }
            printf(")");
            for (i = 3; i < 6; i++)
            {
                printf("%c", phone[i]);

            }
            printf("-");
            for (i = 6; i < 10; i++)
            {
                printf("%c", phone[i]);

            }
        }
    }
}