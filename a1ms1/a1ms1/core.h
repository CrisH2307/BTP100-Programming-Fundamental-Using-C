
/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

// Wait for user to input the "enter" key to continue
void suspend(void);

// Clear the standard input buffer
void clearInputBuffer(void);

int StringLength(char* String1);

char* StringHold(char* String2, const char* StringConst);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int Min, int Max);

char inputCharOption(const char CStringArray[]);

void inputCString(char* CString, int Min, int Max);

void displayFormattedPhone(char* CStringParameter);



#endif