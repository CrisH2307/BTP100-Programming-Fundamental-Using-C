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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
	printf("Pat.# Name            Phone#\n"
		"----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
	if (fmt == FMT_FORM)
	{
		printf("Name  : %s\n"
			"Number: %05d\n"
			"Phone : ", patient->name, patient->patientNumber);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
	else
	{
		printf("%05d %-15s ", patient->patientNumber,
			patient->name);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
	printf("Clinic Appointments for the Date: ");

	if (isAllRecords)
	{
		printf("<ALL>\n\n");
		printf("Date       Time  Pat.# Name            Phone#\n"
			"---------- ----- ----- --------------- --------------------\n");
	}
	else
	{
		printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
		printf("Time  Pat.# Name            Phone#\n"
			"----- ----- --------------- --------------------\n");
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
	const struct Appointment* appoint,
	int includeDateField)
{
	if (includeDateField)
	{
		printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
			appoint->date.day);
	}
	printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
		patient->patientNumber, patient->name);

	displayFormattedPhone(patient->phone.number);

	printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
	int selection;

	do {
		printf("Veterinary Clinic System\n"
			"=========================\n"
			"1) PATIENT     Management\n"
			"2) APPOINTMENT Management\n"
			"-------------------------\n"
			"0) Exit System\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');
		switch (selection)
		{
		case 0:
			printf("Are you sure you want to exit? (y|n): ");
			selection = !(inputCharOption("yn") == 'y');
			putchar('\n');
			if (!selection)
			{
				printf("Exiting system... Goodbye.\n\n");
			}
			break;
		case 1:
			menuPatient(data->patients, data->maxPatient);
			break;
		case 2:
			menuAppointment(data);
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
	int selection;

	do {
		printf("Patient Management\n"
			"=========================\n"
			"1) VIEW   Patient Data\n"
			"2) SEARCH Patients\n"
			"3) ADD    Patient\n"
			"4) EDIT   Patient\n"
			"5) REMOVE Patient\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 5);
		putchar('\n');
		switch (selection)
		{
		case 1:
			displayAllPatients(patient, max, FMT_TABLE);
			suspend();
			break;
		case 2:
			searchPatientData(patient, max);
			break;
		case 3:
			addPatient(patient, max);
			suspend();
			break;
		case 4:
			editPatient(patient, max);
			break;
		case 5:
			removePatient(patient, max);
			suspend();
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
	int selection;

	do {
		printf("Edit Patient (%05d)\n"
			"=========================\n"
			"1) NAME : %s\n"
			"2) PHONE: ", patient->patientNumber, patient->name);

		displayFormattedPhone(patient->phone.number);

		printf("\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');

		if (selection == 1)
		{
			printf("Name  : ");
			inputCString(patient->name, 1, NAME_LEN);
			putchar('\n');
			printf("Patient record updated!\n\n");
		}
		else if (selection == 2)
		{
			inputPhoneData(&patient->phone);
			printf("Patient record updated!\n\n");
		}

	} while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
	int selection;

	do {
		printf("Appointment Management\n"
			"==============================\n"
			"1) VIEW   ALL Appointments\n"
			"2) VIEW   Appointments by DATE\n"
			"3) ADD    Appointment\n"
			"4) REMOVE Appointment\n"
			"------------------------------\n"
			"0) Previous menu\n"
			"------------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
		case 1:
			viewAllAppointments(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 2:
			viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 3:
			addAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 4:
			removeAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		}
	} while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) \
{
	int i = 0;
	int WhiteFlag = -1;
	displayPatientTableHeader();

	for (i = 0; i < max; i++) 
	{
		if (patient[i].patientNumber != 0) 
		{
			displayPatientData(&patient[i], fmt);
			WhiteFlag++;
		}
	}
	if (WhiteFlag == -1) 
	{
		printf("*** No records found ***\n");
	}
	printf("\n");
}


// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max) 
{
	int Options;
	int BlackFlag = 0;

	while (BlackFlag == 0) 
	{
		printf("Search Options\n");
		printf("==========================\n");
		printf("1) By patient number\n");
		printf("2) By phone number\n");
		printf("..........................\n");
		printf("0) Previous menu\n");
		printf("..........................\n");
		printf("Selection: ");
		Options = inputIntRange(0, 2);
		printf("\n");

		switch (Options)
		{
		case 0:
			BlackFlag = 1;
			break;

		case 1:
			searchPatientByPatientNumber(patient, max);
			printf("\n");
			suspend();
			break;

		case 2:
			searchPatientByPhoneNumber(patient, max);
			printf("\n");
			suspend();
			break;

		default:
			break;
		}


	}


	return;
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) 
{
	int i = 0;
	int CheckNumber = 0;
	int Index = -1;

	for (i = 0; i < max && CheckNumber == 0; i++)
	{
		if (patient[i].patientNumber == 0) 
		{
			CheckNumber = 1;
			Index = i;
		}
	}
	if (CheckNumber == 0) 
	{
		printf("ERROR: Patient listing is FULL!\n\n");
	}
	else 
	{

		patient[Index].patientNumber = nextPatientNumber(patient, max);

		inputPatient(&patient[Index]);

		printf("*** New patient record added ***\n\n");

	}

	return;
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)

void editPatient(struct Patient patient[], int max) 
{
	int Index = 0;
	int PatientNumber = 0;
	printf("Enter the patient number: ");
	PatientNumber = inputIntPositive();
	Index = findPatientIndexByPatientNum(PatientNumber, patient, max);
	printf("\n");
	if (Index != -1) 
	{
		menuPatientEdit(&patient[Index]);
	}
	else 
	{
		printf("ERROR: Patient record not found!\n");
	}

	return;

}

// Remove a patient record from the patient array
// (Copy your code from MS#2)

void removePatient(struct Patient patient[], int max) 
{
	int Index = 0;
	int PatientNumber = 0;
	char Remove;

	printf("Enter the patient number: ");

	PatientNumber = inputIntPositive();
	Index = findPatientIndexByPatientNum(PatientNumber, patient, max);


	if (Index != -1) 
	{
		printf("\n");
		displayPatientData(&patient[Index], FMT_FORM);
		printf("\nAre you sure you want to remove this patient record? (y/n): ");

		Remove = inputCharOption("yn");

		if (Remove == 'y') 
		{
			strcpy(patient[Index].name, "\0");
			strcpy(patient[Index].phone.description, "\0");
			strcpy(patient[Index].phone.number, "\0");
			patient[Index].patientNumber = 0;

			printf("Patient record has been removed!\n\n");

		}
		else 
		{
			printf("Operation aborted.\n\n");

		}
	}
	else 
	{
		printf("\nERROR: Patient record not found!\n\n");
	}

	return;

}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) 
{
	int i = 0;
	int Index = 0;

	SortAppointments(data->appointments);

	displayScheduleTableHeader(&data->appointments->date, 1);


	for (i = 0; i < data->maxAppointments; i++) {

		if (data->appointments[i].patientNumber != 0) {
			Index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);

			displayScheduleData(&data->patients[Index], &data->appointments[i], 1);
		}
	}
	printf("\n");

	return;
}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) 
{
	int year = 0;
	int month = 0;
	int day = 0;
	int i = 0;
	int PurpleFlag = 0;
	int Index = 0;

	inputDate(&day, &month, &year);

	printf("\n");
	for (i = 0; i < data->maxAppointments && PurpleFlag == 0; i++) 
	{

		if (day == data->appointments[i].date.day && month == data->appointments[i].date.month && year == data->appointments[i].date.year) 
		{
			displayScheduleTableHeader(&data->appointments[i].date, 0);
			PurpleFlag = 1;
		}
	}


	for (i = 0; i < data->maxAppointments; i++) 
	{
		if (day == data->appointments[i].date.day && month == data->appointments[i].date.month && year == data->appointments[i].date.year) 
		{
			Index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);

			displayScheduleData(&data->patients[Index], &data->appointments[i], 0);

		}
	}

	printf("\n");

}


// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patient, int maxPatient) 
{

	int i = 0;
	int Index = -1;
	int PatientNumber = 0;
	int YellowFlag = -1;
	int BlueFlag = 0;
	int FlagFinish = 0;
	int year = 0;
	int day = 0;
	int month = 0;
	int hour = 0;
	int min = 0;

	printf("Patient Number: ");
	PatientNumber = inputIntPositive();
	YellowFlag = findPatientIndexByPatientNum(PatientNumber, patient, MAX_PETS_);
	if (YellowFlag == -1)
	{
		printf("\n*** No records found ***\n");
	}
	else 
	{
		for (i = 0; i < maxAppointments && Index == -1; i++)
		{
			if (appointments[i].patientNumber == 0) 
			{
				Index = i;
			}
		}

		if (Index == -1)
		{
			printf("\nERROR: Appointment timeslot is not available!\n");
		}
		else 
		{

			while (FlagFinish == 0)
			{
				inputDate(&day, &month, &year);
				inputTime(&hour, &min);

				BlueFlag = 0;

				for (i = 0; i < maxAppointments && BlueFlag == 0; i++)
				{
					if (appointments[i].date.day == day && appointments[i].date.month == month && appointments[i].date.year == year && appointments[i].time.hour == hour && appointments[i].time.min == min) 
					{
						printf("\nERROR: Appointment timeslot is not available!\n\n");
						BlueFlag = 1;
					}
				}
				if (BlueFlag != 1)
				{
					appointments[Index].patientNumber = PatientNumber;
					appointments[Index].date.day = day;
					appointments[Index].date.month = month;
					appointments[Index].date.year = year;
					appointments[Index].time.hour = hour;
					appointments[Index].time.min = min;

					printf("\n*** Appointment scheduled! ***\n\n");
					FlagFinish = 1;
					SortAppointments(appointments);
				}

			}


		}

	}

}


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patient, int maxPatient) 
{

	int i = 0;
	int FlagFinish = -1;
	int PatientNumber = 0;
	int Index = -1;
	int PinkFlag = 0;
	int year = 0;
	int day = 0;
	int month = 0;
	char Remove;


	printf("Patient Number: ");
	PatientNumber = inputIntPositive();
	Index = findPatientIndexByPatientNum(PatientNumber, patient, MAX_PETS_);
	if (Index == -1)
	{
		printf("ERROR: Patient record not found!\n\n");

	}
	else 
	{
		inputDate(&day, &month, &year);

		for (i = 0; i < maxAppointments && PinkFlag == 0; i++)
		{
			if (appointments[i].date.day == day && appointments[i].date.month == month && appointments[i].date.year == year && appointments[i].patientNumber == PatientNumber)
			{
				printf("\n");
				displayPatientData(&patient[Index], FMT_FORM);
				FlagFinish = i;

				PinkFlag = 1;

			}
		}


		if (PinkFlag != 1)
		{
			printf("ERROR: Appointment timeslot is not available!");
		}
		else 
		{

			printf("Are you sure you want to remove this appointment (y,n): ");
			Remove = inputCharOption("yn");
			if (Remove == 'y') 
			{
				printf("\nAppointment record has been removed!\n\n");
				appointments[FlagFinish].patientNumber = 0;
				appointments[FlagFinish].date.day = 0;
				appointments[FlagFinish].date.month = 0;
				appointments[FlagFinish].date.year = 0;
				appointments[FlagFinish].time.min = 0;
				appointments[FlagFinish].time.hour = 0;

			}
			else {
				printf("operation aborted!");
			}
		}



	}

}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) 
{

	int PatientNumber;
	int PatientSearch;

	printf("Search by patient number: ");
	PatientNumber = inputIntPositive();

	PatientSearch = findPatientIndexByPatientNum(PatientNumber, patient, max);


	if (PatientSearch != -1) 
	{
		printf("\n");
		displayPatientData(&patient[PatientSearch], FMT_FORM);
	}
	else 
	{
		printf("\n*** No records found ***\n");
	}

	return;

}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
	char PhoneNumber[PHONE_LEN + 1];
	int i = 0;
	int PatientCheck = 0;
	int Index = 0;
	printf("Search by phone number: ");
	inputCString(PhoneNumber, PHONE_LEN, PHONE_LEN);
	printf("\n");
	displayPatientTableHeader();
	for (i = 0; i < max; i++) 
	{
		PatientCheck = strcmp(PhoneNumber, patient[i].phone.number);

		if (PatientCheck == 0)
		{
			displayPatientData(&patient[i], FMT_TABLE);
			Index++;
		}

	}
	if (Index == 0) 
	{
		printf("\n*** No records found ***\n");

	}

	return;

}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max) 
{
	int i = 0;
	int Next = 0;

	for (i = 0; i < max; i++) 
	{
		if (patient[i].patientNumber > Next)
		{
			Next = patient[i].patientNumber;

		}
	}
	Next += 1;

	return Next;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient Patient[], int max) 
{

	int i = 0;
	int RedFlag = 0;

	for (i = 0; i < max && RedFlag == 0; i++)
	{
		if (patientNumber == Patient[i].patientNumber) 
		{
			RedFlag = 1;
		}

	}
	if (RedFlag == 0) 
	{
		i = -1;
	}
	else 
	{
		i--;
	}


	return i;
}

void SortAppointments(struct Appointment* Appointment) 
{
	int i;
	int j;
	int Appointment1;
	int Appointment2;


	for (i = 0; i < MAX_APPOINTMENTS_; i++)
	{
		j = 0;

		for (j = 0; j < MAX_APPOINTMENTS_ - i - 1 && Appointment[j + 1].patientNumber != 0; j++)
		{

			Appointment1 = Appointment[j].time.min;
			Appointment2 = Appointment[j + 1].time.min;
			if (Appointment1 > Appointment2)
			{
				Reverse(&Appointment[j], &Appointment[j + 1]);

			}
		}
	}

	for (i = 0; i < MAX_APPOINTMENTS_; i++)
	{
		j = 0;

		for (j = 0; j < MAX_APPOINTMENTS_ - i - 1 && Appointment[j + 1].patientNumber != 0; j++)
		{


			Appointment1 = Appointment[j].time.hour;
			Appointment2 = Appointment[j + 1].time.hour;
			if (Appointment1 > Appointment2)
			{
				Reverse(&Appointment[j], &Appointment[j + 1]);

			}
		}
	}

	for (i = 0; i < MAX_APPOINTMENTS_; i++) 
	{
		j = 0;

		for (j = 0; j < MAX_APPOINTMENTS_ - i - 1 && Appointment[j + 1].patientNumber != 0; j++)
		{


			Appointment1 = Appointment[j].date.day;
			Appointment2 = Appointment[j + 1].date.day;
			if (Appointment1 > Appointment2)
			{
				Reverse(&Appointment[j], &Appointment[j + 1]);

			}
		}
	}

	for (i = 0; i < MAX_APPOINTMENTS_; i++) 
	{
		j = 0;

		for (j = 0; j < MAX_APPOINTMENTS_ - i - 1 && Appointment[j + 1].patientNumber != 0; j++)
		{


			Appointment1 = Appointment[j].date.month;
			Appointment2 = Appointment[j + 1].date.month;
			if (Appointment1 > Appointment2)
			{
				Reverse(&Appointment[j], &Appointment[j + 1]);
			}
		}
	}


	for (i = 0; i < MAX_APPOINTMENTS_; i++)
	{
		for (j = 0; j < MAX_APPOINTMENTS_ - i - 1 && Appointment[j + 1].patientNumber != 0; j++)
		{

			Appointment1 = Appointment[j].date.year;
			Appointment2 = Appointment[j + 1].date.year;
			if (Appointment1 > Appointment2)
			{
				Reverse(&Appointment[j], &Appointment[j + 1]);
			}
		}
	}

}


void Reverse(struct Appointment* Data1, struct Appointment* Data2) 
{
	struct Appointment Data = { 0 };

	Data = *Data1;
	*Data1 = *Data2;
	*Data2 = Data;


}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* Patient) 
{

	printf("Patient Data Input\n");
	printf("------------------\n");
	printf("Number: %05d\n", (*Patient).patientNumber);
	printf("Name  : ");
	inputCString(Patient->name, 1, NAME_LEN);
	printf("\n");
	inputPhoneData(&Patient->phone);

	return;

}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* Phone)
{
	int Contacted = 0;

	printf("Phone Information\n");
	printf("-----------------\n");
	printf("How will the patient like to be contacted?\n");
	printf("1. Cell\n");
	printf("2. Home\n");
	printf("3. Work\n");
	printf("4. TBD\n");
	printf("Selection: ");
	Contacted = inputIntRange(1, 4);
	if (Contacted == 4) 
	{
		strcpy(Phone->description, "TBD");
		printf("\n");
	}
	else 
	{
		if (Contacted == 1) 
		{
			strcpy(Phone->description, "CELL");
		}
		else if (Contacted == 2) 
		{
			strcpy(Phone->description, "HOME");
		}
		else if (Contacted == 3)
		{
			strcpy(Phone->description, "WORK");
		}

		printf("\nContact: %s\n", Phone->description);
		printf("Number : ");
		inputCString(Phone->number, PHONE_LEN, PHONE_LEN);
		printf("\n");
	}

	return;

}
// Get user input for Date
void inputDate(int* day, int* month, int* year) 
{
	int MaxMonth = 0;
	printf("Year        : ");
	*year = inputIntPositive();
	printf("Month (1-12): ");
	*month = inputIntRange(1, 12);

	if (*month == 2)
	{
		if (*year % 4 == 0) 
		{
			MaxMonth = 29;
		}
		else
		{
			MaxMonth = 28;
		}
	}
	else if (*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 || *month == 12) 
	{
		MaxMonth = 31;
	}
	else 
	{
		MaxMonth = 30;
	}
	printf("Day (%d-%d)  : ",1, MaxMonth);
	*day = inputIntRange(1, MaxMonth);
}


// Get user input for time
void inputTime(int* hour, int* min)
{
	int GreenFlag = 0;

	while (GreenFlag == 0)
	{
		printf("Hour (0-23)  : ");
		*hour = inputIntRange(0, 23);
		printf("Minute (0-59): ");
		*min = inputIntRange(0, 59);

		if (*hour >= START_HOURS && *hour <= END_HOURS && *min % TIME_INTERVAL == 0) 
		{
			if (*hour == END_HOURS && *min == 30) 
			{
				printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", START_HOURS, END_HOURS);
			}
			else 
			{
				GreenFlag = 1;
			}
		}
		else 
		{
			printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", START_HOURS, END_HOURS);
		}
	}
}
//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:


int importPatients(const char* datafile, struct Patient patients[], int max) 
{
	int i = 0;
	int OrangeFlag = 0;
	FILE* fp = NULL;
	fp = fopen(datafile, "r");

	if (fp != NULL) 
	{

		for (i = 0; i < max && OrangeFlag == 0; i++) 
		{
			if (feof(fp) != 0) 
			{
				OrangeFlag = 1;
			}
			fscanf(fp, "%d|%15[^|]|%4[^|]|%10[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);

		}
		fclose(fp);

	}
	else
	{
		printf("Failed to open file \n");
	}


	return i;
}




// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appointments[], int max)
{
	int i = 0;
	int Index = 0;
	FILE* fp = NULL;
	fp = fopen(datafile, "r");

	if (fp != NULL) 
	{

		for (i = 0; i < max && feof(fp) == 0; i++) 
		{
			fscanf(fp, "%d,%d,%d,%d,%d,%d", &appointments[i].patientNumber, &appointments[i].date.year, &appointments[i].date.month, &appointments[i].date.day, &appointments[i].time.hour, &appointments[i].time.min);
			if (appointments[i].patientNumber != 0) 
			{
				Index++;
			}
		}
		fclose(fp);
	}
	else 
	{
		printf("Failed to open file \n");
	}
	return Index;
}
