#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
using namespace std;

//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character 
string inputString(string prompt, bool spaces)
{
	string input = "";

	cout << prompt;
	if (spaces)
		getline(cin, input);
	else
	{
		cin >> input;
		cin.clear();
		cin.ignore(999, '\n');
	}
	return input;
}

//PreCondition: valid string of options
//PostCondition: returns an uppercase  of the option (char)
char inputChar(string prompt, string options)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a character type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			bool found = false;
			for (int i = 0; i < options.length(); i++)
				if ((toupper(options.at(i))) == toupper(input))
				{
					found = true;
					break;
				}
			if (found)
			{
				cin.clear();
				cin.ignore(999, '\n');
				break;
			}
			else
			{
				SetConsoleTextAttribute(color, 12);
				cout << "ERROR: Invalid input. Must be one of '" << options << "' character.\n";
				SetConsoleTextAttribute(color, 15);
			}

		}
	} while (true);
	return toupper(input);
}

//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char yes, char no)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a character type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
	} while (true);
	return toupper(input);
}

//PreCondition: alphaOrDigit (boolean true or false)
//PostCondition: returns an alphabet or a digit character
char inputChar(string prompt, bool alphaOrDigit)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a character type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be an alphabet character.\n";
			SetConsoleTextAttribute(color, 15);
		}
		else if (!alphaOrDigit && !isdigit(input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a digit character.\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
	} while (true);
	return input;
}

//PreCondition: NA
//PostCondition: returns any character
char inputChar(string prompt)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a character type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return toupper(input);
}

//PreCondition: NA
//PostCondition: returns any integer value
int inputInteger(string prompt)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(string prompt, bool posNeg)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a positive number.\n";
			SetConsoleTextAttribute(color, 15);
		}
		else if (!posNeg && input >= 0)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a negative number.\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start (integer) and greater (boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(string prompt, int start, bool greater)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input < start)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a greater than or equal to " << start << ".\n";
			SetConsoleTextAttribute(color, 15);
		}
		else if (!greater && input > start)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a lesser than or equal to " << start << ".\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
int inputInteger(string prompt, int startRange, int endRange)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: NA
//PostCondition: returns any double value
double inputDouble(string prompt)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a double type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(string prompt, bool posNeg)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a double type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0.0)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a positive number.\n";
			SetConsoleTextAttribute(color, 15);
		}
		else if (!posNeg && input >= 0.0)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a negative number.\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start(integer) and greater(boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
double inputDouble(string prompt, double start, bool posNeg)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a double type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= start)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
			SetConsoleTextAttribute(color, 15);
		}
		else if (!posNeg && input >= start)
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be a double type.\n";
			SetConsoleTextAttribute(color, 15);
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
		{
			SetConsoleTextAttribute(color, 12);
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
			SetConsoleTextAttribute(color, 15);
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}