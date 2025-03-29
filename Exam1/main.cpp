#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h> // for color-coded periodic table
#include "input.h"

using namespace std;

void sectionA();
void sectionB();
void sectionC();
void sectionX();
void setColor(int color);

//sets color for text
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



struct Element
{
    short atomicNum = 0; //Atomic Number
    char symbol[3] = "un"; //Symbol
    char name[25] = "unkown"; //Name
    float mass = 0.0; //Mass
    char stateType = 'u'; //State Type
    short groupNum = 0; //Group #
    short periodNum = 0; //Period #
    char blockType = 'u'; //Block Type
    float meltingPoint = 0.0; //Melting Point
    float boilingPoint = 0.0; //Boiling Point
    int discoveryYear = 0; // Discovery Year
    char discoveredBy[100] = "unkown"; //Discoverd by
};


int main()
{
    do
    {
        system("cls");
        cout << "\n\tCMPR121 - Exam#1: Implementation using Dynamic Array, string/c-string, struct, and Binary File By YOURNAME (dd/mm/yy)\n";
        cout << "\n" << string(132, char(205));
        cout << "\n\n\t A) Advance Binary Data File (chapter#12)";
        cout << "\n\n\t B) Dynamic Array (chapter#9)";
        cout << "\n\n\t C) Vector (chapter#7)";
        cout << "\n\n\t X) Xtra credits (5pts)\n";
        cout << "\n" << string(132, char(205));
        cout << "\n\n";
        cout << "\n\n\t Q) Quit (terminate) Program\n";
        cout << "\n" << string(132, char(205));

        switch (toupper(inputChar("\n\tOption: ", "QABCX")))
        {
        case 'Q': exit(0); 
        case 'A': sectionA(); break; 
        case 'B': sectionB(); break;
        case 'C': sectionC(); break; 
        case 'X': sectionX(); break; 

        default:
            setColor(7);
            cout << "\n\tERROR: Invalid Option.\n";
            setColor(15);
        }

        system("pause");
    } while (true);

    return 0;
}
