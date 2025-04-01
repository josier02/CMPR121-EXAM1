
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

//for struct allison used Element alex uses element
//im going to leave comment lines like this "//" on lines where alex just needs to adjust to his names when he copies this main
//alex uses optionA,B,C allison uses sectionA,B,C

//allison uses  SetConsoleTextAttribute(color, 12); where I use setColor(12); you guys can decide which you wanna use
//for mine you dont need to have the changed input header, the professors copy works fine just add the appropriate void set color funciton

using namespace std;

//prototypes
void sectionA(); //optionA();
void sectionB(); //optionB();
void sectionC(); //optionC();
//void xTraCredit();

struct Element //struct element
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
        system("cls");
        printPeriodicTable(); //displays the periodic table title
        cout << "\n\tCMPR121: Exam#1: Implementation using Dynamic Array, string/C-string, struct, and Binary File By YOURNAME "; //make sure to change to your name
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t A) Advance Binary Data File (Chapter#12)";
        cout << "\n\t B) Dynamic Array (Chapter#9)";
        cout << "\n\t C) Vector (Chapter#7)";
        cout << "\n\t X) Xtra credits (5 pts)";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t Q) Quit (terminate) Program";
        cout << "\n\t" << string(100, char(205));
        cout << "\n";

        switch (toupper(inputChar("\n\tOption: ", static_cast<string>("QABCX"))))
        {
        case 'Q': exit(0);
        case 'A': sectionA(); break; //optionA(); break;
        case 'B': sectionB(); break; //optionB(); break;
        case 'C': sectionC(); break; //optionC(); break;
        //case 'X': xTraCredit(); break; 
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

void displayAllElements(Element element) //void displayAllElements(element elements)
{
    float kelvinm = 0.0;
    float farenheitm = 0.0;
    float kelvinb = 0.0;
    float farenheitb = 0.0;
    string blockTypeName = "unknown";
    char block = toupper(element.blockType); //char block = toupper(elements.blockType);
    string discoveryYear;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    kelvinm = element.meltingPoint + 273.15; //kelvinm = elements.meltingPoint + 273.15;
    farenheitm = (element.meltingPoint * 1.8) + 32; //farenheitm = (elements.meltingPoint * 1.8) + 32;

    kelvinb = element.boilingPoint + 273.15; //kelvinb = elements.boilingPoint + 273.15;
    farenheitb = (element.boilingPoint * 1.8) + 32; //farenheitb = (elements.boilingPoint * 1.8) + 32;

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
    cout << "\n\tAtomic # " << right << setw(8) << ": " << element.atomicNum; //cout << "\tAtomic # " << right << setw(8) << ": " << elements.atomicNum << "\n";
    cout << "\n\tSymbol " << right << setw(10) << ": " << element.symbol; //cout << "\tSymbol " << right << setw(10) << ": " << elements.symbol << "\n";
    cout << "\n\tName " << right << setw(12) << ": " << element.name; //cout << "\tName " << right << setw(12) << ": " << elements.name << "\n";
    cout << "\n\tMass " << right << setw(12) << setprecision(3) << ": " << element.mass << " u"; //cout << "\tMass " << right << setw(12) << setprecision(3) << ": " << elements.mass << " u\n";
    cout << "\n\tState type " << right << setw(6) << ": " << element.stateType; //cout << "\tState type " << right << setw(6) << ": " << elements.stateType << "\n";
    cout << "\n\tGroup # " << right << setw(9) << setprecision(1) << ": " << element.groupNum; //cout << "\tGroup # " << right << setw(9) << setprecision(1) << ": " << elements.groupNum << "\n";
    cout << "\n\tPeriod # " << right << setw(8) << ": " << element.periodNum; //cout << "\tPeriod # " << right << setw(8) << ": " << elements.periodNum << "\n";
    cout << "\n\tBlock type " << right << setw(7) << ": (" << block << ") " << blockTypeName;
    cout << "\n\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << element.meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K"; //out << "\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << elements.meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n";
    cout << "\n\tBoiling point " << right << setw(3) << ": " << element.boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K"; //cout << "\tBoiling point " << right << setw(3) << ": " << elements.boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n";
    cout << "\n\tDiscovery year " << right << setw(2) << ": ";
    if (element.discoveryYear == 0) //if (elements.discoveryYear == 0)
    {
        cout << "Prehistoric" << "\n";
    }
    else
    {
        cout << element.discoveryYear << "\n"; //cout << elements.discoveryYear << "\n";
    }
    cout << "\n\tDiscovered by " << right << setw(3) << ": " << element.discoveredBy << "\n\n"; //cout << "\n\tDiscovered by " << right << setw(3) << ": " << elements.discoveredBy << "\n\n";
    SetConsoleTextAttribute(color, 15);
}


void displayAllElements(Element element[], int size) //void displayAllElements(element elements [], int size)
{
    for (int i = 0; i < size; i++)
    {
        float kelvinm = 0.0;
        float farenheitm = 0.0;
        float kelvinb = 0.0;
        float farenheitb = 0.0;
        string blockTypeName = "unknown";
        char block = toupper(element[i].blockType); //char block = toupper(elements[i].blockType);
        string discoveryYear;
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

        kelvinm = element[i].meltingPoint + 273.15; //kelvinm = elements[i].meltingPoint + 273.15;
        farenheitm = (element[i].meltingPoint * 1.8) + 32; //farenheitm = (elements[i].meltingPoint * 1.8) + 32;

        kelvinb = element[i].boilingPoint + 273.15; //kelvinb = elements[i].boilingPoint + 273.15;
        farenheitb = (element[i].boilingPoint * 1.8) + 32; //farenheitb = (elements[i].boilingPoint * 1.8) + 32;


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
        cout << "\tAtomic # " << right << setw(8) << ": " << element[i].atomicNum << "\n"; //farenheitb = (elements[i].boilingPoint * 1.8) + 32;
        cout << "\tSymbol " << right << setw(10) << ": " << element[i].symbol << "\n"; //cout << "\tSymbol " << right << setw(10) << ": " << elements[i].symbol << "\n";
        cout << "\tName " << right << setw(12) << ": " << element[i].name << "\n"; //cout << "\tName " << right << setw(12) << ": " << elements[i].name << "\n";
        cout << "\tMass " << right << setw(12) << setprecision(3) << ": " << element[i].mass << " u\n"; //cout << "\tMass " << right << setw(12) << setprecision(3) << ": " << elements[i].mass << " u\n";
        cout << "\tState type " << right << setw(6) << ": " << element[i].stateType << "\n"; //cout << "\tState type " << right << setw(6) << ": " << elements[i].stateType << "\n";
        cout << "\tGroup # " << right << setw(9) << setprecision(1) << ": " << element[i].groupNum << "\n"; //cout << "\tGroup # " << right << setw(9) << setprecision(1) << ": " << elements[i].groupNum << "\n";
        cout << "\tPeriod # " << right << setw(8) << ": " << element[i].periodNum << "\n"; // cout << "\tPeriod # " << right << setw(8) << ": " << elements[i].periodNum << "\n";
        cout << "\tBlock type " << right << setw(7) << ": (" << block << ") " << blockTypeName << "\n";
        cout << "\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << element[i].meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n"; //cout << "\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << elements[i].meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n";
        cout << "\tBoiling point " << right << setw(3) << ": " << element[i].boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n"; //cout << "\tBoiling point " << right << setw(3) << ": " << elements[i].boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n";
        cout << "\tDiscovery year " << right << setw(2) << ": "; 
        if (element[i].discoveryYear == 0) //if (elements[i].discoveryYear == 0)
        {
            cout << "\tPrehistoric" << "\n";
        }
        else
        {
            cout << element[i].discoveryYear << "\n"; //cout << elements[i].discoveryYear << "\n";
        }
        cout << "\tDiscovered by " << right << setw(3) << ": " << element[i].discoveredBy << "\n\n"; //cout << "\tDiscovered by " << right << setw(3) << ": " << elements[i].discoveredBy << "\n\n";
        SetConsoleTextAttribute(color, 15);
    }
}

void displayAllElements(const vector<Element>& element) //void displayAllElements(const vector<element>& elements)
{
    for (size_t i = 0; i < element.size(); i++) //for (size_t i = 0; i < elements.size(); i++)
    {
        float kelvinm = 0.0;
        float farenheitm = 0.0;
        float kelvinb = 0.0;
        float farenheitb = 0.0;
        string blockTypeName = "unknown";
        char block = toupper(element[i].blockType); //char block = toupper(elements[i].blockType);
        string discoveryYear;
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

        kelvinm = element[i].meltingPoint + 273.15;//kelvinm = elements[i].meltingPoint + 273.15;
        farenheitm = (element[i].meltingPoint * 1.8) + 32; //farenheitm = (elements[i].meltingPoint * 1.8) + 32;

        kelvinb = element[i].boilingPoint + 273.15; //kelvinb = elements[i].boilingPoint + 273.15;
        farenheitb = (element[i].boilingPoint * 1.8) + 32; // farenheitb = (elements[i].boilingPoint * 1.8) + 32;

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
        cout << "\tAtomic # " << right << setw(8) << ": " << element[i].atomicNum << "\n"; //cout << "\tAtomic # " << right << setw(8) << ": " << elements[i].atomicNum << "\n";
        cout << "\tSymbol " << right << setw(10) << ": " << element[i].symbol << "\n"; //cout << "\tSymbol " << right << setw(10) << ": " << elements[i].symbol << "\n";
        cout << "\tName " << right << setw(12) << ": " << element[i].name << "\n"; //cout << "\tName " << right << setw(12) << ": " << elements[i].name << "\n";
        cout << "\tMass " << right << setw(12) << setprecision(3) << ": " << element[i].mass << " u\n"; //cout << "\tMass " << right << setw(12) << setprecision(3) << ": " << elements[i].mass << " u\n";
        cout << "\tState type " << right << setw(6) << ": " << element[i].stateType << "\n"; //cout << "\tState type " << right << setw(6) << ": " << elements[i].stateType << "\n";
        cout << "\tGroup # " << right << setw(9) << setprecision(1) << ": " << element[i].groupNum << "\n"; //cout << "\tState type " << right << setw(6) << ": " << elements[i].stateType << "\n";
        cout << "\tPeriod # " << right << setw(8) << ": " << element[i].periodNum << "\n"; //cout << "\tPeriod # " << right << setw(8) << ": " << elements[i].periodNum << "\n";
        cout << "\tBlock type " << right << setw(7) << ": (" << block << ") " << blockTypeName << "\n";
        cout << "\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << element[i].meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n"; //cout << "\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << elements[i].meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n";
        cout << "\tBoiling point " << right << setw(3) << ": " << element[i].boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n"; //cout << "\tBoiling point " << right << setw(3) << ": " << elements[i].boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n";
        cout << "\tDiscovery year " << right << setw(2) << ": ";
        if (element[i].discoveryYear == 0) //if (elements[i].discoveryYear == 0)
        {
            cout << "\tPrehistoric" << "\n";
        }
        else
        {
            cout << element[i].discoveryYear << "\n"; //cout << elements[i].discoveryYear << "\n";
        }
        cout << "\tDiscovered by " << right << setw(3) << ": " << element[i].discoveredBy << "\n\n"; //cout << "\tDiscovered by " << right << setw(3) << ": " << elements[i].discoveredBy << "\n\n";
        SetConsoleTextAttribute(color, 15);
    }
}

void sectionA_fileElementDisplay(fstream& binaryFile)
{
    system("cls"); //clears the screen
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    Element element; //holds information about an element //element elements;

    long numBytes;
    int count = 0;

    // loops through every record found in the file
    while (binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element))) //while (binaryFile.read(reinterpret_cast<char*>(&elements), sizeof(elements)))
    {
        displayAllElements(element); //displayAllElements(elements);
        count++;
    }

    binaryFile.read(reinterpret_cast<char*>(&element), sizeof(element)); //binaryFile.read(reinterpret_cast<char*>(&elements), sizeof(elements));
    SetConsoleTextAttribute(color, 2);
    cout << "\n\tCONFIRMATION: " << count << " record(s) found. \n\n";
    SetConsoleTextAttribute(color, 15);
}

void sectionA_addElement(fstream& binaryFile, string fileBin, long atomicNum)
{
    Element element; //element elements;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    element.atomicNum = static_cast <short> (atomicNum); //elements.atomicNum = static_cast <short> (atomicNum);
    strncpy_s(element.symbol, inputString("\tSpecify the Element Symbol: ", false).c_str(), sizeof(element.symbol) - 1); //strncpy_s(elements.symbol, inputString("Specify the Element Symbol: ", false).c_str(), sizeof(elements.symbol) - 1);
    strncpy_s(element.name, inputString("\tSpecify the Element Name: ", false).c_str(), sizeof(element.name) - 1); //strncpy_s(elements.name, inputString("Specify the Element Name: ", false).c_str(), sizeof(elements.name) - 1);
    element.mass = static_cast<float> (inputDouble("\tSpecify the Element Mass: ", true)); //elements.mass = static_cast<float> (inputDouble("Specify the Element Mass: ", true));
    element.stateType = inputChar("\tSpecify the Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU")); //elements.stateType = inputChar("Specify the Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU"));
    element.groupNum = inputInteger("\tSpecify the Element Group # (0-unknown or 1...18) : ", 0, 18); //elements.groupNum = inputInteger("Specify the Element Group # (0-unknown or 1...18) : ", 0, 18);
    element.periodNum = inputInteger("\tSpecify the Element Period # (0-unknown or 1...7) : ", 0, 7); //elements.periodNum = inputInteger("Specify the Element Period # (0-unknown or 1...7) : ", 0, 7);
    element.blockType = inputChar("\tSpecify the Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF")); //elements.blockType = inputChar("Specify the Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF"));
    element.meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) : "); //elements.meltingPoint = inputDouble("Specify the Element Melting Point (celsius degree) : ");
    element.boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) : "); //elements.boilingPoint = inputDouble("Specify the Element Boiling Point (celsius degree) : ");
    element.discoveryYear = static_cast <short> (inputInteger("\tSpecify the Element Discovery Year : ", 0, 2025)); //elements.discoveryYear = static_cast <short> (inputInteger("Specify the Element Discovery Year : ", 0, 2025));
    strncpy_s(element.discoveredBy, inputString("\tSpecify the Element Discovered By : ", true).c_str(), sizeof(element.discoveredBy) - 1); //strncpy_s(elements.discoveredBy, inputString("Specify the Element Discovered By : ", true).c_str(), sizeof(elements.discoveredBy) - 1);

    binaryFile.write(reinterpret_cast<char*> (&element), sizeof(element)); //binaryFile.write(reinterpret_cast<char*> (&elements), sizeof(elements));
    SetConsoleTextAttribute(color, 2);
    cout << "\n\tCONFIRMATION: A new element with Atomic # (" << element.atomicNum << ") has been added / appended into the binary data file, " << fileBin << " \n"; //cout << "\nCONFIRMATION: A new element with Atomic # (" << elements.atomicNum << ") has been added / appended into the binary data file, " << fileBin << " \n";
    SetConsoleTextAttribute(color, 15);
}


void sectionA_updateElement(Element element, fstream& binaryFile, string fileBin, int recNum, int count) //void sectionA_updateElement(element elements, fstream& binaryFile, string fileBin, int recNum, int count)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    Element temp; //element temp;

    temp = element; //temp = elements;

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
            element = temp; //elements = temp;
            //Writes to specified record
            binaryFile.write(reinterpret_cast<char*>(&element), sizeof(element)); //binaryFile.write(reinterpret_cast<char*>(&elements), sizeof(elements));
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

void sectionA_elementSearch(Element element, fstream& binaryFile, string fileBin, int count) //void sectionA_elementSearch(element elements, fstream& binaryFile, string fileBin, int count)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(color, 2);
    cout << "\n\tCONFIRMATION: The Element with Atomic # (" << element.atomicNum << ") is found at location #" << count << "\n\n"; //cout << "\nCONFIRMATION: The Element with Atomic # (" << elements.atomicNum << ") is found at location #" << count << "\n";
    SetConsoleTextAttribute(color, 15);

}

void sectionA() //void optionA()
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
        cout << "\n\t4) Search for an element by atomic # from the binary data file"; 
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
                system("cls");
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

//alex uses int optionB1(element*& elements, int& SIZE)
int  sectionB_fileReadnStore(Element*& element, int& SIZE) //int optionB1(element*& elements, int& SIZE)
{
    system("cls");
    Element item; //element item;

    //prompt user for the file
    string fileNamePrompt = inputString("\n\tSpecify the binary file name to read from: ", false);

    ifstream myDataFileB1(fileNamePrompt, ios::binary);

    if (!myDataFileB1.is_open())
    {
        setColor(12);
        cout << "\n\tERROR: FILE " << fileNamePrompt << " CANNOT BE FOUND.";
        setColor(15);
        return 1;

    }

   //ask alex about this
    myDataFileB1.seekg(0, ios::end); // this will always move to the end of the file 
    int myDataFileB1Size = myDataFileB1.tellg(); // basically gets the size
   
    SIZE = myDataFileB1Size / sizeof(Element); //SIZE = myDataFileB1Size / sizeof(element);

    element = new Element[SIZE]; //elements = new element[SIZE]

    if (element == nullptr) //if (elements == nullptr)
        cout << "Mem check ";

    myDataFileB1.seekg(0, ios::beg); // back to the start 

    myDataFileB1.read(reinterpret_cast<char*>(element), SIZE * sizeof(Element)); //myDataFileB1.read(reinterpret_cast<char*>(elements), SIZE * sizeof(element));

    if (!myDataFileB1) 
    {
        setColor(12);
        cout << "\n\tERROR READING FILE!" << endl;
        setColor(15);
        myDataFileB1.close();
    }

    myDataFileB1.close();
    setColor(2);
    cout << "\n\tCONFIRMATION: Data from binary file," << fileNamePrompt << "has been retrieved and stored into dynamic array.";
    setColor(15);

    return 0;
}


int sectionB_addElement(Element*& element, int& SIZE) //alex uses int optionB2(Element*& elements, int& SIZE) // maybe not an int
{
    system("cls");
    cout << "\tDisplay ALL element(s) from the dynamic array...\n";


    if (element == nullptr) //if (elements == nullptr)
        cout << "Mem check and or add elements ";

    if (SIZE == 0)
    {
        setColor(12);
        cout << "\n\tERROR: Dynamic array is empty. Therfore, no element can be displayed.";
        setColor(15);
    }
    
    
    displayAllElements(element, SIZE); //displayAllElements(elements, SIZE);
    {
       
        cout << " * Current size of the dynamic array : " << SIZE;

        return 0;
    }
}

    //Adding a new element information to the dynamic array...
    int sectionB_displayElement(Element * &element, int& SIZE) //int optionB3(element*& elements, int& SIZE)
    {
        system("cls");
        cout << "\tAdding a new element information to the dynamic array...\n";

        if (SIZE == 0)
        {
            setColor(0x0E);
            cout << "\n\nWARNING: Dynamic Array is empty. Therefore, a new dynamic array will be created."; 
            setColor(15);
            // this is if they didn't run option1 

            short testAtomicNum = inputInteger("\n\n\tSpecify a new Element Atomic # : ", 1, 118);
            int tempSize = SIZE + 1;
            Element* newElements = new Element[tempSize]; // element* newElements = new element[tempSize]; // new array

            for (int i = 0; i < SIZE; ++i)
            {
                newElements[i] = element[i]; //newElements[i] = elements[i];
            }
            delete[] element; //delete[] elements;


            cout << "\n";
            newElements[SIZE].atomicNum = testAtomicNum;
            strncpy_s(newElements[SIZE].symbol, inputString("\tSpecify the Element Symbol :", boolalpha).c_str(), sizeof(newElements[SIZE].symbol) - 1);
            strncpy_s(newElements[SIZE].name, inputString("\tSpecify the Element Name :", boolalpha).c_str(), sizeof(newElements[SIZE].name) - 1);
            newElements[SIZE].mass = inputDouble("\tSpecify the Element Mass :");
            newElements[SIZE].stateType = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) :", static_cast<string>("slgu"))));
            newElements[SIZE].groupNum = inputInteger("\tSpecify the Element Group # (0 = unknown or 1...18) :", 0, 18);
            newElements[SIZE].periodNum = inputInteger("\tSpecify the Element Period # (0 = unknown or 1...7) :", 0, 7);
            newElements[SIZE].blockType = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) :", static_cast<string>("spdf"))));
            newElements[SIZE].meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) :"); //valdiate& change 
            newElements[SIZE].boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) :"); //validate
            newElements[SIZE].discoveryYear = inputInteger("\tSpecify the Element Discovery Year :", true);
           strncpy_s(newElements[SIZE].discoveredBy, inputString("\tSpecify the Element Discoverred By :", true).c_str(), sizeof(newElements[SIZE].discoveredBy) - 1);

            SIZE++;
            element = newElements; //elements = newElements;

            setColor(2);
            cout << "\n\tCONFIRMATION: A new element with Atomic # (" << testAtomicNum << ") has been added into the dynamic array.";
            setColor(15);

           
            return 0;
        }

        if (SIZE != 0)
        {


            short testAtomicNum = inputInteger("\n\n\tSpecify a new Element Atomic # : ", 1, 118);


            for (int i = 0; i < SIZE; i++)
            {
                if (testAtomicNum == element[i].atomicNum) //if (testAtomicNum == elements[i].atomicNum)
                {
                    setColor(12);
                    cout << "\n\tERROR: Element with Atomic # " << testAtomicNum << " is already existed. Please perform other valid option.";
                    setColor(15);
                    return 1;
                }

            }
                int tempSize = SIZE + 1;
                Element* newElements = new Element[tempSize]; // new array //element* newElements = new element[tempSize]; // new array 

                for (int i = 0; i < SIZE; ++i) 
                {
                    newElements[i] = element[i]; //newElements[i] = elements[i];
                }

                delete[] element; //delete[] elements;


                cout << "\n";
                newElements[SIZE].atomicNum = testAtomicNum;
                //strncpy_s(newElements[SIZE].symbol, sizeof(3), inputString("\tSpecify the Element Symbol :", boolalpha).c_str(), _TRUNCATE);
                strncpy_s(newElements[SIZE].symbol, inputString("\tSpecify the Element Symbol :", boolalpha).c_str(), sizeof(newElements[SIZE].symbol) - 1);
                strncpy_s(newElements[SIZE].name, inputString("\tSpecify the Element Name :", boolalpha).c_str(), sizeof(newElements[SIZE].name) - 1);
                newElements[SIZE].mass = inputDouble("\tSpecify the Element Mass :");
                newElements[SIZE].stateType = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) :", static_cast<string>("slgu"))));
                newElements[SIZE].groupNum = inputInteger("\tSpecify the Element Group # (0 = unknown or 1...18) :", 0, 18);
                newElements[SIZE].periodNum = inputInteger("\tSpecify the Element Period # (0 = unknown or 1...7) :", 0, 7);
                newElements[SIZE].blockType = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) :", static_cast<string>("spdf"))));
                newElements[SIZE].meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) :"); //valdiate& change 
                newElements[SIZE].boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) :"); //validate
                newElements[SIZE].discoveryYear = inputInteger("\tSpecify the Element Discovery Year :", true);
                strncpy_s(newElements[SIZE].discoveredBy, sizeof(100), inputString("\tSpecify the Element Discoverred By :", true).c_str(), sizeof(newElements[SIZE].discoveredBy) - 1);


                SIZE++;
                element = newElements; //elements = newElements;

                setColor(2);
                cout << "\n\tCONFIRMATION: A new element with Atomic # (" << testAtomicNum << ") has been added into the dynamic array.";
                setColor(15);
        }
            return 0;
    }

    
    // prompt user for changes change if need be
    // the display changes as you adjust the element  
    int sectionB_updateElement(Element*& element, int& SIZE) // maybe not an int //optionB4(element*& elements, int& SIZE)
    {
        system("cls");

        cout << "\n\tDirectly Update a chemistry element information from the dynamic array...";

        if (SIZE == 0)
        {
            setColor(12);
            cout << "\n\n\tERROR: Dynamic array is empty and therefore no element can be updated.\n";
            setColor(15);
            return 1;
        }

        bool found = false;
        short a_num = inputInteger("\n\n\tSpecify an existing Element Atomic # :", true);

        for (int i = 0; i < SIZE; i++)
        {
            if (a_num == element[i].atomicNum) //if (a_num == elements[i].atomicNum) //this might need adjustment
            {  
                short atomicNumB = element[i].atomicNum; //short atomicNumB = elements[i].atomicNum;
                char symbolB[3];
                strncpy_s(symbolB, sizeof(symbolB), element[i].symbol, _TRUNCATE); //strncpy_s(symbolB, sizeof(symbolB), elements[i].symbol, _TRUNCATE);
                char nameB[25];
                strncpy_s(nameB, sizeof(nameB), element[i].name, _TRUNCATE); //strncpy_s(nameB, sizeof(nameB), elements[i].name, _TRUNCATE);
                float massB = element[i].mass; //float massB = elements[i].mass;
                char stateTypeB = element[i].stateType; //char stateTypeB = elements[i].stateType;
                short groupNumB = element[i].groupNum; //short groupNumB = elements[i].groupNum;
                short periodNumB = element[i].periodNum; //short periodNumB = elements[i].periodNum;
                char blockTypeB = element[i].blockType; //char blockTypeB = elements[i].blockType;
                float meltingPointB = element[i].meltingPoint; //float meltingPointB = elements[i].meltingPoint;
                float boilingPointB = element[i].boilingPoint; //float boilingPointB = elements[i].boilingPoint;
                short discoveryYearB = element[i].discoveryYear; //short discoveryYearB = elements[i].discoveryYear;
                char discoveredByB[100];
                strncpy_s(discoveredByB, sizeof(discoveredByB), element[i].discoveredBy, _TRUNCATE); //strncpy_s(discoveredByB, sizeof(discoveredByB), elements[i].discoveredBy, _TRUNCATE);
                do
                {
                    float kelvinm = 0.0;
                    float farenheitm = 0.0;
                    float kelvinb = 0.0;
                    float farenheitb = 0.0;
                    string blockTypeName = "unknown";
                    char block = toupper(blockTypeB);
                    string discoveryYear;

                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

                    kelvinm = meltingPointB + 273.15;
                    farenheitm = (meltingPointB * 1.8) + 32;

                    kelvinb = boilingPointB + 273.15;
                    farenheitb = (boilingPointB * 1.8) + 32;

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

                    setColor(2);
                    cout << setw(20) << left << "\n\tAtomic #" << ": " << left << element[i].atomicNum; //cout << setw(20) << left << "\n\tAtomic #" << ": " << left << elements[i].atomicNum;
                    cout << setw(20) << left << "\n\tSymbol " << ": " << left << symbolB; 
                    cout << setw(20) << left << "\n\tName " << ": " << left << nameB;
                    cout << setw(20) << left << "\n\tMass" << ": " << left << massB << " u";
                    cout << setw(20) << left << "\n\tState Type" << ": " << left << stateTypeB;
                    cout << setw(20) << left << "\n\tGroup #" << ": " << left << groupNumB;
                    cout << setw(20) << left << "\n\tPeriod #" << ": " << periodNumB;
                    cout << setw(20) << left << "\n\tBlock Type" << ": (" << block << ") " << blockTypeName;
                    cout << setw(20) << left << setprecision(2) << fixed << "\n\tMelting Point" << ": " << meltingPointB << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K";
                    cout << setw(20) << left << setprecision(2) << fixed << "\n\tBoiling Point" << ": " << boilingPointB << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K";
                    cout << setw(20) << left << "\n\tDiscovery Year" << ": " << discoveryYearB;
                   
                    if (discoveryYearB == 0)
                    {
                        cout << "Prehistoric";
                    }
                    else
                    {
                        cout << discoveryYearB;
                    }
                    cout << setw(20) << left << "\n\tDiscovered by" << ": " << discoveredByB << "\n\n";
                    setColor(15);

                    cout << "\n\tUpdating Element's information...";
                    cout << "\n\t" << string(100, char(205));
                    cout << "\n\t 1)  Symbol";
                    cout << "\n\t 2)  Name";
                    cout << "\n\t 3)  Atomic Mass";
                    cout << "\n\t 4)  State type";
                    cout << "\n\t 5)  Group #";
                    cout << "\n\t 6)  Block Type";
                    cout << "\n\t 7)  Period Type";
                    cout << "\n\t 8)  Melting Point";
                    cout << "\n\t 9)  Boiling Point";
                    cout << "\n\t 10) Discoverred Year";
                    cout << "\n\t 11) Discoverred BY";
                    cout << "\n\t" << string(100, char(205));
                    cout << "\n";
                    cout << "\n\t -1) Return WITHOUT changes(s)";
                    cout << "\n\t  0) Return WITH comitted change(s)";
                    cout << "\n\t" << string(100, char(205));
                    switch (inputInteger("\n\tOption: ", -1, 11))
                    {
                    case -1:
                        setColor(0x0E);
                        cout << "\nWarning: No update was committed.\n\n"; 
                        setColor(15);
                        return 0;
                        
                    case 1:strncpy_s(symbolB, inputString("\tSpecify the Element Symbol :", boolalpha).c_str(), sizeof(symbolB) - 1); break;

                    case 2:strncpy_s(nameB, sizeof(nameB), inputString("\tSpecify the Element Name :", boolalpha).c_str(), _TRUNCATE); break;

                    case 3: massB = inputDouble("\tSpecify the Element Mass :"); break;

                    case 4: stateTypeB = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) :", static_cast<string>("slgu"))));; break; 

                    case 5: groupNumB = inputInteger("\tSpecify the Element Group # (0 = unknown or 1...18) :", 0, 18); break; 

                    case 6: blockTypeB = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) :", static_cast<string>("spdf")))); break; 

                    case 7: periodNumB = inputInteger("\tSpecify the Element Period # (0 = unknown or 1...7) :", 1, 7); break; 

                    case 8: meltingPointB = inputDouble("\tSpecify the Element Melting Point (celsius degree) :"); break; 

                    case 9: boilingPointB = inputDouble("\tSpecify the Element Boiling Point (celsius degree) :"); break;
                    case 10: discoveryYearB = inputInteger("\tSpecify the Element Discovery Year :", true); break; 

                    case 11: strncpy_s(discoveredByB, inputString("\tSpecify a new Element Discoverred By :", boolalpha).c_str(), sizeof(discoveredByB) - 1); break;

                    case 0:
                        element[i].symbol; //elements[i].symbol; 
                        strncpy_s(element[i].symbol, sizeof(element[i].symbol), symbolB, _TRUNCATE); //strncpy_s(elements[i].symbol, sizeof(elements[i].symbol), symbolB, _TRUNCATE);
                        element[i].name; //elements[i].name;
                        strncpy_s(element[i].name, sizeof(nameB), nameB, _TRUNCATE); //strncpy_s(elements[i].name, sizeof(nameB), nameB, _TRUNCATE);
                        element[i].mass = massB; //elements[i].mass = massB;
                        element[i].stateType = stateTypeB; //elements[i].stateType = stateTypeB;
                        element[i].groupNum = groupNumB; //elements[i].groupNum = groupNumB;
                        element[i].blockType = blockTypeB; //elements[i].blockType = blockTypeB;
                        element[i].periodNum = periodNumB; //elements[i].periodNum = periodNumB;
                        element[i].meltingPoint = meltingPointB; //elements[i].meltingPoint = meltingPointB;
                        element[i].boilingPoint = boilingPointB; //elements[i].boilingPoint = boilingPointB;
                        element[i].discoveryYear = discoveryYearB; //elements[i].discoveryYear = discoveryYearB;

                       element[i].discoveredBy; //elements[i].discoveredBy;
                       strncpy_s(element[i].discoveredBy, sizeof(discoveredByB), discoveredByB, _TRUNCATE); //strncpy_s(elements[i].discoveredBy, sizeof(discoveredByB), discoveredByB, _TRUNCATE);

                       setColor(2);
                       cout << "\nCONFIRMATION: Element with Atomic # " << element[i].atomicNum << " has been updated into the dynamic array.\n"; //cout << "\nCONFIRMATION: Element with Atomic # " << elements[i].atomicNum << " has been updated into the dynamic array.\n";
                       setColor(15);

                        return 0; break;


                    default: 
                        setColor(12);
                        cout << "\n\tERROR: Invalid Option.\n";
                        setColor(15);
                    }
                    system("cls");
                    //system("pause"); //looks like you skipped the system pause 
                } while (true);

                found = true;
            }

        }

        if (!found)
        {
            setColor(12);
            cout << "\n\tERROR: Cannot update an element with Atomic # (" << a_num << ") that does not existed.Please perform other valid option.\n\n";
            setColor(15);
            return 1;
        }

        return 0;
    }

    // this is needed to pass into sort 
    //spelling error in descending i fixed
    bool sortDescending(const Element& a, const Element& b) //bool sortDescedning(const element& a, const element& b)
    {
        return strcmp(a.symbol, b.symbol) > 0;
    }
    //spelling error in Ascending i fixed
    bool sortAscending(const Element& a, const Element& b) //bool sortAsending(const element& a, const element& b)
    {
        return strcmp(a.symbol, b.symbol) < 0; 
    }

    int  sectionB_sortbySymbol(Element*& element, int& SIZE) ////alex uses int optionB5(element*& elements, int& SIZE) 
    {
        system("cls");

        cout << "\n\tSorting the dynamic array in ascending order by atomic #...";

        if (SIZE == 0)
        {
            setColor(12);
            cout << "\n\n\tERROR: Dynamic array is empty. Therefore, sort cannot be performed.\n"; 
            setColor(15);
            return 1;
        }
        else
        {
            sort(element, element + SIZE, sortDescending); //sort(elements, elements + SIZE, sortDescedning);
            setColor(2);
            cout << "\n\nCONFIRMATION: Dynamic array has been sorted by Symbol in ascending order. Please perfrom Option#2 to display the sorted array.\n";
            setColor(15);
        }

    }

  
    int binarySearch(Element element[], int SIZE, const char* target)  //int binarySearch(element elements[], int SIZE, const char* target)
    {
        int left = 0;
        int right = SIZE - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            int comparison = strcmp(element[mid].symbol, target); //int comparison = strcmp(elements[mid].symbol, target);

            if (comparison == 0)
            {
                return mid;
            }

            if (comparison < 0) 
            {
                right = mid - 1; // switch right to left for ascending currently descending
            }

            else 
            {

                left = mid + 1; // switch right to left for ascending currently descending  
            }

        }
        return -1;
    }

    int sectionB_binarySearchSymbol(Element*& element, int& SIZE)  //int optionB6(element*& elements, int& SIZE)  
    {
        system("cls");
        cout << "\n\tSearching an element from a dynamic array by Symbol...";


        if (SIZE == 0)
        {
            setColor(12);
            cout << "\n\n\tERROR: Dynamic array is empty. Therefore, search cannot be performed.\n"; 
            setColor(15);
            return 1;
        }

        char testSymbol[3];
        strncpy_s(testSymbol, inputString("\n\n\tSpecify a Symbol of an element to search : ", boolalpha).c_str(), sizeof(testSymbol) - 1);

        // changes descending spelling error
        sort(element, element + SIZE, sortDescending); // have to sort first  //sort(elements, elements + SIZE, sortDescedning); // have to sort first

        int result = binarySearch(element, SIZE, testSymbol); //int result = binarySearch(elements, SIZE, testSymbol);

        if (result != -1)
        {
            setColor(12);
            cout << "\n\tCONFIRMATION: Element with Symbol(" << testSymbol << ") is found at index[" << result << "] from the dynamic array.\n";
            setColor(15);
        }
        else 
        {
            setColor(12);
            cout << "\n\tError: Element with Symbol(" << testSymbol << ") cannot be found from the dynamic array.\n";
            setColor(15);
        }
        return 0;

    }

    void arrayToFile(string filename, Element* element, int SIZE) //void arrayToFile(string filename, element* elements, int SIZE)
    {
        fstream file;
        file.open(filename, ios::binary | ios::out);
        for (int i = 0; i < SIZE; i++)
            
            file.write(reinterpret_cast<char*>(&element[i]), sizeof(element[i])); //file.write(reinterpret_cast<char*>(&elements[i]), sizeof(elements[i]));
        file.close();
    }
    
    int  sectionB_arraytoFile(Element*& element, int& SIZE) //int optionB7(element*& elements, int& SIZE)
    {
        system("cls");
        cout << "\n\tWriting elements from the dynamic array to binary data file...";


        if (SIZE == 0)
        {
            setColor(12);
            cout << "\n\n\tERROR: Dynamic array is empty. Therefore, write to file cannot be completed.\n";
            setColor(15);
            return 1;
        }
        string NameofFile = inputString("\n\n\tEnter a binary data file name to store elements(no spaces): ", false);

        //alex has elements
        arrayToFile(NameofFile, element, SIZE);
        setColor(2);
        cout << "CONFIRMATION: Element(s) from dynamic array have been stored into file, " << NameofFile << ".";   //changed from uper L to lower L in Element
        setColor(15);
        
        return 0;

    }


    void sectionB()
    {
        int SIZE = 0;
        //alex uses element for struct
        Element* arrayOfElements = new Element[SIZE];

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
                sectionB_fileReadnStore(arrayOfElements, SIZE);
                break;
            case 2:
                sectionB_displayElement(arrayOfElements, SIZE);
                break;
            case 3:
                sectionB_addElement(arrayOfElements, SIZE);
                break;
            case 4:
                sectionB_updateElement(arrayOfElements, SIZE);
                break;
            case 5:
                sectionB_sortbySymbol(arrayOfElements, SIZE);
                break;
            case 6:
                sectionB_binarySearchSymbol(arrayOfElements, SIZE);
                break;
            case 7:
                sectionB_arraytoFile(arrayOfElements, SIZE);
                break;
            }
            cout << "\n\n\n";
            system("pause");
        } while (true);

        delete[] arrayOfElements; // double check 
    }

    //allison if you want to keep your naming format, change to sectionC1
    //alex has element for struct
    int optionC1(vector<Element>& element)
    {
        system("cls");

        string fileNamePrompt = inputString("\n\tSpecify the binary file name to read from: ", false); // prompt user for the file 

        ifstream myDataFileB1(fileNamePrompt, ios::binary);

        if (!myDataFileB1.is_open())
        { 
            setColor(12);
            cout << "\n\tERROR: FILE " << fileNamePrompt << "  CANNOT BE FOUND.\n\n";
            setColor(15);
            return 1;

        }

        // Seek back to the start of the file and read the data
        myDataFileB1.seekg(0, ios::end);
        int myDataFileB1Size = myDataFileB1.tellg();


           // Calculate the number of elements the file can contain
        //alex has element for struct
        int numElements = myDataFileB1Size / sizeof(Element);

        // Resize the vector to hold the correct number of elements
        element.resize(numElements);

        // Seek back to the start of the file and read the data
        myDataFileB1.seekg(0, ios::beg);
        myDataFileB1.read(reinterpret_cast<char*>(element.data()), myDataFileB1Size);
        //########################################################################################


        if (!myDataFileB1)
        {
            setColor(12);
            cout << "\n\tERROR READING FILE!" << endl;
            setColor(15);
            myDataFileB1.close();
        }

        myDataFileB1.close();
        setColor(2);
        cout << "\n\tCONFIRMATION: Data from binary file, " << fileNamePrompt << " has been retrieved and stored into the vector.\n\n";
        setColor(15);

        return 0;
    }

    //alex has element for struct and elements
    int optionC2(vector<Element>& element) // maybe not an int 
    {
        system("cls");

        //alex has elements
        if (element.data() == 0)
        {
            setColor(12);
            cout << "\n\tERROR: The vector is empty. Therfore cannot display any element.\n\n";
            setColor(15);

            return 1;

        }

        cout << "\n\n\tDisplay ALL element(s) from the vector...\n\n";

        displayAllElements(element);

        
        cout << "\tSize : " << element.size() << "\n\n";
        return 0;
    }

    //alex has element for struct and elements
    int optionC3(vector<Element>& element)
    {
        
        system("cls");

        cout << "\tAdd a new element to the vector...\n\n";

        short atomicNumC;
        atomicNumC = inputInteger("\tSpecify the atomic # : ", true);

        //alex has elements
        for (size_t i = 0; i < element.size(); i++)
        {
            //alex has elements
            if (atomicNumC == element[i].atomicNum)
            {
                setColor(12);
                cout << "\n\t ERROR: Element with atomic #(" << atomicNumC << ")is already existed in the vector at index[" << i << "]. Please perform other valid option.\n";
                setColor(15);
                return 1;
            }
        }

        //alex has elements
        for (size_t i = 0; i < element.size(); i++)
        {
            //alex has elements
            if (atomicNumC != element[i].atomicNum);
        }

        //alex has element for struct
        Element newElements;
        //newElements.atomicNum = inputInteger("\n\tSpecify the Element Atomic # : ", true);
        strncpy_s(newElements.symbol, inputString("\tSpecify the Element Symbol : ", boolalpha).c_str(), _TRUNCATE);
        strncpy_s(newElements.name, sizeof(25), inputString("\tSpecify the Element Name :", boolalpha).c_str(), _TRUNCATE);
        newElements.mass = inputDouble("\tSpecify the Element Mass : ");
        newElements.stateType = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) : ", static_cast<string>("slgu"))));
        newElements.groupNum = inputInteger("\tSpecify the Element Group # (0 = unknown or 1...18) : ", 0, 18);
        newElements.periodNum = inputInteger("\tSpecify the Element Period # (0 = unknown or 1...7) : ", 0, 7);
        newElements.blockType = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) : ", static_cast<string>("spdf"))));
        newElements.meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) : "); //valdiate& change 
        newElements.boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) : "); //validate
        newElements.discoveryYear = inputInteger("\tSpecify the Element Discovery Year : ", true);
        strncpy_s(newElements.discoveredBy, sizeof(100), inputString("\tSpecify the Element Discoverred By : ", true).c_str(), _TRUNCATE); //maybe tak eout sizeof100

        //alex has elements
        element.push_back(newElements);

        setColor(2);
        cout << "\n\tCONFIRMATION: A new element with Atomic # (" << atomicNumC << ") has been added into the dynamic array.\n\n"; 
        setColor(15);


        return 0;
    }

     // this code should update the element prompted 
    //alex has element for struct and elements
    int optionC4(vector<Element>& element)
    {
        system("cls");
        cout << "\tUpdating an existing element from the vector...\n";

        //alex has elements
        if (element.data() == 0)
        {
            setColor(12);
            cout << "\n\tERROR: Vector is empty. Please perform other valid option.\n\n";
            setColor(15);
            return 1;
        }

        bool found = false;
        short a_num = inputInteger("\n\n\tSpecify an existing Element Atomic # :", true);

        //alex has elements 
        for (size_t i = 0; i < element.size(); i++)
        {
            //alex has elements, edit next few lines as needed 
            if (a_num == element[i].atomicNum) //this might need adjustment 
            {
          
                short atomicNumB = element[i].atomicNum;
                char symbolB[3];
                strncpy_s(symbolB, sizeof(symbolB), element[i].symbol, _TRUNCATE);
                char nameB[25];
                strncpy_s(nameB, sizeof(nameB), element[i].name, _TRUNCATE);
                float massB = element[i].mass;
                char stateTypeB = element[i].stateType;
                short groupNumB = element[i].groupNum;
                short periodNumB = element[i].periodNum;
                char blockTypeB = element[i].blockType;
                float meltingPointB = element[i].meltingPoint;
                float boilingPointB = element[i].boilingPoint;
                short discoveryYearB = element[i].discoveryYear;
                char discoveredByB[100];
                strncpy_s(discoveredByB, sizeof(discoveredByB), element[i].discoveredBy, _TRUNCATE);
                do
                {
                    float kelvinm = 0.0;
                    float farenheitm = 0.0;
                    float kelvinb = 0.0;
                    float farenheitb = 0.0;
                    string blockTypeName = "unknown";
                    char block = toupper(blockTypeB);
                    string discoveryYear;
                    /*HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);*/

                    kelvinm = meltingPointB + 273.15;
                    farenheitm = (meltingPointB * 1.8) + 32;

                    kelvinb = boilingPointB + 273.15;
                    farenheitb = (boilingPointB * 1.8) + 32;


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

                    //alex has elements, change as needed 
                    cout << setw(20) << left << "\n\tAtomic #" << ": " << left << element[i].atomicNum;
                    cout << setw(20) << left << "\n\tSymbol " << ": " << left << symbolB; // might need to checck if the input is the same 
                    cout << setw(20) << left << "\n\tName " << ": " << left << nameB;
                    cout << setw(20) << left << "\n\tMass" << ": " << left << massB << " u";
                    cout << setw(20) << left << "\n\tState Type" << ": " << left << stateTypeB;
                    cout << setw(20) << left << "\n\tGroup #" << ": " << left << groupNumB;
                    cout << setw(20) << left << "\n\tPeriod #" << ": " << periodNumB;
                    cout << setw(20) << left << "\n\tBlock Type" << ": (" << block << ") " << blockTypeName;
                    cout << setw(20) << left << setprecision(2) << fixed << "\n\tMelting Point" << ": " << meltingPointB << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K";
                    cout << setw(20) << left << setprecision(2) << fixed << "\n\tBoiling Point" << ": " << boilingPointB << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K";
                    cout << setw(20) << left << "\n\tDiscovery Year" << ": " << discoveryYearB;
                  
                    if (discoveryYearB == 0)
                    {
                        cout << "Prehistoric";
                    }
                    else
                    {
                        cout << discoveryYearB;
                    }
                    cout << setw(20) << left << "\n\tDiscovered by" << ": " << discoveredByB << "\n\n";
/////////////////////////////////////////////////////////////////////////////
                    cout << "\n\tUpdating Element's information...";
                    cout << "\n\t" << string(100, char(205));
                    cout << "\n\t 1)  Symbol";
                    cout << "\n\t 2)  Name";
                    cout << "\n\t 3)  Atomic Mass";
                    cout << "\n\t 4)  State type";
                    cout << "\n\t 5)  Group #";
                    cout << "\n\t 6)  Block Type";
                    cout << "\n\t 7)  Period Type";
                    cout << "\n\t 8)  Melting Point";
                    cout << "\n\t 9)  Boiling Point";
                    cout << "\n\t 10) Discoverred Year";
                    cout << "\n\t 11) Discoverred BY";
                    cout << "\n\t" << string(100, char(205));
                    cout << "\n";
                    cout << "\n\t -1) Return WITHOUT changes(s)";
                    cout << "\n\t  0) Return WITH comitted change(s)";
                    cout << "\n\t" << string(100, char(205));
                    switch (inputInteger("\n\tOption: ", -1, 11))
                    {
                        // you need a buffer
                    case -1:
                        setColor(0x0E);
                        cout << "\nWarning: No update was committed.\n\n"; 
                        setColor(15);

                        return 0; 
                       
                    case 1:strncpy_s(symbolB, inputString("\tSpecify the Element Symbol :", boolalpha).c_str(), sizeof(symbolB) - 1); break;

                    case 2:strncpy_s(nameB, sizeof(nameB), inputString("\tSpecify the Element Name :", boolalpha).c_str(), _TRUNCATE); break; 

                    case 3: massB = inputDouble("\tSpecify the Element Mass :"); break; 

                    case 4: stateTypeB = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) :", static_cast<string>("slgu"))));; break; 

                    case 5: groupNumB = inputInteger("\tSpecify the Element Group # (0 = unknown or 1...18) :", 0, 18); break; 

                    case 6: blockTypeB = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) :", static_cast<string>("spdf")))); break; 

                    case 7: periodNumB = inputInteger("\tSpecify the Element Period # (0 = unknown or 1...7) :", 1, 7); break; 

                    case 8: meltingPointB = inputDouble("\tSpecify the Element Melting Point (celsius degree) :"); break;

                    case 9: boilingPointB = inputDouble("\tSpecify the Element Boiling Point (celsius degree) :"); break; 

                    case 10: discoveryYearB = inputInteger("\tSpecify the Element Discovery Year :", true); break;

                    case 11: strncpy_s(discoveredByB, inputString("\tSpecify a new Element Discoverred By :", boolalpha).c_str(), sizeof(discoveredByB) - 1); break;

                    case 0:
                        //alex has elements, change as needed 
                        element[i].symbol; // this might not be needed as its passed argument 
                        strncpy_s(element[i].symbol, sizeof(element[i].symbol), symbolB, _TRUNCATE);

                        element[i].name;
                        strncpy_s(element[i].name, sizeof(nameB), nameB, _TRUNCATE);

                        element[i].mass = massB;
                        element[i].stateType = stateTypeB;
                        element[i].groupNum = groupNumB;
                        element[i].blockType = blockTypeB;
                        element[i].periodNum = periodNumB;
                        element[i].meltingPoint = meltingPointB;
                        element[i].boilingPoint = boilingPointB;
                        element[i].discoveryYear = discoveryYearB;

                        element[i].discoveredBy;
                        strncpy_s(element[i].discoveredBy, sizeof(discoveredByB), discoveredByB, _TRUNCATE);

                        setColor(2);
                        cout << "\nCONFIRMATION: Element with Atomic # " << element[i].atomicNum << " has been updated into vector.\n";
                        setColor(15);

                        return 0; break;


                    default: 
                        setColor(12);
                        cout << "\n\tERROR: Invalid Option.\n";
                        setColor(15);
                    }
                    system("cls");
                   
                } while (true);

                found = true;
            }
        }

        if (!found)
        {
            setColor(12);
            cout << "\n\t ERROR: Element with Atomic#(" << a_num << ") does not existed in the vector. Please perform other valid option.\n\n";
            setColor(15);
            return 1;
        }
        return 0;
    }

    //alex has element struct and elements
    int optionC5(vector<Element>& element)
    {
        system("cls");
        cout << "\tSort the vector by Name in ascending order...\n";

        //alex has elements
        if (element.data() == 0)
        {
            setColor(12);
            cout << "\n\tERROR: Vector is empty. Therefore, sort cannot be completed.\n\n";
            setColor(15);
            return 1;
        }

        //alex has elements and asending (i changed the spelling error)
        sort(element.begin(), element.end(), sortAscending);

        setColor(2);
        cout << "\n\tCONFIRMATION: Vector has been sorted by Name in ascending order. Please perform Option#2 to display the newly sorted vector.\n\n";
        setColor(15);
    }

    //alex has element for struct and elements
    int binarySearchV(const vector<Element>& element, const char* target)
    {
        int left = 0;
        //alex has elements
        int right = element.size() - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            //alex has elements
            int cmp = strcmp(element[mid].name, target);
            if (cmp == 0)
            {
                return mid;
            }
            else if (cmp < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    //alex has element for struct and elements
    int optionC6(vector<Element>& element)
    {
        system("cls");
        cout << "\tSearch an element from the the vector by Name...\n";

        //alex has elements
        if (element.data() == 0)
        {
            setColor(12);
            cout << "\n\tERROR: Vector is empty. Therefore, search can be performed.\n\n";
            setColor(15);
            return 1;
        }

        char nameC[25] = "UNK";
        strncpy_s(nameC, inputString("\n\n\tSpecify a Name of an element to search : ", boolalpha).c_str(), sizeof(nameC) - 1);

        //alex has elements and asending (i changed spelling error)
        sort(element.begin(), element.end(), sortAscending);

        //alex has elements
        int result = binarySearchV(element, nameC);

        if (result != -1) 
        {
            setColor(2);
            cout << "\n\tCONFIRMATION: Element with Name(" << nameC << ") is found at Index[" << result << "] from vector.\n\n";
            setColor(15);
        }
        else
        {
            setColor(12);
            cout << "\n\tError: Element with Name(" << nameC << ") cannot be found from vector.\n\n";
            setColor(15);
        }
        return 0;
    }

    //alex has element for struct and elements
    void vectorToFile(string filename, vector<Element>& element)
    {
        fstream file;
        file.open(filename, ios::binary | ios::out);
        //alex has elements
        for (size_t i = 0; i < element.size(); i++)
            file.write(reinterpret_cast<char*>(&element[i]), sizeof(element[i]));
        file.close();
    }

    //alex has element for struct and elements
    int optionC7(vector<Element>& element)
    {
        system("cls");
        cout << "\t\nWriting elements from the vector to binary data file...\n";

        //alex has elements
        if (element.data() == 0)
        {
            setColor(12);
            cout << "\n\tERROR: Vector is empty. Therefore, write to binary file cannot be completed.\n\n";
            setColor(15);
            return 1;
        }


        string NameofFile = inputString("\n\n\tEnter a binary data file name to store elements(no spaces): ", false);

        //alex has elements
        vectorToFile(NameofFile, element);

        setColor(2);
        cout << "CONFIRMATION: ELements(s) from dynamic array have been stored into file, " << NameofFile << ".\n\n";
        setColor(15);

        return 0;
    }

    //alex has optionC()
    void sectionC()
    {
        int SIZE = 0;
        //alex has element fro struct
        vector <Element> vectorOfElements(SIZE);

        do
        {
            system("cls");
            cout << "\n\tOption C: Vector";
            cout << "\n\t" << string(100, char(205));
            cout << "\n\t 1) Read ALL element(s) from the binary data file and store into the vector";
            cout << "\n\t 2) Display ALL element(s) from the vector";
            cout << "\n\t 3) Add a new element into the vector";
            cout << "\n\t 4) Update an existing element from the vector";
            cout << "\n\t 5) Sort the vector by Name  in ascending order";
            cout << "\n\t 6) Binary search for an element by Name";
            cout << "\n\t 7) Store elements from the vector into the binary data file"; // misspelled binary  
            cout << "\n\t" << string(100, char(205));
            cout << "\n";
            cout << "\n\t 0) Return to Main Menu"; // this option you just had return 0. but this looks better with return to main 
            cout << "\n\t" << string(100, char(205));
            switch (inputInteger("\n\tOption: ", 0, 7))
            {
            case 0: return;
            case 1: optionC1(vectorOfElements); break;
            case 2: optionC2(vectorOfElements); break;
            case 3: optionC3(vectorOfElements); break;
            case 4: optionC4(vectorOfElements); break;
            case 5: optionC5(vectorOfElements); break;
            case 6: optionC6(vectorOfElements); break;
            case 7: optionC7(vectorOfElements); break;
            default: 
                setColor(12);
                cout << "\n\tERROR: Invalid Option.\n";
                setColor(15);
            }

            system("pause");
        } while (true);
    }
