
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include "input.h"
#include <windows.h>

//struct allison used Element alex uses element
// for members allison uses element and alex uses elements

using namespace std;

//prototypes
void sectionA(); 
void sectionB();
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



// Function to set console color
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printElement(int atomicNum, string symbol, int color)
{
    setColor(color);
    cout << "[ " << setw(3) << atomicNum << "-" << left << setw(3) << symbol << " ]";
    setColor(7); // Reset to default color

}

// Function to print the periodic table
void printPeriodicTable()
{
    cout << "+" << string(206, '-') << "+" << endl;
    cout << "|" << string(50, ' ') << "Periodic Table of Elements by Atomic Number & Symbol (colors 5 pts Xtra credits)" << string(76, ' ') << "|" << endl;

    // row 1
    cout << "|" << string(3, ' ');
    printElement(1, "H", 1); // 1 = blue
    printElement(2, "He", 12); // 12 = light red
    cout << string(181, ' ') << "|" << endl;

    // row 2
    cout << "|" << string(3, ' ');
    printElement(3, "Li", 11); // 11 = light cyan
    printElement(4, "Be", 12);
    cout << string(114, ' ');
    printElement(5, "B", 14);  // 14 = yellow
    printElement(6, "C", 1);
    printElement(7, "N", 1);
    printElement(8, "O", 1);
    printElement(9, "F", 1);
    printElement(10, "Ne", 12);
    cout << string(1, ' ') << "|" << endl;

    //row3
    cout << "|" << string(3, ' ');
    printElement(11, "Na", 11);
    printElement(12, "Mg", 12);
    cout << string(114, ' ');
    printElement(13, "Al", 2); //2 = green
    printElement(14, "Si", 14);
    printElement(15, "P", 1);
    printElement(16, "S", 1);
    printElement(17, "Cl", 1);
    printElement(18, "Ar", 12);
    cout << string(1, ' ') << "|" << endl;

    //row4
    cout << "|" << string(3, ' ');
    printElement(19, "K", 11);
    printElement(20, "Ca", 12);
    printElement(21, "Sc", 13); //13 = light magenta
    cout << string(4, ' ');
    printElement(22, "Ti", 13);
    printElement(23, "V", 13);
    printElement(24, "Cr", 13);
    printElement(25, "Mn", 13);
    printElement(26, "Fe", 13);
    printElement(27, "Co", 13);
    printElement(28, "Ni", 13);
    printElement(29, "Cu", 13);
    printElement(30, "Zn", 13);
    printElement(31, "Ga", 2);
    printElement(32, "Ge", 14);
    printElement(33, "As", 14);
    printElement(34, "Se", 1);
    printElement(35, "Br", 1);
    printElement(36, "Kr", 12);
    cout << string(1, ' ') << "|" << endl;

    //row5
    cout << "|" << string(3, ' ');
    printElement(37, "Rb", 11);
    printElement(38, "Sr", 12);
    printElement(39, "Y", 13);
    cout << string(4, ' ');
    printElement(40, "Zr", 13);
    printElement(41, "Nb", 13);
    printElement(42, "Mo", 13);
    printElement(43, "Tc", 13);
    printElement(44, "Ru", 13);
    printElement(45, "Rh", 13);
    printElement(46, "Pd", 13);
    printElement(47, "Ag", 13);
    printElement(48, "Cd", 13);
    printElement(49, "In", 2);
    printElement(50, "Sn", 2);
    printElement(51, "Sb", 14);
    printElement(52, "Te", 14);
    printElement(53, "I", 1);
    printElement(54, "Xe", 12);
    cout << string(1, ' ') << "|" << endl;

    //row6
    cout << "|" << string(3, ' ');
    printElement(55, "Cs", 11);
    printElement(56, "Ba", 12);
    printElement(57, "La", 11);
    cout << "---" << "+";
    printElement(72, "Hf", 13);
    printElement(73, "Ta", 13);
    printElement(74, "W", 13);
    printElement(75, "Re", 13);
    printElement(76, "Os", 13);
    printElement(77, "Ir", 13);
    printElement(78, "Pt", 13);
    printElement(79, "Au", 13);
    printElement(80, "Hg", 13);
    printElement(81, "Tl", 2);
    printElement(82, "Pb", 2);
    printElement(83, "Bi", 2);
    printElement(84, "Po", 2);
    printElement(85, "At", 2);
    printElement(86, "Rn", 12);
    cout << string(1, ' ') << "|" << endl;


    // Row 7 (with "corner" connection from Ra to Ac)
    cout << "|" << string(3, ' ');
    printElement(87, "Fr", 11);
    printElement(88, "Ra", 12);
    printElement(89, "Ac", 12);
    cout << "-" << "+";
    cout << string(1, ' ') << "|";
    printElement(104, "Rf", 13);
    printElement(105, "Db", 13);
    printElement(106, "Sg", 13);
    printElement(107, "Bh", 13);
    printElement(108, "Hs", 13);
    printElement(109, "Mt", 8);
    printElement(110, "Ds", 8);
    printElement(111, "Rg", 8);
    printElement(112, "Cn", 8);
    printElement(113, "Nh", 8);
    printElement(114, "Fl", 8);
    printElement(115, "Mc", 8);
    printElement(116, "Lv", 8);
    printElement(117, "Ts", 8);
    printElement(118, "Og", 8);
    cout << string(1, ' ') << "|" << endl;

    //row8
    cout << "|" << string(37, ' ') << "| |";
    cout << string(166, ' ') << "|" << endl;

    //row9
    cout << "|" << string(37, ' ') << "| +-";
    printElement(58, "Ce", 11);
    printElement(59, "Pr", 11);
    printElement(60, "Nd", 11);
    printElement(61, "Pm", 11);
    printElement(62, "Sm", 11);
    printElement(63, "Eu", 11);
    printElement(64, "Gd", 11);
    printElement(65, "Tb", 11);
    printElement(66, "Dy", 11);
    printElement(67, "Ho", 11);
    printElement(68, "Er", 11);
    printElement(69, "Tm", 11);
    printElement(70, "Yb", 11);
    printElement(71, "Lu", 11);
    cout << string(11, ' ') << "|" << endl;

    //row10
    cout << "|" << string(37, ' ') << "+---";
    printElement(90, "Th", 2);
    printElement(91, "Pa", 2);
    printElement(92, "U", 2);
    printElement(93, "Np", 2);
    printElement(94, "Pu", 2);
    printElement(95, "Am", 2);
    printElement(96, "Cm", 2);
    printElement(97, "Bk", 2);
    printElement(98, "Cf", 2);
    printElement(99, "Es", 2);
    printElement(100, "Fm", 2);
    printElement(101, "Md", 2);
    printElement(102, "No", 2);
    printElement(103, "Lr", 2);
    cout << string(11, ' ') << "|";

    //last row
    cout << endl;
    cout << "+" << string(206, '-') << "+" << endl;
}



int main()
{

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    do
    {
        //system("cls");
        printPeriodicTable(); //displays the periodic table title
        cout << "\n\tCMPR121: Exam#1: Implementation using Dynamic Array, string/C-string, struct, and Binary File By YOURNAME ";
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
        case 'B': sectionB(); break;
        //case 'C': sectionC(); break;
             /* case 'X': xTraCredit(); break; */

        default:
            SetConsoleTextAttribute(color, 12);
            cout << "\n\tERROR: Invalid option.\n";
            SetConsoleTextAttribute(color, 15);
        }
        cout << "\n\n\t";
        system("pause");
    } while (true);

    return 0;
}


void displayAllElements(Element element)
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
    cout << "\n\tAtomic # " << right << setw(8) << ": " << element.atomicNum;
    cout << "\n\tSymbol " << right << setw(10) << ": " << element.symbol;
    cout << "\n\tName " << right << setw(12) << ": " << element.name;
    cout << "\n\tMass " << right << setw(12) << setprecision(3) << ": " << element.mass << " u";
    cout << "\n\tState type " << right << setw(6) << ": " << element.stateType;
    cout << "\n\tGroup # " << right << setw(9) << setprecision(1) << ": " << element.groupNum;
    cout << "\n\tPeriod # " << right << setw(8) << ": " << element.periodNum;
    cout << "\n\tBlock type " << right << setw(7) << ": (" << block << ") " << blockTypeName;
    cout << "\n\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << element.meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K";
    cout << "\n\tBoiling point " << right << setw(3) << ": " << element.boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K";
    cout << "\n\tDiscovery year " << right << setw(2) << ": ";
    if (element.discoveryYear == 0)
    {
        cout << "Prehistoric";
    }
    else
    {
        cout << element.discoveryYear;
    }
    cout << "\n\tDiscovered by " << right << setw(3) << ": " << element.discoveredBy << "\n\n";
    SetConsoleTextAttribute(color, 15);
}


void sectionA_fileElementDisplay(fstream& binaryFile)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    Element element; //holds information about an element

    long numBytes;
    int count = 0;

    // loops through every record found in the file
    while (binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element)))
    {
        displayAllElements(element);
        count++;
    }

    binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
    SetConsoleTextAttribute(color, 2);
    cout << "\n\tCONFIRMATION: " << count << " record(s) found. \n\n";
    SetConsoleTextAttribute(color, 15);
}

void sectionA_addElement(fstream& binaryFile, string fileBin, long atomicNum)
{
    Element element;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    element.atomicNum = static_cast <short> (atomicNum);
    strncpy_s(element.symbol, inputString("\tSpecify the Element Symbol: ", false).c_str(), sizeof(element.symbol) - 1);
    strncpy_s(element.name, inputString("\tSpecify the Element Name: ", false).c_str(), sizeof(element.name) - 1);
    element.mass = static_cast<float> (inputDouble("\tSpecify the Element Mass: ", true));
    element.stateType = inputChar("\tSpecify the Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU"));
    element.groupNum = inputInteger("\tSpecify the Element Group # (0-unknown or 1...18) : ", 0, 18);
    element.periodNum = inputInteger("\tSpecify the Element Period # (0-unknown or 1...7) : ", 0, 7);
    element.blockType = inputChar("\tSpecify the Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF"));
    element.meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) : ");
    element.boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) : ");
    element.discoveryYear = static_cast <short> (inputInteger("\tSpecify the Element Discovery Year : ", 0, 2025));
    strncpy_s(element.discoveredBy, inputString("\tSpecify the Element Discovered By : ", true).c_str(), sizeof(element.discoveredBy) - 1);

    binaryFile.write(reinterpret_cast<char*> (&element), sizeof(element));
    SetConsoleTextAttribute(color, 2);
    cout << "\n\tCONFIRMATION: A new element with Atomic # (" << element.atomicNum << ") has been added / appended into the binary data file, " << fileBin << " \n";
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
        displayAllElements(temp);
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
            cout << "\n\tCONFIRMATION: Element with Atomic # (" << recNum << ") has been updated into the binary data file," << fileBin << "\n\n";
            SetConsoleTextAttribute(color, 15);
            return;
        case -1:
            temp = { 0 };
            SetConsoleTextAttribute(color, 0x0E);
            cout << "\n\tWARNING: No update was commited.\n\n";
            SetConsoleTextAttribute(color, 0x07);
            return;
        case 1:
            strncpy_s(temp.symbol, inputString("\n\tSpecify a new Element Symbol: ", false).c_str(), sizeof(temp.symbol) - 1);
            break;
        case 2:
            strncpy_s(temp.name, inputString("\n\tSpecify a new Element Name: ", false).c_str(), sizeof(temp.name) - 1);
            break;
        case 3:
            temp.mass = static_cast<float> (inputDouble("\n\tSpecify a new Element Mass: ", true));
            break;
        case 4:
            temp.stateType = inputChar("\n\tSpecify a new Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU"));
            break;
        case 5:
            temp.groupNum = inputInteger("\n\tSpecify a new Element Group # (0-unknown or 1...18) : ", 0, 18);
            break;
        case 6:
            temp.blockType = inputChar("\n\tSpecify a new Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF"));
            break;
        case 7:
            temp.periodNum = inputInteger("\n\tSpecify a new Element Period # (0-unknown or 1...7) : ", 0, 7);
            break;
        case 8:
            temp.meltingPoint = inputDouble("\n\tSpecify the new Element Melting Point (celsius degree) : ");
            break;
        case 9:
            temp.boilingPoint = inputDouble("\n\tSpecify the new Element Boiling Point (celsius degree) : ");
            break;
        case 10:
            temp.discoveryYear = static_cast <short> (inputInteger("\n\tSpecify the new Element Discovery Year : ", 0, 2025));
            break;
        case 11:
            strncpy_s(temp.discoveredBy, inputString("\n\tSpecify the new Element Discovered By : ", true).c_str(), sizeof(temp.discoveredBy) - 1);
            break;
        }

    } while (true);

}

void sectionA_elementSearch(Element element, fstream& binaryFile, string fileBin, int count)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(color, 2);
    cout << "\n\tCONFIRMATION: The Element with Atomic # (" << element.atomicNum << ") is found at location #" << count << "\n\n";
    SetConsoleTextAttribute(color, 15);

}

void sectionA()
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
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


        cout << "\n\t" << string(80, '=');
        switch (inputInteger("\n\tOption: ", 0, 4))
        {
        case 0: //professor has it clear screen and display main screen 
            system("cls"); //clears the screen but is showing press any key at top needs fixing
            return;
        case 1:
            system("cls"); //clears the screen

            fileBin = inputString("\n\tSpecify a valid binary data file name to retrieve data from: ", false);
            binaryFile.open(fileBin, ios::in | ios::binary);
            if (!binaryFile)
            {
                SetConsoleTextAttribute(color, 12);
                cout << "\n\tERROR: File, " << fileBin << ", cannot be found.\n\n";
                SetConsoleTextAttribute(color, 15);
            }
            else
            {
                sectionA_fileElementDisplay(binaryFile);
            }
            binaryFile.close();
            break;
        case 2:
            system("cls"); //clears the screen
            cout << "\tDirectly add an element into the binary data file... \n\n";

            binaryFile.open(fileBin, ios::in | ios::out | ios::binary | ios::app);
            if (fileBin.empty())
            {
                SetConsoleTextAttribute(color, 12);
                cout << "\n\tERROR: Binary Data file has NOT been specified from Option #1. Please re-perform Option #1. \n\n";
                SetConsoleTextAttribute(color, 15);
            }
            else
            {
                cout << "\n\tAdding a new element information\n\n";
                recNum = static_cast <long> (inputInteger("\n\tSpecify the Atomic # : ", 1, 118));
                binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element));
                bool findNum = false;

                while (!binaryFile.eof())
                {
                    if (recNum == element.atomicNum)
                    {
                        findNum = true;
                        SetConsoleTextAttribute(color, 12);
                        cout << "\n\tERROR: Cannot add a new Element with Atomic # (" << recNum << ") that is already existed. Please perform other valid Options.\n\n";
                        SetConsoleTextAttribute(color, 15);
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
            cout << "\n\tUpdating an element in the binary data file... \n\n";

            if (fileBin.empty())
            {
                SetConsoleTextAttribute(color, 12);
                cout << "\n\tERROR: Binary Data file has NOT been specified from Option #1. Please re-perform Option #1. \n\n";
                SetConsoleTextAttribute(color, 15);
            }
            else
            {
                binaryFile.open(fileBin, ios::in | ios::out | ios::binary);
                recNum = static_cast<long>(inputInteger("\tSpecify the Element Atomic # to be updated: "));
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
                    SetConsoleTextAttribute(color, 12);
                    cout << "\n\tERROR: Cannot find the Element with Atomic # (" << recNum << "). Please perform other valid option.\n\n";
                    SetConsoleTextAttribute(color, 15);
                }
            }
            binaryFile.close();
            break;
        case 4:
            system("cls");
            cout << "\n\tSearching an element located in the binary data file...\n\n";

            binaryFile.open(fileBin, ios::in | ios::out | ios::binary);
            if (fileBin.empty())
            {
                SetConsoleTextAttribute(color, 12);
                cout << "\n\tERROR: Binary Data file has NOT been specified from Option #1. Please re-perform Option #1. \n\n";
                SetConsoleTextAttribute(color, 15);
            }
            else
            {
                recNum = static_cast<long>(inputInteger("\tSpecify the Element Atomic # to be searched : "));
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
                    SetConsoleTextAttribute(color, 12);
                    cout << "\n\tERROR: Cannot find the Element with Atomic # (" << recNum << "). Please perform other valid option.\n\n";
                    SetConsoleTextAttribute(color, 15);

                }


            }
            binaryFile.close();
            break;
        }

        system("pause");
    } while (true);

}


void sectionB()
{
    do
    {
        system("cls"); //clears the screen
        cout << "\n\t Option B: Dynamic Array";
        cout << "\n\t" << string(80, '=');
        cout << "\n\t1) Read element(s) from the binary data file and store into the dynamic array";
        cout << "\n\t2) Display element(s) from the dynamic array";
        cout << "\n\t3) Add a new chemistry element into the dynamic array";
        cout << "\n\t4) Update an existing chemistry element from the dynamic array";
        cout << "\n\t5) Sort the dynamic array by Symbol in descending order";
        cout << "\n\t6) Binary search an element by Symbol";
        cout << "\n\t7) Write elements from the dynamic array to the binary data file.";
        cout << "\n\t" << string(80, '-');
        cout << "\n\t0) Return to main menu";

        switch (inputInteger("\tOption: ", 0, 7))
        {
        case 0: return;
        case 1:
           // sectionB1(); //combining allisons and alex's code
            break;
        case 2:
          //  sectionB_displayElement();
            break;
        case 3:
           // sectionB_addElement();
            break;
        case 4:
           // sectionB_updateElement();
            break;
        case 5:
           // sectionB_sortbySymbol();
            break;
        case 6:
           // sectionB_binarySearchSymbol();
            break;
        case 7:
           // sectionB_arraytoFile();
            break;
        }

        system("pause");
    } while (true);
} 
/*
int sectionB1(Element*& element, int& SIZE)
{
    system("cls");
    Element item; //alex has element item

    //prompt user for the file
    string fileNamePrompt = inputString("\n\tSpecify the binary file name to read from: ", false);

    ifstream myDataFileB1(fileNamePrompt, ios::binary);

    if (!myDataFileB1.is_open())
    {
        cout << "\n\tERROR: FILE " << fileNamePrompt << " CANNOT BE FOUND.";
        //set color to red
        return 1;

    }


    //here is my new dynamic array 
    element = new Element[SIZE];

    if (element == nullptr)
        cout << "Mem check ";

    myDataFileB1.seekg(0, ios::beg); // back to the start 

   
    myDataFileB1.read(reinterpret_cast<char*>(element), SIZE * sizeof(Element));



}
*/