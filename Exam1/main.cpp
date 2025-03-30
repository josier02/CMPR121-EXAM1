
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include <windows.h>

#include "input.h"
using namespace std;

void sectionA();
//void sectionB();
//void sectionC();
//void xTraCredit();

struct Element
{
    short atomicNum = 0; //Atomic Number
    char symbol[3] = "un"; //Symbol
    char name[25] = "unknown"; //Name
    float mass = 0.0; //Mass
    char stateType = 'u'; //State type
    short groupNum = 0; //Group #
    short periodNum = 0; // Period #
    char blockType = 'u'; //Block type
    float meltingPoint = 0.0; //Melting Point
    float boilingPoint = 0.0; //Boiling Point
    short discoveryYear = 0; //Discovery Year
    char discoveredBy[100] = "unknown"; //Discovered by
};

int main()
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Periodic Table of Elements by Atomic Number & Symbol";


    do
    {
        system("cls");
        cout << "\n\tCMPR121: Exam#1: Implementation using Dynamic Array, string/C-string, struct, and Binary File By Josephine Razo ";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t A) Advance Binary Data File (Chapter#12)";
        cout << "\n\t B) Dynamic Array (Chapter#9)";
        cout << "\n\t C) Vector (Chapter#7)";
        cout << "\n\t X) Xtra credits (5 pts)";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t Q) Quit (terminate) Program";
        cout << "\n\t" << string(80, char(205));
        cout << "\n";

        switch (toupper(inputChar("\nOption: ", static_cast<string>("ABCXQ"))))
        {
        case 'Q': exit(0);
        case 'A': sectionA(); break;
            /* case 'B': sectionB(); break;
             case 'C': sectionC(); break;*/
             /* case 'X': xTraCredit(); break; */

        default:
            SetConsoleTextAttribute(color, FOREGROUND_RED);
            cout << "\n\tERROR: Invalid option.\n";
            SetConsoleTextAttribute(color, 15);
        }
        system("pause");
    } while (true);

    return 0;
}


void displayAllElements(Element element, fstream& binaryFile)
{
    float kelvinm = 0.0;
    float farenheitm = 0.0;
    float kelvinb = 0.0;
    float farenheitb = 0.0;
    string blockTypeName = "unknown";
    char block = toupper(element.blockType);
    string discoveryYear;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    kelvinm = element.meltingPoint + 273.15;
    farenheitm = (element.meltingPoint * 1.8) + 32;

    kelvinb = element.boilingPoint + 273.15;
    farenheitb = (element.boilingPoint * 1.8) + 32;


    switch (block)
    {
    case 'P':
        blockTypeName = "principal";
        break;
    case 'D':
        blockTypeName = "diffuse";
        break;
    case 'S':
        blockTypeName = "sharp";
        break;
    case 'F':
        blockTypeName = "fundamental";
        break;
    default:
        break;
    }

    SetConsoleTextAttribute(color, 2);
    cout << "Atomic # " << right << setw(8) << ": " << element.atomicNum << "\n";
    cout << "Symbol " << right << setw(10) << ": " << element.symbol << "\n";
    cout << "Name " << right << setw(12) << ": " << element.name << "\n";
    cout << "Mass " << right << setw(12) << setprecision(3) << ": " << element.mass << " u\n";
    cout << "State type " << right << setw(6) << ": " << element.stateType << "\n";
    cout << "Group # " << right << setw(9) << setprecision(1) << ": " << element.groupNum << "\n";
    cout << "Period # " << right << setw(8) << ": " << element.periodNum << "\n";
    cout << "Block type " << right << setw(7) << ": (" << block << ") " << blockTypeName << "\n";
    cout << "Melting point " << right << setw(3) << setprecision(2) << fixed << ": " << element.meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n";
    cout << "Boiling point " << right << setw(3) << ": " << element.boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n";
    cout << "Discovery year " << right << setw(2) << ": ";
    if (element.discoveryYear == 0)
    {
        cout << "Prehistoric" << "\n";
    }
    else
    {
        cout << element.discoveryYear << "\n";
    }
    cout << "Discovered by " << right << setw(3) << ": " << element.discoveredBy << "\n\n";
    SetConsoleTextAttribute(color, 15);
}


void sectionA_fileElementDisplay(fstream& binaryFile)
{
    system("cls"); //clears the screen
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    Element element; //holds information about an element

    long numBytes;
    int count = 0;

    // loops through every record found in the file
    while (binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element)))
    {
        displayAllElements(element, binaryFile);
        count++;
    }

    binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
    SetConsoleTextAttribute(color, 2);
    cout << "CONFIRMATION: " << count << " record(s) found. \n\n";
    SetConsoleTextAttribute(color, 15);
}

void sectionA_addElement(fstream& binaryFile, string fileBin, long atomicNum)
{
    Element element;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    element.atomicNum = static_cast <short> (atomicNum);
    strncpy_s(element.symbol, inputString("Specify the Element Symbol: ", false).c_str(), sizeof(element.symbol) - 1);
    strncpy_s(element.name, inputString("Specify the Element Name: ", false).c_str(), sizeof(element.name) - 1);
    element.mass = static_cast<float> (inputDouble("Specify the Element Mass: ", true));
    element.stateType = inputChar("Specify the Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU"));
    element.groupNum = inputInteger("Specify the Element Group # (0-unknown or 1...18) : ", 0, 18);
    element.periodNum = inputInteger("Specify the Element Period # (0-unknown or 1...7) : ", 0, 7);
    element.blockType = inputChar("Specify the Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF"));
    element.meltingPoint = inputDouble("Specify the Element Melting Point (celsius degree) : ");
    element.boilingPoint = inputDouble("Specify the Element Boiling Point (celsius degree) : ");
    element.discoveryYear = static_cast <short> (inputInteger("Specify the Element Discovery Year : ", 0, 2025));
    strncpy_s(element.discoveredBy, inputString("Specify the Element Discovered By : ", true).c_str(), sizeof(element.discoveredBy) - 1);

    binaryFile.write(reinterpret_cast<char*> (&element), sizeof(element));
    SetConsoleTextAttribute(color, 2);
    cout << "\nCONFIRMATION: A new element with Atomic # (" << element.atomicNum << ") has been added / appended into the binary data file, " << fileBin << " \n";
    SetConsoleTextAttribute(color, 15);
}



void sectionA_updateElement(Element element, fstream& binaryFile, string fileBin, int recNum, int count)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    Element temp;

    temp = element;

    do
    {
        system("cls");
        SetConsoleTextAttribute(color, 2);
        displayAllElements(temp, binaryFile);
        SetConsoleTextAttribute(color, 15);


        cout << "\n\tUpdating Element's information...";
        cout << "\n\t" << string(80, '=');
        cout << "\n\t1) Symbol";
        cout << "\n\t2) Name";
        cout << "\n\t3) Atomic Mass";
        cout << "\n\t4) State Type";
        cout << "\n\t5) Group#";
        cout << "\n\t6) Block Type";
        cout << "\n\t7) Period Type";
        cout << "\n\t8) Melting Point";
        cout << "\n\t9) Boiling Point";
        cout << "\n\t10) Discovered Year";
        cout << "\n\t11) Discovered By";
        cout << "\n\t" << string(80, '-');
        cout << "\n\t-1) Return WITHOUT change(s)";
        cout << "\n\t0) Return WITH commited change(s)";
        cout << "\n\t" << string(80, '=');


        switch (inputInteger("\n\tOption: ", -1, 11))
        {
        case 0:

            binaryFile.seekp(count * sizeof(temp), ios::beg);
            //// temp to original file. 
            element = temp;
            //Writes to specified record
            binaryFile.write(reinterpret_cast<char*>(&element), sizeof(element));
            SetConsoleTextAttribute(color, 2);
            cout << "CONFIRMATION: Element with Atomic # (" << recNum << ") has been updated into the binary data file," << fileBin << "\n";
            SetConsoleTextAttribute(color, 15);
            return;
        case -1:
            temp = { 0 };
            SetConsoleTextAttribute(color, 0x0E);
            cout << "WARNING: No update was commited.\n";
            SetConsoleTextAttribute(color, 0x07);
            return;
        case 1:
            strncpy_s(temp.symbol, inputString("Specify a new Element Symbol: ", false).c_str(), sizeof(temp.symbol) - 1);
            break;
        case 2:
            strncpy_s(temp.name, inputString("Specify a new Element Name: ", false).c_str(), sizeof(temp.name) - 1);
            break;
        case 3:
            temp.mass = static_cast<float> (inputDouble("Specify a new Element Mass: ", true));
            break;
        case 4:
            temp.stateType = inputChar("Specify a new Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU"));
            break;
        case 5:
            temp.groupNum = inputInteger("Specify a new Element Group # (0-unknown or 1...18) : ", 0, 18);
            break;
        case 6:
            temp.blockType = inputChar("Specify a new Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF"));
            break;
        case 7:
            temp.periodNum = inputInteger("Specify a new Element Period # (0-unknown or 1...7) : ", 0, 7);
            break;
        case 8:
            temp.meltingPoint = inputDouble("Specify the Element Melting Point (celsius degree) : ");
            break;
        case 9:
            temp.boilingPoint = inputDouble("Specify the Element Boiling Point (celsius degree) : ");
            break;
        case 10:
            temp.discoveryYear = static_cast <short> (inputInteger("Specify the Element Discovery Year : ", 0, 2025));
            break;
        case 11:
            strncpy_s(temp.discoveredBy, inputString("Specify the Element Discovered By : ", true).c_str(), sizeof(temp.discoveredBy) - 1);
            break;
        }

    } while (true);

}

void sectionA_elementSearch(Element element, fstream& binaryFile, string fileBin, int count)
{

    cout << "\nCONFIRMATION: The Element with Atomic # (" << element.atomicNum << ") is found at location #" << count << "\n";

}

void sectionA()
{
    fstream binaryFile; // only reads data from file; File Stream Object
    Element element;
    string fileBin;
    long recNum = 0;

    do
    {
        system("cls"); //clears the screen
        cout << "\n\t Option A: Advanced Binary File Menu";
        cout << "\n\t" << string(80, '=');
        cout << "\n\t1) Retrieve and display ALL element(s) from a binary data file";
        cout << "\n\t2) Add a new element to the binary data file";
        cout << "\n\t3) Update an existing element from the binary data file";
        cout << "\n\t4) Search for an element by atomic # from the binary data file"; //stats at pg 697
        cout << "\n\t" << string(80, '-');
        cout << "\n\t0) Return to main menu";

        switch (inputInteger("\tOption: ", 0, 4))
        {
        case 0: return;
        case 1:
            system("cls"); //clears the screen

            fileBin = inputString("\nSpecify a valid binary data file name to retrieve data from: ", false);
            binaryFile.open(fileBin, ios::in | ios::binary);
            if (!binaryFile)
            {
                cout << "ERROR: File, " << fileBin << ", cannot be found.\n";
            }
            else
            {
                sectionA_fileElementDisplay(binaryFile);
            }
            binaryFile.close();
            break;
        case 2:
            system("cls"); //clears the screen
            cout << "Directly add an element into the binary data file... \n";

            binaryFile.open(fileBin, ios::in | ios::out | ios::binary | ios::app);
            if (fileBin.empty())
            {
                cout << "\nERROR: Binary Data file has NOT been specified from Option #1. Please re-perform Option #1. \n\n";
            }
            else
            {
                system("cls"); //clears the screen
                cout << "Adding a new element information\n\n";
                recNum = static_cast <long> (inputInteger("Specify the Atomic # : ", 1, 118));
                binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
                bool findNum = false;

                while (!binaryFile.eof())
                {
                    if (recNum == element.atomicNum)
                    {
                        //sectionA_addElement(element, binaryFile, fileBin, recNum);
                        findNum = true;
                        cout << "\n ERROR: Cannot add a new Element with Atomic # (" << recNum << ") that is already existed. Please perform other valid Options.\n\n";
                        break;
                    }


                    binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));

                }
                binaryFile.close();

                binaryFile.open(fileBin, ios::out | ios::binary | ios::app);
                if (findNum == false)
                {
                    sectionA_addElement(binaryFile, fileBin, recNum);
                }
            }
            binaryFile.close();
            break;
        case 3:
            system("cls");
            cout << "Updating an element in the binary data file... \n\n";

            if (fileBin.empty())
            {
                cout << "\nERROR: Binary Data file has NOT been specified from Option #1. Please re-perform Option #1. \n\n";
            }
            else
            {
                binaryFile.open(fileBin, ios::in | ios::out | ios::binary);
                recNum = static_cast<long>(inputInteger("Specify the Element Atomic # to be updated: "));
                binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
                bool isFound = false;
                int count = 0;

                while (!binaryFile.eof())
                {
                    if (recNum == element.atomicNum)
                    {
                        binaryFile.seekg(count * sizeof(element), ios::beg);
                        binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
                        sectionA_updateElement(element, binaryFile, fileBin, recNum, count); //12.6 pg.686-688
                        isFound = true;
                        break;
                    }

                    binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
                    count++;
                }

                if (isFound == false)
                {
                    cout << "\n ERROR: Cannot find the Element with Atomic # (" << recNum << "). Please perform other valid option.\n\n";
                }
            }
            binaryFile.close();
            break;
        case 4:
            system("cls");
            cout << "Searching an element located in the binary data file...\n";

            binaryFile.open(fileBin, ios::in | ios::out | ios::binary);
            if (fileBin.empty())
            {
                cout << "\nERROR: Binary Data file has NOT been specified from Option #1. Please re-perform Option #1. \n\n";
            }
            else
            {
                recNum = static_cast<long>(inputInteger("Specify the Element Atomic # to be searched : "));
                binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
                bool isFound = false;
                int count = 0;

                while (!binaryFile.eof())
                {

                    if (recNum == element.atomicNum)
                    {
                        sectionA_elementSearch(element, binaryFile, fileBin, count);
                        isFound = true;
                    }

                    binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
                    count++;
                }

                if (isFound == false)
                {
                    cout << "\n ERROR: Cannot find the Element with Atomic # (" << recNum << "). Please perform other valid option.\n\n";

                }


            }
            binaryFile.close();
            break;
        }

        system("pause");
    } while (true);

}

