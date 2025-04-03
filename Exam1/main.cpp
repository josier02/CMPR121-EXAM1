
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

//allison uses (this is just an example for the color red) SetConsoleTextAttribute(color, 12); where I use setColor(12); you guys can decide which you wanna use
//for mine you dont need to have the changed input header, the professors copy works fine just add the appropriate void set color funciton


using namespace std;

//prototypes
void sectionA(); 
void sectionB(); 
void sectionC(); 

void optionX();

//Prints individual bracket with atomic number and element symbol through taking a number by Christopher Rios
void printBracket(int i);

void printMenuPeriodicTable();

const int ELEMENT_COUNT = 118;

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

Element elements[118] =
{
    {1, "H", "Hydrogen", 1.008, 'g', 1, 1, 1, -259.16, -252.87, 1766, "Henry Cavendish"},
    {2, "He", "Helium", 4.0026, 'g', 18, 1, 1, -272.2, -268.93, 1895, "Sir William Ramsay"},
    {3, "Li", "Lithium", 6.94, 's', 1, 2, 1, 180.54, 1342, 1817, "Johan August Arfvedson"},
    {4, "Be", "Beryllium", 9.0122, 's', 2, 2, 1, 1287, 2471, 1798, "Louis-Nicolas Vauquelin"},
    {5, "B", "Boron", 10.81, 's', 13, 2, 2, 2076, 3927, 1808, "Joseph Louis Gay-Lussac"},
    {6, "C", "Carbon", 12.011, 's', 14, 2, 2, 3550, 4827, -0, "Unknown"},
    {7, "N", "Nitrogen", 14.007, 'g', 15, 2, 2, -210.1, -195.79, 1772, "Daniel Rutherford"},
    {8, "O", "Oxygen", 15.999, 'g', 16, 2, 2, -218.79, -182.95, 1774, "Joseph Priestley"},
    {9, "F", "Fluorine", 18.998, 'g', 17, 2, 2, -219.67, -188.12, 1886, "Henri Moissan"},
    {10, "Ne", "Neon", 20.180, 'g', 18, 2, 2, -248.59, -246.08, 1898, "Sir William Ramsay"},
    {11, "Na", "Sodium", 22.990, 's', 1, 3, 1, 97.72, 883, 1807, "Humphry Davy"},
    {12, "Mg", "Magnesium", 24.305, 's', 2, 3, 1, 650, 1091, 1808, "Humphry Davy"},
    {13, "Al", "Aluminum", 26.982, 's', 13, 3, 2, 660.32, 2470, 1825, "Hans Christian Ørsted"},
    {14, "Si", "Silicon", 28.085, 's', 14, 3, 2, 1414, 3265, 1824, "Jöns Jakob Berzelius"},
    {15, "P", "Phosphorus", 30.974, 's', 15, 3, 2, 44.15, 280.5, 1669, "Hennig Brand"},
    {16, "S", "Sulfur", 32.06, 's', 16, 3, 2, 115.21, 444.6, -0, "Unknown"},
    {17, "Cl", "Chlorine", 35.45, 'g', 17, 3, 2, -101.5, -34.04, 1774, "Carl Wilhelm Scheele"},
    {18, "Ar", "Argon", 39.948, 'g', 18, 3, 2, -189.35, -185.85, 1894, "Lord Rayleigh and Sir William Ramsay"},
    {19, "K", "Potassium", 39.098, 's', 1, 4, 1, 63.38, 759, 1807, "Humphry Davy"},
    {20, "Ca", "Calcium", 40.078, 's', 2, 4, 1, 842, 1484, 1808, "Humphry Davy"},
    {21, "Sc", "Scandium", 44.956, 's', 3, 4, 1, 1541, 2836, 1879, "Lars Fredrik Nilson"},
    {22, "Ti", "Titanium", 47.867, 's', 4, 4, 1, 1668, 3287, 1791, "William Gregor"},
    {23, "V", "Vanadium", 50.942, 's', 5, 4, 1, 1910, 3407, 1801, "Andrés Manuel del Río"},
    {24, "Cr", "Chromium", 51.996, 's', 6, 4, 1, 1907, 2671, 1797, "Louis-Nicolas Vauquelin"},
    {25, "Mn", "Manganese", 54.938, 's', 7, 4, 1, 1246, 2061, 1774, "Carl Wilhelm Scheele"},
    {26, "Fe", "Iron", 55.845, 's', 8, 4, 1, 1538, 2862, -0, "Unknown"},
    {27, "Co", "Cobalt", 58.933, 's', 9, 4, 1, 1495, 2927, 1735, "Georg Brandt"},
    {28, "Ni", "Nickel", 58.693, 's', 10, 4, 1, 1455, 2730, 1751, "Axel Fredrik Cronstedt"},
    {29, "Cu", "Copper", 63.546, 's', 11, 4, 1, 1084.62, 2562, -0, "Unknown"},
    {30, "Zn", "Zinc", 65.38, 's', 12, 4, 1, 419.53, 907, -0, "Unknown"},
    {31, "Ga", "Gallium", 69.723, 's', 13, 4, 2, 29.76, 2204, 1875, "Lecoq de Boisbaudran"},
    {32, "Ge", "Germanium", 72.63, 's', 14, 4, 2, 938.25, 2833, 1886, "Clemens Winkler"},
    {33, "As", "Arsenic", 74.9216, 's', 15, 4, 2, 817, 614, -0, "Unknown"},
    {34, "Se", "Selenium", 78.96, 's', 16, 4, 2, 221, 685, 1817, "Jöns Jakob Berzelius"},
    {35, "Br", "Bromine", 79.904, 'l', 17, 4, 2, -7.2, 58.8, 1826, "Antoine Jérôme Balard"},
    {36, "Kr", "Krypton", 83.798, 'g', 18, 4, 2, -157.36, -153.22, 1898, "Sir William Ramsay"},
    {37, "Rb", "Rubidium", 85.4678, 's', 1, 5, 1, 39.31, 688, 1861, "Robert Bunsen"},
    {38, "Sr", "Strontium", 87.62, 's', 2, 5, 1, 777, 1382, 1790, "Adair Crawford"},
    {39, "Y", "Yttrium", 88.9059, 's', 3, 5, 1, 1526, 3336, 1794, "Johan Gadolin"},
    {40, "Zr", "Zirconium", 91.224, 's', 4, 5, 1, 1855, 4409, 1789, "Martin Heinrich Klaproth"},
    {41, "Nb", "Niobium", 92.9064, 's', 5, 5, 1, 2477, 4744, 1801, "Charles Hatchett"},
    {42, "Mo", "Molybdenum", 95.95, 's', 6, 5, 1, 2623, 4639, 1778, "Carl Wilhelm Scheele"},
    {43, "Tc", "Technetium", 98, 's', 7, 5, 1, 2157, 4265, 1937, "Carlo Perrier"},
    {44, "Ru", "Ruthenium", 101.07, 's', 8, 5, 1, 2334, 4150, 1844, "Karl Ernst Claus"},
    {45, "Rh", "Rhodium", 102.9055, 's', 9, 5, 1, 1964, 3695, 1803, "William Hyde Wollaston"},
    {46, "Pd", "Palladium", 106.42, 's', 10, 5, 1, 1554.9, 2963, 1803, "William Hyde Wollaston"},
    {47, "Ag", "Silver", 107.8682, 's', 11, 5, 1, 961.78, 2162, -0, "Unknown"},
    {48, "Cd", "Cadmium", 112.414, 's', 12, 5, 1, 321.07, 767, 1817, "Friedrich Stromeyer"},
    {49, "In", "Indium", 114.818, 's', 13, 5, 2, 156.6, 2072, 1863, "Ferdinand Reich"},
    {50, "Sn", "Tin", 118.71, 's', 14, 5, 2, 231.93, 2602, -0, "Unknown"},
    {51, "Sb", "Antimony", 121.76, 's', 15, 5, 2, 630.63, 1587, -0, "Unknown"},
    {52, "Te", "Tellurium", 127.6, 's', 16, 5, 2, 449.51, 988, 1782, "Franz-Joseph Müller von Reichenstein"},
    {53, "I", "Iodine", 126.9045, 's', 17, 5, 2, 113.7, 184.3, 1811, "Bernard Courtois"},
    {54, "Xe", "Xenon", 131.293, 'g', 18, 5, 2, -111.8, -108.1, 1898, "Sir William Ramsay"},
    {55, "Cs", "Cesium", 132.9055, 's', 1, 6, 1, 28.44, 671, 1860, "Robert Bunsen"},
    {56, "Ba", "Barium", 137.327, 's', 2, 6, 1, 727, 1897, 1808, "Humphry Davy"},
    {57, "La", "Lanthanum", 138.9055, 's', 3, 6, 1, 920, 3464, 1839, "Carl Gustaf Mosander"},
    {58, "Ce", "Cerium", 140.116, 's', 4, 6, 1, 798, 3443, 1803, "Martin Heinrich Klaproth"},
    {59, "Pr", "Praseodymium", 140.9077, 's', 5, 6, 1, 931, 3520, 1885, "Carl Auer von Welsbach"},
    {60, "Nd", "Neodymium", 144.242, 's', 6, 6, 1, 1024, 3074, 1885, "Carl Auer von Welsbach"},
    {61, "Pm", "Promethium", 145, 's', 7, 6, 1, 1042, 3000, 1945, "Jacob A. Marinsky"},
    {62, "Sm", "Samarium", 150.36, 's', 8, 6, 1, 1072, 1794, 1879, "Lecoq de Boisbaudran"},
    {63, "Eu", "Europium", 151.964, 's', 9, 6, 1, 822, 1529, 1901, "Eugène-Anatole Demarçay"},
    {64, "Gd", "Gadolinium", 157.25, 's', 10, 6, 1, 1312, 3250, 1880, "Jean Charles Galissard de Marignac"},
    {65, "Tb", "Terbium", 158.9253, 's', 11, 6, 1, 1356, 3230, 1843, "Carl Gustaf Mosander"},
    {66, "Dy", "Dysprosium", 162.5, 's', 12, 6, 1, 1412, 2567, 1886, "Paul Émile Lecoq de Boisbaudran"},
    {67, "Ho", "Holmium", 164.9303, 's', 13, 6, 1, 1474, 2700, 1878, "Marc Delafontaine"},
    {68, "Er", "Erbium", 167.259, 's', 14, 6, 1, 1529, 2868, 1842, "Carl Gustaf Mosander"},
    {69, "Tm", "Thulium", 168.9342, 's', 15, 6, 1, 1545, 1950, 1879, "Per Teodor Cleve"},
    {70, "Yb", "Ytterbium", 173.045, 's', 16, 6, 1, 1097, 1469, 1878, "Jean Charles Galissard de Marignac"},
    {71, "Lu", "Lutetium", 174.9668, 's', 17, 6, 1, 1652, 3402, 1907, "Georges Urbain"},
    {72, "Hf", "Hafnium", 178.49, 's', 4, 6, 1, 2233, 4603, 1923, "Dirk Coster"},
    {73, "Ta", "Tantalum", 180.9479, 's', 5, 6, 1, 3017, 5458, 1802, "Anders Ekeberg"},
    {74, "W", "Tungsten", 183.84, 's', 6, 6, 1, 3422, 5555, 1783, "José and Fausto Elhuyar"},
    {75, "Re", "Rhenium", 186.207, 's', 7, 6, 1, 3186, 5596, 1925, "Ida Noddack"},
    {76, "Os", "Osmium", 190.23, 's', 8, 6, 1, 3033, 5012, 1803, "Smithson Tennant"},
    {77, "Ir", "Iridium", 192.217, 's', 9, 6, 1, 2466, 4428, 1803, "Smithson Tennant"},
    {78, "Pt", "Platinum", 195.084, 's', 10, 6, 1, 1768.3, 3825, 1735, "Antonio de Ulloa"},
    {79, "Au", "Gold", 196.9665, 's', 11, 6, 1, 1064.18, 2970, -0, "Unknown"},
    {80, "Hg", "Mercury", 200.592, 'l', 12, 6, 1, -38.83, 356.73, -0, "Unknown"},
    {81, "Tl", "Thallium", 204.38, 's', 13, 6, 1, 304, 1473, 1861, "William Crookes"},
    {82, "Pb", "Lead", 207.2, 's', 14, 6, 1, 327.46, 1749, -0, "Unknown"},
    {83, "Bi", "Bismuth", 208.9804, 's', 15, 6, 1, 271.3, 1564, 1753, "Claude François Geoffroy"},
    {84, "Po", "Polonium", 209, 's', 16, 6, 1, 254, 962, 1898, "Marie Curie"},
    {85, "At", "Astatine", 210, 's', 17, 6, 1, 302, 337, 1940, "Dale R. Corson"},
    {86, "Rn", "Radon", 222, 'g', 18, 6, 1, -71, -61.7, 1900, "Friedrich Ernst Dorn"},
    {87, "Fr", "Francium", 223, 's', 1, 7, 1, 27, 677, 1939, "Marguerite Perey"},
    {88, "Ra", "Radium", 226, 's', 2, 7, 1, 700, 1737, 1898, "Marie Curie"},
    {89, "Ac", "Actinium", 227, 's', 3, 7, 1, 1050, 3200, 1899, "Friedrich Oskar Giesel"},
    {90, "Th", "Thorium", 232.0381, 's', 4, 7, 1, 1750, 4788, 1829, "Jöns Jakob Berzelius"},
    {91, "Pa", "Protactinium", 231.0359, 's', 5, 7, 1, 1568, 4027, 1913, "Kaiser Wilhelm Institute"},
    {92, "U", "Uranium", 238.0289, 's', 6, 7, 1, 1135, 4131, 1789, "Martin Heinrich Klaproth"},
    {93, "Np", "Neptunium", 237, 's', 7, 7, 1, 640, 3902, 1940, "Edwin McMillan"},
    {94, "Pu", "Plutonium", 244, 's', 8, 7, 1, 640, 3228, 1940, "Glenn T. Seaborg"},
    {95, "Am", "Americium", 243, 's', 9, 7, 1, 1176, 2607, 1944, "Glenn T. Seaborg"},
    {96, "Cm", "Curium", 247, 's', 10, 7, 1, 1340, 3110, 1944, "Glenn T. Seaborg"},
    {97, "Bk", "Berkelium", 247, 's', 11, 7, 1, 986, 2627, 1949, "Lawrence Berkeley National Laboratory"},
    {98, "Cf", "Californium", 251, 's', 12, 7, 1, 900, 1470, 1950, "Lawrence Berkeley National Laboratory"},
    {99, "Es", "Einsteinium", 252, 's', 13, 7, 1, 860, 996, 1952, "Lawrence Berkeley National Laboratory"},
    {100, "Fm", "Fermium", 257, 's', 14, 7, 1, 1527, 2270, 1952, "Lawrence Berkeley National Laboratory"},
    {101, "Md", "Mendelevium", 258, 's', 15, 7, 1, 827, 1097, 1955, "Lawrence Berkeley National Laboratory"},
    {102, "No", "Nobelium", 259, 's', 16, 7, 1, 827, 1105, 1958, "Lawrence Berkeley National Laboratory"},
    {103, "Lr", "Lawrencium", 266, 's', 17, 7, 1, 1627, 1627, 1961, "Lawrence Berkeley National Laboratory"},
    {104, "Rf", "Rutherfordium", 267, 's', 4, 7, 3, 2400, -1, 1969, "Dubna" },
    {105, "Db", "Dubnium", 270, 's', 5, 7, 3, -1, -1, 1967, "Dubna" },
    {106, "Sg", "Seaborgium", 271, 's', 6, 7, 3, -1, -1, 1974, "Berkeley" },
    {107, "Bh", "Bohrium", 270, 's', 7, 7, 3, -1, -1, 1981, "Darmstadt" },
    {108, "Hs", "Hassium", 277, 's', 8, 7, 3, -1, -1, 1984, "Darmstadt" },
    {109, "Mt", "Meitnerium", 278, 's', 9, 7, 3, -1, -1, 1982, "Darmstadt" },
    {110, "Ds", "Darmstadtium", 281, 's', 10, 7, 3, -1, -1, 1994, "Darmstadt" },
    {111, "Rg", "Roentgenium", 282, 's', 11, 7, 3, -1, -1, 1994, "Darmstadt" },
    {112, "Cn", "Copernicium", 285, 's', 12, 7, 3, -1, -1, 1996, "Darmstadt" },
    {113, "Nh", "Nihonium", 286, 's', 13, 7, 2, -1, -1, 2003, "RIKEN" },
    {114, "Fl", "Flerovium", 289, 's', 14, 7, 2, -1, -1, 1998, "Dubna" },
    {115, "Mc", "Moscovium", 290, 's', 15, 7, 2, -1, -1, 2003, "Dubna" },
    {116, "Lv", "Livermorium", 293, 's', 16, 7, 2, -1, -1, 2000, "Dubna" },
    {117, "Ts", "Tennessine", 294, 's', 17, 7, 2, -1, -1, 2010, "Dubna" },
    {118, "Og", "Oganesson", 294, 'g', 18, 7, 2, -1, -1, 2002, "Dubna" }
};


void setColor(int colorCode)
{
    /*

Code	Color	Example
1	Blue	setColor(1);
2	Green	setColor(2);
3	Cyan	setColor(3);
4	Red	setColor(4);
5	Magenta	setColor(5);
6	Yellow	setColor(6);
7	White (Default)	setColor(7);
8	Gray	setColor(8);
9	Bright Blue	setColor(9);
10	Bright Green	setColor(10);
11	Bright Cyan	setColor(11);
12	Bright Red	setColor(12);
13	Bright Magenta	setColor(13);
14	Bright Yellow	setColor(14);
15	Bright White	setColor(15);

    */

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void printBracket(int i)
{
    // Format: [ X-Y ] where X is atomic number, Y is symbol
    char buffer[9]; // 8 chars + null terminator
    snprintf(buffer, sizeof(buffer), "[%2d-%-2s]", elements[i].atomicNum, elements[i].symbol);

    // Ensure the output is exactly 8 characters
    cout << string(buffer).substr(0, 8);
}

void printMenuPeriodicTable()
{
    /*

Code	Color	Example
1	Blue	setColor(1);
2	Green	setColor(2);
3	Cyan	setColor(3);
4	Red	setColor(4);
5	Magenta	setColor(5);
6	Yellow	setColor(6);
7	White (Default)	setColor(7);
8	Gray	setColor(8);
9	Bright Blue	setColor(9);
10	Bright Green	setColor(10);
11	Bright Cyan	setColor(11);
12	Bright Red	setColor(12);
13	Bright Magenta	setColor(13);
14	Bright Yellow	setColor(14);
15	Bright White	setColor(15);

    */

    cout << "\n\t" << char(201) << string(160, char(205)) << char(187);

    cout << "\n\t" << char(186) << string(40, char(32)) << "Periodic Table of Elements by Atomic Number & Symbol(colors 5 pts Xtra credits) " << string(40, char(32)) << char(186);

    //Period 1
    cout << "\n\t" << char(186) << string(8, char(32));
    setColor(9);
    printBracket(0);
    cout << string(130, char(32));
    setColor(12);
    printBracket(1);
    setColor(15);
    cout << string(8, char(32)) << char(186);

    //Period 2
    cout << "\n\t" << char(186) << string(8, char(32));
    setColor(11);
    printBracket(2);
    setColor(12);
    printBracket(3);
    cout << string(88, char(32));
    setColor(14);
    printBracket(4);
    setColor(9);
    printBracket(5);
    printBracket(6);
    printBracket(7);
    printBracket(8);
    setColor(12);
    printBracket(9);
    setColor(15);
    cout << string(8, char(32)) << char(186);

    //Period 3
    cout << "\n\t" << char(186) << string(8, char(32));
    setColor(11);
    printBracket(10);
    setColor(12);
    printBracket(11);
    cout << string(88, char(32));
    setColor(10);
    printBracket(12);
    setColor(14);
    printBracket(13);
    setColor(9);
    printBracket(14);
    printBracket(15);
    printBracket(16);
    setColor(12);
    printBracket(17);
    setColor(15);
    cout << string(8, char(32)) << char(186);

    //Period 4
    cout << "\n\t" << char(186) << string(8, char(32));
    setColor(11);
    printBracket(18);
    setColor(12);
    printBracket(19);
    setColor(13);
    printBracket(20);
    cout << string(18, char(32));
    printBracket(21);
    printBracket(22);
    printBracket(23);
    printBracket(24);
    printBracket(25);
    printBracket(26);
    printBracket(27);
    printBracket(28);
    printBracket(29);
    setColor(10);
    printBracket(30);
    setColor(14);
    printBracket(31);
    printBracket(32);
    setColor(9);
    printBracket(33);
    printBracket(34);
    setColor(12);
    printBracket(35);
    setColor(15);
    cout << string(8, char(32)) << char(186);

    //Period 5
    cout << "\n\t" << char(186) << string(8, char(32));
    setColor(11);
    printBracket(36);
    setColor(12);
    printBracket(37);
    setColor(13);
    printBracket(38);
    cout << string(18, char(32));
    printBracket(39);
    printBracket(40);
    printBracket(41);
    printBracket(42);
    printBracket(43);
    printBracket(44);
    printBracket(45);
    printBracket(46);
    printBracket(47);
    setColor(10);
    printBracket(48);
    printBracket(49);
    setColor(14);
    printBracket(50);
    printBracket(51);
    setColor(9);
    printBracket(52);
    setColor(12);
    printBracket(53);
    setColor(15);
    cout << string(8, char(32)) << char(186);

    //Period 6
    cout << "\n\t" << char(186) << string(8, char(32));
    setColor(11);
    printBracket(54);
    setColor(12);
    printBracket(55);
    setColor(11);
    printBracket(56);
    setColor(15);
    cout << char(196) << char(191) << string(16, char(32));
    setColor(13);
    printBracket(71);
    printBracket(72);
    printBracket(73);
    printBracket(74);
    printBracket(75);
    printBracket(76);
    printBracket(77);
    printBracket(78);
    printBracket(79);
    setColor(10);
    printBracket(80);
    printBracket(81);
    printBracket(82);
    printBracket(83);
    printBracket(84);
    setColor(12);
    printBracket(85);
    setColor(15);
    cout << string(8, char(32)) << char(186);

    //Period 7
    cout << "\n\t" << char(186) << string(8, char(32));
    setColor(11);
    printBracket(86);
    setColor(12);
    printBracket(87);
    printBracket(88);
    setColor(15);
    cout << char(191) << char(179) << string(1, char(32));
    setColor(13);
    printBracket(103);
    printBracket(104);
    printBracket(105);
    printBracket(106);
    printBracket(107);
    setColor(8);
    printBracket(108);
    printBracket(109);
    printBracket(110);
    printBracket(111);
    printBracket(112);
    printBracket(113);
    printBracket(114);
    printBracket(115);
    printBracket(115);
    printBracket(117);
    setColor(15);
    cout << string(8, char(32)) << char(186);


    //Line before Period 8
    cout << "\n\t" << char(186) << string(29, char(32)) << char(179) << char(179) << string(129, char(32)) << char(186);

    //Period 8
    cout << "\n\t" << char(186) << string(29, char(32)) << char(179) << char(192) << string(16, char(196));
    setColor(11);
    printBracket(57);
    printBracket(58);
    printBracket(59);
    printBracket(60);
    printBracket(61);
    printBracket(62);
    printBracket(63);
    printBracket(64);
    printBracket(65);
    printBracket(66);
    printBracket(67);
    printBracket(68);
    printBracket(69);
    printBracket(70);
    setColor(15);
    cout << string(15, char(32)) << char(186);

    //Period 9
    cout << "\n\t" << char(186) << string(29, char(32)) << char(192) << string(17, char(196));
    setColor(10);
    printBracket(89);
    printBracket(90);
    printBracket(91);
    printBracket(92);
    printBracket(93);
    printBracket(94);
    printBracket(95);
    printBracket(96);
    printBracket(97);
    printBracket(98);
    printBracket(99);
    printBracket(100);
    printBracket(101);
    printBracket(102);
    setColor(15);
    cout << string(11, char(32)) << char(186);

    cout << "\n\t" << char(186) << string(160, char(32)) << char(186);

    cout << "\n\t" << char(200) << string(160, char(205)) << char(188);
}


int main()
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    do
    {
        system("cls");
        printMenuPeriodicTable();
        cout << "\n\tCMPR121: Exam#1: Implementation using Dynamic Array, string/C-string, struct, and Binary File By YOURNAME "; //make sure to change to your name
        cout << "\n\t" << string(160, char(205));
        cout << "\n\t\t A) Advance Binary Data File (Chapter#12)";
        cout << "\n\t\t B) Dynamic Array (Chapter#9)";
        cout << "\n\t\t C) Vector (Chapter#7)";
        cout << "\n\t\t X) Xtra credits (5 pts)";
        cout << "\n\t" << string(160, char(196));
        cout << "\n\t\t Q) Quit (terminate) Program";
        cout << "\n\t" << string(160, char(205)) << "\n";

        switch (toupper(inputChar("\tOption: ", static_cast<string>("QABCX"))))
        {
        case 'Q': exit(0);
        case 'A': sectionA(); break; 
        case 'B': sectionB(); break; 
        case 'C': sectionC(); break; 
        case 'X': optionX(); break; 
        default:
            SetConsoleTextAttribute(color, 12);
            cout << "\n\tERROR: Invalid option.\n";
            SetConsoleTextAttribute(color, 15);
        }
        cout << "\n";
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
    string stateTypeName = "unknown";
    char stateType = toupper(element.stateType);
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
    
    switch (stateType)
    {
    case 'L':
        stateTypeName = "liquid";
        break;
    case 'S':
        stateTypeName = "solid";
        break;
    case 'G':
        stateTypeName = "gas";
        break;
    case 'U':
        stateTypeName = "unknown";
        break;
    default:
        break;
    }

   
    setColor(10); 
    cout << "\n\tAtomic # " << right << setw(8) << ": " << element.atomicNum; 
    cout << "\n\tSymbol " << right << setw(10) << ": " << element.symbol; 
    cout << "\n\tName " << right << setw(12) << ": " << element.name; 
    cout << "\n\tMass " << right << setw(12) << setprecision(3) << fixed << ": " << element.mass << " u"; 
    cout << "\n\tState type " << right << setw(6) << ": " << stateTypeName;
    cout << "\n\tGroup # " << right << setw(9) << setprecision(1) << ": " << element.groupNum; 
    cout << "\n\tPeriod # " << right << setw(8) << ": " << element.periodNum; 
    cout << "\n\tBlock type " << right << setw(7) << ": (" << block << ") " << blockTypeName;
    cout << "\n\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << element.meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K"; 
    cout << "\n\tBoiling point " << right << setw(3) << ": " << element.boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K"; 
    cout << "\n\tDiscovery year " << right << setw(2) << ": ";

    if (element.discoveryYear == 0) 
    {
        cout << "Prehistoric" << "\n";
    }
    else
    {
        cout << element.discoveryYear << "\n";
    }
    cout << "\tDiscovered by " << right << setw(3) << ": " << element.discoveredBy << "\n\n";
    setColor(15);
}


void displayAllElements(Element element[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        float kelvinm = 0.0;
        float farenheitm = 0.0;
        float kelvinb = 0.0;
        float farenheitb = 0.0;
        string blockTypeName = "unknown";
        char block = toupper(element[i].blockType); 
        string stateTypeName = "unknown";
        char stateType = toupper(element[i].stateType);
        string discoveryYear;
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

        kelvinm = element[i].meltingPoint + 273.15; 
        farenheitm = (element[i].meltingPoint * 1.8) + 32; 

        kelvinb = element[i].boilingPoint + 273.15; 
        farenheitb = (element[i].boilingPoint * 1.8) + 32; 


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

        switch (stateType)
        {
        case 'L':
            stateTypeName = "liquid";
            break;
        case 'S':
            stateTypeName = "solid";
            break;
        case 'G':
            stateTypeName = "gas";
            break;
        case 'U':
            stateTypeName = "unknown";
            break;
        default:
            break;
        }

        SetConsoleTextAttribute(color, 10);
        cout << "\tIndex[" << i << "]\n";
        cout << "\tAtomic # " << right << setw(8) << ": " << element[i].atomicNum << "\n"; 
        cout << "\tSymbol " << right << setw(10) << ": " << element[i].symbol << "\n"; 
        cout << "\tName " << right << setw(12) << ": " << element[i].name << "\n"; 
        cout << "\tMass " << right << setw(12) << setprecision(3) << fixed << ": " << element[i].mass << " u\n"; 
        cout << "\tState type " << right << setw(6) << ": " << stateTypeName << "\n"; 
        cout << "\tGroup # " << right << setw(9) << setprecision(1) << ": " << element[i].groupNum << "\n"; 
        cout << "\tPeriod # " << right << setw(8) << ": " << element[i].periodNum << "\n"; 
        cout << "\tBlock type " << right << setw(7) << ": (" << block << ") " << blockTypeName << "\n";
        cout << "\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << element[i].meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n"; 
        cout << "\tBoiling point " << right << setw(3) << ": " << element[i].boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n"; 
        cout << "\tDiscovery year " << right << setw(2) << ": ";
        if (element[i].discoveryYear == 0) 
        {
            cout << "Prehistoric" << "\n";
        }
        else
        {
            cout << element[i].discoveryYear << "\n"; 
        }
        cout << "\tDiscovered by " << right << setw(3) << ": " << element[i].discoveredBy << "\n\n"; 
        SetConsoleTextAttribute(color, 15);
    }
}

void displayAllElements(const vector<Element>& element) 
{
    for (size_t i = 0; i < element.size(); i++) 
    {
        float kelvinm = 0.0;
        float farenheitm = 0.0;
        float kelvinb = 0.0;
        float farenheitb = 0.0;
        string blockTypeName = "unknown";
        char block = toupper(element[i].blockType); 
        string stateTypeName = "unknown";
        char stateType = toupper(element[i].stateType);
        string discoveryYear;
        HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

        kelvinm = element[i].meltingPoint + 273.15;
        farenheitm = (element[i].meltingPoint * 1.8) + 32; 

        kelvinb = element[i].boilingPoint + 273.15; 
        farenheitb = (element[i].boilingPoint * 1.8) + 32; 

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
        switch (stateType)
        {
        case 'L':
            stateTypeName = "liquid";
            break;
        case 'S':
            stateTypeName = "solid";
            break;
        case 'G':
            stateTypeName = "gas";
            break;
        case 'U':
            stateTypeName = "unknown";
            break;
        default:
            break;
        }

        SetConsoleTextAttribute(color, 10);
        cout << "\tIndex[" << i << "]\n";
        cout << "\tAtomic # " << right << setw(8) << ": " << element[i].atomicNum << "\n"; 
        cout << "\tSymbol " << right << setw(10) << ": " << element[i].symbol << "\n"; 
        cout << "\tName " << right << setw(12) << ": " << element[i].name << "\n"; 
        cout << "\tMass " << right << setw(12) << setprecision(3) << fixed << ": " << element[i].mass << " u\n"; 
        cout << "\tState type " << right << setw(6) << ": " << stateTypeName << "\n"; 
        cout << "\tGroup # " << right << setw(9) << setprecision(1) << ": " << element[i].groupNum << "\n"; 
        cout << "\tPeriod # " << right << setw(8) << ": " << element[i].periodNum << "\n"; 
        cout << "\tBlock type " << right << setw(7) << ": (" << block << ") " << blockTypeName << "\n";
        cout << "\tMelting point " << right << setw(3) << setprecision(2) << fixed << ": " << element[i].meltingPoint << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K\n"; 
        cout << "\tBoiling point " << right << setw(3) << ": " << element[i].boilingPoint << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K\n"; 
        cout << "\tDiscovery year " << right << setw(2) << ": ";
        if (element[i].discoveryYear == 0) 
        {
            cout << "Prehistoric" << "\n";
        }
        else
        {
            cout << element[i].discoveryYear << "\n"; 
        }
        cout << "\tDiscovered by " << right << setw(3) << ": " << element[i].discoveredBy << "\n\n"; 
        SetConsoleTextAttribute(color, 15);
    }
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
    SetConsoleTextAttribute(color, 10);
    cout << "\n\tCONFIRMATION: " << count << " record(s) found. \n\n";
    SetConsoleTextAttribute(color, 15);
}

void sectionA_addElement(fstream& binaryFile, string fileBin, long atomicNum)
{
    Element element; 
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    element.atomicNum = static_cast <short> (atomicNum); 
    strncpy_s(element.symbol, inputString("\tSpecify the Element Symbol   : ", false).c_str(), sizeof(element.symbol) - 1); 
    strncpy_s(element.name, inputString("\tSpecify the Element Name     : ", false).c_str(), sizeof(element.name) - 1); 
    element.mass = static_cast<float> (inputDouble("\tSpecify the Element Mass     : ", true)); 
    element.stateType = inputChar("\tSpecify the Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU")); 
    element.groupNum = inputInteger("\tSpecify the Element Group # (0-unknown or 1...18) : ", 0, 18); 
    element.periodNum = inputInteger("\tSpecify the Element Period # (0-unknown or 1...7) : ", 0, 7); 
    element.blockType = inputChar("\tSpecify the Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF")); 
    element.meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) : "); 
    element.boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) : "); 
    element.discoveryYear = static_cast <short> (inputInteger("\tSpecify the Element Discovery Year : ", 0, 2025)); 
    strncpy_s(element.discoveredBy, inputString("\tSpecify the Element Discovered By  : ", true).c_str(), sizeof(element.discoveredBy) - 1); 

    binaryFile.write(reinterpret_cast<char*> (&element), sizeof(element)); 
    SetConsoleTextAttribute(color, 10);
    cout << "\n\tCONFIRMATION: A new element with Atomic # (" << element.atomicNum << ") has been added / appended into the binary data file, " << fileBin << " \n"; 
    SetConsoleTextAttribute(color, 15);
}


void sectionA_updateElement(Element element, fstream& binaryFile, string fileBin, int recNum, int count) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    Element temp; 

    temp = element; 

    do
    {
        system("cls");
        SetConsoleTextAttribute(color, 10);
        displayAllElements(temp);
        SetConsoleTextAttribute(color, 15);


        cout << "\n\tUpdating Element's information...";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 1) Symbol";
        cout << "\n\t 2) Name";
        cout << "\n\t 3) Atomic Mass";
        cout << "\n\t 4) State Type";
        cout << "\n\t 5) Group #";
        cout << "\n\t 6) Block Type";
        cout << "\n\t 7) Period Type";
        cout << "\n\t 8) Melting Point";
        cout << "\n\t 9) Boiling Point";
        cout << "\n\t10) Discovered Year";
        cout << "\n\t11) Discovered By";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t-1) Return WITHOUT change(s)";
        cout << "\n\t 0) Return WITH commited change(s)";
        cout << "\n\t" << string(80, char(205)) << "\n";


        switch (inputInteger("\tOption: ", -1, 11))
        {
        case 0:

            binaryFile.seekp(count * sizeof(temp), ios::beg);
            //// temp to original file. 
            element = temp; 
            //Writes to specified record
            binaryFile.write(reinterpret_cast<char*>(&element), sizeof(element));
            SetConsoleTextAttribute(color, 10);
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
            strncpy_s(temp.symbol, inputString("\tSpecify a new Element Symbol: ", false).c_str(), sizeof(temp.symbol) - 1);
            break;
        case 2:
            strncpy_s(temp.name, inputString("\tSpecify a new Element Name: ", false).c_str(), sizeof(temp.name) - 1);
            break;
        case 3:
            temp.mass = static_cast<float> (inputDouble("\tSpecify a new Element Mass: ", true));
            break;
        case 4:
            temp.stateType = inputChar("\tSpecify a new Element State type(S - solid, L - liquid, G - gas, or U - unknown) : ", static_cast<string>("SLGU"));
            break;
        case 5:
            temp.groupNum = inputInteger("\tSpecify a new Element Group # (0-unknown or 1...18) : ", 0, 18);
            break;
        case 6:
            temp.blockType = inputChar("\tSpecify a new Element Block type(S - sharp, P - principal, D - diffuse, or F - fundamental) : ", static_cast<string>("SPDF"));
            break;
        case 7:
            temp.periodNum = inputInteger("\tSpecify a new Element Period type (1...7) : ", 0, 7);
            break;
        case 8:
            temp.meltingPoint = inputDouble("\tSpecify the new Element Melting Point (celsius degree) : ");
            break;
        case 9:
            temp.boilingPoint = inputDouble("\tSpecify the new Element Boiling Point (celsius degree) : ");
            break;
        case 10:
            temp.discoveryYear = static_cast <short> (inputInteger("\tSpecify the new Element Discovery Year : ", 0, 2025));
            break;
        case 11:
            strncpy_s(temp.discoveredBy, inputString("\tSpecify the new Element Discovered By : ", true).c_str(), sizeof(temp.discoveredBy) - 1);
            break;
        }

    } while (true);

}

void sectionA_elementSearch(Element element, fstream& binaryFile, string fileBin, int count) 
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(color, 10);
    cout << "\n\tCONFIRMATION: The Element with Atomic # (" << element.atomicNum << ") is found at location " << count << "\n\n"; //cout << "\nCONFIRMATION: The Element with Atomic # (" << elements.atomicNum << ") is found at location #" << count << "\n";
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
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t1) Retrieve and display ALL element(s) from a binary data file";
        cout << "\n\t2) Add a new element to the binary data file";
        cout << "\n\t3) Update an existing element from the binary data file";
        cout << "\n\t4) Search for an element by atomic # from the binary data file";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t0) Return to main menu";


        cout << "\n\t" << string(80, char(205)) << "\n";
        switch (inputInteger("\tOption: ", 0, 4))
        {
        case 0:
            return;
        case 1:
            system("cls"); //clears the screen

            fileBin = inputString("\n\tSpecify a valid binary data file name to retrieve data from: ", false);
            binaryFile.open(fileBin, ios::in | ios::binary);
            if (!binaryFile)
            {
                SetConsoleTextAttribute(color, 12);
                cout << "\tERROR: File, " << fileBin << ", cannot be found.\n\n";
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
            cout << "\tDirectly add an element into the binary data file... \n";

            binaryFile.open(fileBin, ios::in | ios::out | ios::binary | ios::app);
            if (fileBin.empty())
            {
                SetConsoleTextAttribute(color, 12);
                cout << "\n\tERROR: Binary Data file has NOT been specified from Option #1. Please re-perform Option #1. \n\n";
                SetConsoleTextAttribute(color, 15);
            }
            else
            {

                cout << "\n\tAdding a new element information\n";
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
                recNum = static_cast<long>(inputInteger("\tSpecify the Element Atomic # to be searched : ", 1, 118));
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


int  sectionB_fileReadnStore(Element*& element, int& SIZE) 
{
    system("cls");
    Element item; 

    //prompt user for the file
    string fileNamePrompt = inputString("\n\tSpecify the binary file name to read from: ", false);

    ifstream myDataFileB1(fileNamePrompt, ios::binary);

    if (!myDataFileB1.is_open())
    {
        setColor(12);
        cout << "\n\tERROR: file " << fileNamePrompt << " cannot be found.\n\n";
        setColor(15);
        return 1;

    }


    myDataFileB1.seekg(0, ios::end); // this will always move to the end of the file 
    int myDataFileB1Size = myDataFileB1.tellg(); // basically gets the size

    SIZE = myDataFileB1Size / sizeof(Element); 

    element = new Element[SIZE]; 

    if (element == nullptr) 
        cout << "Mem check ";

    myDataFileB1.seekg(0, ios::beg); // back to the start 

    myDataFileB1.read(reinterpret_cast<char*>(element), SIZE * sizeof(Element)); 

    if (!myDataFileB1)
    {
        setColor(12);
        cout << "\n\tERROR READING FILE!" << endl;
        setColor(15);
        myDataFileB1.close();
    }

    myDataFileB1.close();
    setColor(10);
    cout << "\n\tCONFIRMATION: Data from binary file," << fileNamePrompt << "has been retrieved and stored into dynamic array.\n\n";
    setColor(15);

    return 0;
}


int sectionB_displayElement(Element*& element, int& SIZE) 
{
    system("cls");
    cout << "\tDisplay ALL element(s) from the dynamic array...\n\n";


    if (element == nullptr) 
        cout << "Mem check and or add elements ";

    if (SIZE == 0)
    {
        setColor(12);
        cout << "\n\tERROR: Dynamic array is empty. Therfore, no element can be displayed.\n\n";
        setColor(15);
        return 0;
    }

    displayAllElements(element, SIZE); 

    setColor(10);
    cout << "\n\t * Current size of the dynamic array : " << SIZE << "\n\n";
    setColor(15);

    return 0;

}

//Adding a new element information to the dynamic array...
int sectionB_addElement(Element*& element, int& SIZE) 
{
    system("cls");
    cout << "\n\tAdding a new element information to the dynamic array...\n";

    if (SIZE == 0)
    {
        setColor(0x0E);
        cout << "WARNING: Dynamic Array is empty. Therefore, a new dynamic array will be created.";
        setColor(15);// this is if they didn't run option1 

        short testAtomicNum = inputInteger("\n\n\tSpecify a new Element Atomic # : ", 1, 118);
        int tempSize = SIZE + 1;
        Element* newElements = new Element[tempSize];  // new array

        for (int i = 0; i < SIZE; ++i)
        {
            newElements[i] = element[i]; 
        }
        delete[] element; 

        newElements[SIZE].atomicNum = testAtomicNum;
        strncpy_s(newElements[SIZE].symbol, inputString("\tSpecify the Element Symbol  : ", false).c_str(), sizeof(newElements[SIZE].symbol) - 1);
        strncpy_s(newElements[SIZE].name, inputString("\tSpecify the Element Name    : ", false).c_str(), sizeof(newElements[SIZE].name) - 1);
        newElements[SIZE].mass = inputDouble("\tSpecify the Element Mass    : ", true);
        newElements[SIZE].stateType = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) : ", static_cast<string>("slgu"))));
        newElements[SIZE].groupNum = inputInteger("\tSpecify the Element Group # (0 - unknown or 1...18) : ", 0, 18);
        newElements[SIZE].periodNum = inputInteger("\tSpecify the Element Period # (0 - unknown or 1...7) : ", 0, 7);
        newElements[SIZE].blockType = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) : ", static_cast<string>("spdf"))));
        newElements[SIZE].meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) : "); //valdiate& change 
        newElements[SIZE].boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) : "); //validate
        newElements[SIZE].discoveryYear = inputInteger("\tSpecify the Element Discovery Year : ", 0, 2025);
        strncpy_s(newElements[SIZE].discoveredBy, inputString("\tSpecify the Element Discoverred By : ", true).c_str(), sizeof(newElements[SIZE].discoveredBy) - 1);

        SIZE++;
        element = newElements; 

        setColor(10);
        cout << "\n\tCONFIRMATION: A new element with Atomic # (" << testAtomicNum << ") has been added into the dynamic array.\n";
        setColor(15);

        // this is where the memory might be an issue test and run it this if function 
        return 0;
    }

    if (SIZE != 0)
    {


        short testAtomicNum = inputInteger("\n\tSpecify a new Element Atomic # : ", 1, 118);



        for (int i = 0; i < SIZE; i++)
        {
            if (testAtomicNum == element[i].atomicNum) 
            {
                setColor(12);
                cout << "\n\tERROR: Element with Atomic # " << testAtomicNum << " is already existed. Please perform other valid option.";
                setColor(15);
                return 1;
            }

        }
        int tempSize = SIZE + 1;
        Element* newElements = new Element[tempSize]; // new array 

        for (int i = 0; i < SIZE; ++i)
        {
            newElements[i] = element[i]; 
        }

        delete[] element; 

       
        newElements[SIZE].atomicNum = testAtomicNum;

        strncpy_s(newElements[SIZE].symbol, inputString("\tSpecify the Element Symbol :", false).c_str(), sizeof(newElements[SIZE].symbol) - 1);
        strncpy_s(newElements[SIZE].name, inputString("\tSpecify the Element Name :", false).c_str(), sizeof(newElements[SIZE].name) - 1);
        newElements[SIZE].mass = inputDouble("\tSpecify the Element Mass :", true);
        newElements[SIZE].stateType = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) :", static_cast<string>("slgu"))));
        newElements[SIZE].groupNum = inputInteger("\tSpecify the Element Group # (0 = unknown or 1...18) :", 0, 18);
        newElements[SIZE].periodNum = inputInteger("\tSpecify the Element Period # (0 = unknown or 1...7) :", 0, 7);
        newElements[SIZE].blockType = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) :", static_cast<string>("spdf"))));
        newElements[SIZE].meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) :"); //valdiate& change 
        newElements[SIZE].boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) :"); //validate
        newElements[SIZE].discoveryYear = inputInteger("\tSpecify the Element Discovery Year :", 0, 2025);
        strncpy_s(newElements[SIZE].discoveredBy, inputString("\tSpecify the Element Discoverred By :", true).c_str(), sizeof(newElements[SIZE].discoveredBy) - 1);


        SIZE++;
        element = newElements; 

        setColor(10);
        cout << "\n\tCONFIRMATION: A new element with Atomic # (" << testAtomicNum << ") has been added into the dynamic array.";
        setColor(15);
    }
    return 0;
}


// prompt user for changes change if need be
// the display changes as you adjust the element  
int sectionB_updateElement(Element*& element, int& SIZE) // maybe not an int 
{
    system("cls");

    cout << "\n\tDirectly Update a chemistry element information from the dynamic array...";

    if (SIZE == 0)
    {
        setColor(12);
        cout << "\n\n\tERROR: Dynamic array is empty and therefore no element can be updated.\n\n";
        setColor(15);
        return 1;
    }

    bool found = false;
    short a_num = inputInteger("\n\tSpecify an existing Element Atomic # :", 1, 118);
    system("cls");
    for (int i = 0; i < SIZE; i++)
    {
        if (a_num == element[i].atomicNum) 
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
                string stateTypeName = "unknown";
                char stateType = toupper(stateTypeB);
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

                switch (stateType)
                {
                case 'L':
                    stateTypeName = "liquid";
                    break;
                case 'S':
                    stateTypeName = "solid";
                    break;
                case 'G':
                    stateTypeName = "gas";
                    break;
                case 'U':
                    stateTypeName = "unknown";
                    break;
                default:
                    break;
                }

                SetConsoleTextAttribute(color, 10);
                cout << setw(20) << left << "\n\tAtomic #" << ": " << left << element[i].atomicNum; 
                cout << setw(20) << left << "\n\tSymbol " << ": " << left << symbolB;
                cout << setw(20) << left << "\n\tName " << ": " << left << nameB;
                cout << setw(20) << left << "\n\tMass" << setprecision(3) << fixed << ": " << left << massB << " u";
                cout << setw(20) << left << "\n\tState Type" << ": " << left << stateTypeName;
                cout << setw(20) << left << "\n\tGroup #" << ": " << left << groupNumB;
                cout << setw(20) << left << "\n\tPeriod #" << ": " << periodNumB;
                cout << setw(20) << left << "\n\tBlock Type" << ": (" << block << ") " << blockTypeName;
                cout << setw(20) << left << setprecision(2) << fixed << "\n\tMelting Point" << ": " << meltingPointB << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K";
                cout << setw(20) << left << setprecision(2) << fixed << "\n\tBoiling Point" << ": " << boilingPointB << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K";
                cout << setw(20) << left << "\n\tDiscovery Year" << ": ";

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
                cout << "\n\t10) Discoverred Year";
                cout << "\n\t11) Discoverred BY";
                cout << "\n\t" << string(100, (196)); //single line symbol
                cout << "\n\t-1) Return WITHOUT changes(s)";
                cout << "\n\t 0) Return WITH comitted change(s)";
                cout << "\n\t" << string(100, char(205));//double line symbol
                switch (inputInteger("\n\tOption: ", -1, 11))
                {
                case -1:
                    setColor(0x0E);
                    cout << "\n\tWarning: No update was committed.\n\n";
                    setColor(15);
                    return 0;
                case 1:strncpy_s(symbolB, inputString("\tSpecify the Element Symbol : ", false).c_str(), sizeof(symbolB) - 1); break;

                case 2:strncpy_s(nameB, inputString("\tSpecify the Element Name : ", false).c_str(), sizeof(nameB) - 1); break;

                case 3: massB = inputDouble("\tSpecify the Element Mass : "); break;

                case 4: stateTypeB = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) : ", static_cast<string>("slgu"))));; break;

                case 5: groupNumB = inputInteger("\tSpecify the Element Group # (1...18) : ", 1, 18); break;

                case 6: blockTypeB = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) : ", static_cast<string>("spdf")))); break;

                case 7: periodNumB = inputInteger("\tSpecify the Element Period # ( 1...7) : ", 1, 7); break; // prfessors is this "(1, 2, 3, 4, 5, 6, 7, L or A) "

                case 8: meltingPointB = inputDouble("\tSpecify the Element Melting Point (celsius degree) : "); break;

                case 9: boilingPointB = inputDouble("\tSpecify the Element Boiling Point (celsius degree) : "); break;

                case 10: discoveryYearB = inputInteger("\tSpecify the Element Discovery Year : ", 0, 2025); break;

                case 11: strncpy_s(discoveredByB, inputString("\tSpecify a new Element Discoverred By : ", boolalpha).c_str(), sizeof(discoveredByB) - 1); break;

                case 0:
                    element[i].symbol;
                    strncpy_s(element[i].symbol, symbolB, sizeof(element[i].symbol) - 1); 
                    element[i].name; 
                    strncpy_s(element[i].name, nameB, sizeof(nameB) - 1); 
                    element[i].mass = massB; 
                    element[i].stateType = stateTypeB; 
                    element[i].groupNum = groupNumB; 
                    element[i].blockType = blockTypeB; 
                    element[i].periodNum = periodNumB; 
                    element[i].meltingPoint = meltingPointB; 
                    element[i].boilingPoint = boilingPointB; 
                    element[i].discoveryYear = discoveryYearB; 

                    element[i].discoveredBy; 
                    strncpy_s(element[i].discoveredBy, discoveredByB, sizeof(discoveredByB) - 1); 

                    setColor(10);
                    cout << "\nCONFIRMATION: Element with Atomic # " << element[i].atomicNum << " has been updated into the dynamic array.\n";
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
bool sortDescending(const Element& a, const Element& b)
{
    return strcmp(a.symbol, b.symbol) > 0;
}

bool sortAscending(const Element& a, const Element& b) 
{
    return strcmp(a.symbol, b.symbol) < 0;
}

bool sortAscendingVector(const Element& a, const Element& b) 
{
    return strcmp(a.name, b.name) < 0;
}

int  sectionB_sortbySymbol(Element*& element, int& SIZE)  
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
        sort(element, element + SIZE, sortDescending);
        setColor(10);
        cout << "\n\n\tCONFIRMATION: Dynamic array has been sorted by Symbol in ascending order. Please perfrom Option#2 to display the sorted array.\n";
        setColor(15);
    }

}


int binarySearch(Element element[], int SIZE, const char* target)
{
    int left = 0;
    int right = SIZE - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int comparison = strcmp(element[mid].symbol, target); 

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

            left = mid + 1;   
        }

    }
    return -1;
}

int sectionB_binarySearchSymbol(Element*& element, int& SIZE)
{
    system("cls");
    cout << "\n\tSearching an element from a dynamic array by Symbol...";


    if (SIZE == 0)
    {
        setColor(12);
        cout << "\n\n\tERROR: Dynamic array is empty. Therefore, search cannot be performed.\n\n";
        setColor(15);
        return 1;
    }

    char testSymbol[3];
    strncpy_s(testSymbol, inputString("\n\n\tSpecify a Symbol of an element to search : ", boolalpha).c_str(), sizeof(testSymbol) - 1);

   
    sort(element, element + SIZE, sortDescending); // have to sort first  

    int result = binarySearch(element, SIZE, testSymbol); 
    if (result != -1)
    {
        setColor(10);
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

void arrayToFile(string filename, Element* element, int SIZE) 
{
    fstream file;
    file.open(filename, ios::binary | ios::out);
    for (int i = 0; i < SIZE; i++)

        file.write(reinterpret_cast<char*>(&element[i]), sizeof(element[i]));
    file.close();
}

int  sectionB_arraytoFile(Element*& element, int& SIZE) 
{
    system("cls");
    cout << "\n\tWriting elements from the dynamic array to binary data file...";


    if (SIZE == 0)
    {
        setColor(12);
        cout << "\n\n\tERROR: Dynamic array is empty. Therefore, write to file cannot be completed.\n\n";
        setColor(15);
        return 1;
    }
    string NameofFile = inputString("\n\n\tEnter a binary data file name to store elements: ", false);

   
    arrayToFile(NameofFile, element, SIZE);
    setColor(10);
    cout << "\n\tCONFIRMATION: Element(s) from dynamic array have been stored into file, " << NameofFile << ".\n\n";   
    setColor(15);
    return 0;

}


void sectionB()
{
    int SIZE = 0;
    
    Element* arrayOfElements = new Element[SIZE];

    do
    {
        system("cls"); //clears the screen
        cout << "\n\t Option B: Dynamic Array";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t1) Read element(s) from the binary data file and store into the dynamic array";
        cout << "\n\t2) Display element(s) from the dynamic array";
        cout << "\n\t3) Add a new chemistry element into the dynamic array";
        cout << "\n\t4) Update an existing chemistry element from the dynamic array";
        cout << "\n\t5) Sort the dynamic array by Symbol in descending order";
        cout << "\n\t6) Binary search an element by Symbol";
        cout << "\n\t7) Write elements from the dynamic array to the binary data file.";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t0. return to main menu";
        cout << "\n\t" << string(80, char(205)) << "\n";

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
        //cout << "\n\n";
        system("pause");
    } while (true);

    delete[] arrayOfElements; // double check 
}


int optionC1(vector<Element>& element)
{
    system("cls");
    cout << "\n\tRead data from binary file and store into vector...\n";

    string fileNamePrompt = inputString("\n\tEnter the binary file name to read from : ", false); // prompt user for the file 

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
    setColor(10);
    cout << "\n\tCONFIRMATION: Data from binary file, " << fileNamePrompt << ", has been retrieved and stored into the vector.\n\n";
    setColor(15);

    return 0;
}

int optionC2(vector<Element>& element) // maybe not an int 
{
    system("cls");
    cout << "\n\n\tDisplay ALL element(s) from the vector...";

    if (element.data() == 0)
    {
        setColor(12);
        cout << "\n\n\tERROR: The vector is empty. Therfore cannot display any element.\n\n";
        setColor(15);

        return 1;

    }
     
    cout << "\n\n\n";
    displayAllElements(element);


    setColor(10);
    cout << "\tSize : " << element.size() << "\n\n";
    setColor(15);
    return 0;
}


int optionC3(vector<Element>& element)
{


    system("cls");

    cout << "\tAdd a new element to the vector...\n\n";

    short atomicNumC;
    atomicNumC = inputInteger("\tSpecify the atomic # : ", 1, 118);

    for (int i = 1; i < 118; i++)
    {
        if (i == atomicNumC)
        {
            break;
        }
    }


    for (size_t i = 0; i < element.size(); i++)
    {
        if (atomicNumC == element[i].atomicNum)
        {
            setColor(12);
            cout << "\n\t ERROR: Element with atomic #(" << atomicNumC << ")is already existed in the vector at index[" << i << "]. Please perform other valid option.\n";
            setColor(15);
            return 1;
        }
    }


    for (size_t i = 0; i < element.size(); i++)
    {

        if (atomicNumC != element[i].atomicNum);
    }


    Element newElements;
    //changed it to one question
    newElements.atomicNum = atomicNumC;
    strncpy_s(newElements.symbol, inputString("\tSpecify the Element Symbol : ", false).c_str(), sizeof(newElements.symbol) - 1);
    strncpy_s(newElements.name, inputString("\tSpecify the Element Name :", false).c_str(), sizeof(newElements.name) - 1);
    newElements.mass = inputDouble("\tSpecify the Element Mass : ", true);
    newElements.stateType = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) : ", static_cast<string>("slgu")))); 
    newElements.groupNum = inputInteger("\tSpecify the Element Group # (0 - unknown or 1...18) : ", 0, 18);
    newElements.periodNum = inputInteger("\tSpecify the Element Period # (0 - unknown or 1...7) : ", 0, 7);
    newElements.blockType = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) : ", static_cast<string>("spdf"))));
    newElements.meltingPoint = inputDouble("\tSpecify the Element Melting Point (celsius degree) : "); //valdiate& change 
    newElements.boilingPoint = inputDouble("\tSpecify the Element Boiling Point (celsius degree) : "); //validate
    newElements.discoveryYear = inputInteger("\tSpecify the Element Discovery Year : ", 0, 2025);
    strncpy_s(newElements.discoveredBy, inputString("\tSpecify the Element Discoverred By : ", true).c_str(), sizeof(newElements.discoveredBy) - 1); //maybe tak eout sizeof100


    element.push_back(newElements);

    setColor(10);
    cout << "\n\tCONFIRMATION: A new element with Atomic # (" << atomicNumC << ") has been added into the dynamic array.\n\n";
    setColor(15);


    return 0;
}

// this code should update the element prompted 
int optionC4(vector<Element>& element)
{
    system("cls");
    cout << "\tUpdating an existing element from the vector...\n";


    if (element.data() == 0)
    {
        setColor(12);
        cout << "\n\tERROR: Vector is empty. Please perform other valid option.\n\n";
        setColor(15);
        return 1;
    }

    bool found = false;
    short a_num = inputInteger("\n\tSpecify the atomic #  to be updated :", 1, 118);


    for (size_t i = 0; i < element.size(); i++)
    {

        if (a_num == element[i].atomicNum) //this might need adjustment 
        {

            short atomicNumB = element[i].atomicNum;
            char symbolB[3];
            strncpy_s(symbolB, element[i].symbol, sizeof(symbolB) - 1);
            char nameB[25];
            strncpy_s(nameB, element[i].name, sizeof(nameB) - 1);
            float massB = element[i].mass;
            char stateTypeB = element[i].stateType;
            short groupNumB = element[i].groupNum;
            short periodNumB = element[i].periodNum;
            char blockTypeB = element[i].blockType;
            float meltingPointB = element[i].meltingPoint;
            float boilingPointB = element[i].boilingPoint;
            short discoveryYearB = element[i].discoveryYear;
            char discoveredByB[100];
            strncpy_s(discoveredByB, element[i].discoveredBy, sizeof(discoveredByB) - 1);
            do
            {
                system("cls");
                float kelvinm = 0.0;
                float farenheitm = 0.0;
                float kelvinb = 0.0;
                float farenheitb = 0.0;
                string blockTypeName = "unknown";
                char block = toupper(blockTypeB);
                string stateTypeName = "unknown";
                char stateType = toupper(stateTypeB);
                string discoveryYear;


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

                switch (stateType)
                {
                case 'L':
                    stateTypeName = "liquid";
                    break;
                case 'S':
                    stateTypeName = "solid";
                    break;
                case 'G':
                    stateTypeName = "gas";
                    break;
                case 'U':
                    stateTypeName = "unknown";
                    break;
                default:
                    break;
                }





                setColor(10);
                cout << "\n\tIndex[" << i << "]";
                cout << setw(20) << left << "\n\tAtomic #" << ": " << left << element[i].atomicNum;
                cout << setw(20) << left << "\n\tSymbol " << ": " << left << symbolB; // might need to checck if the input is the same 
                cout << setw(20) << left << "\n\tName " << ": " << left << nameB;
                cout << setw(20) << left << "\n\tMass" << ": " << left << setprecision(3) << fixed << massB << " u";
                cout << setw(20) << left << "\n\tState Type" << ": " << left << stateTypeName;
                cout << setw(20) << left << "\n\tGroup #" << ": " << left << groupNumB;
                cout << setw(20) << left << "\n\tPeriod #" << ": " << periodNumB;
                cout << setw(20) << left << "\n\tBlock Type" << ": (" << block << ") " << blockTypeName;
                cout << setw(20) << left << setprecision(2) << fixed << "\n\tMelting Point" << ": " << meltingPointB << "\370C; " << farenheitm << "\370F; " << kelvinm << "\370K";
                cout << setw(20) << left << setprecision(2) << fixed << "\n\tBoiling Point" << ": " << boilingPointB << "\370C; " << farenheitb << "\370F; " << kelvinb << "\370K";
                cout << setw(20) << left << "\n\tDiscovery Year" << ": ";

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




                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

                case 2:strncpy_s(nameB, inputString("\tSpecify the Element Name :", boolalpha).c_str(), sizeof(nameB) - 1); break;

                case 3: massB = inputDouble("\tSpecify the Element Mass :"); break;

                case 4: stateTypeB = (toupper(inputChar("\tSpecify the Element State type (S-solid, L-liquid, G-gas, or U-unknown) :", static_cast<string>("slgu"))));; break;

                case 5: groupNumB = inputInteger("\tSpecify the Element Group # (0 = unknown or 1...18) :", 0, 18); break;

                case 6: blockTypeB = (toupper(inputChar("\tSpecify the Element Block type (S-sharp, P-principal, D-diffuse, or F-fundamental) :", static_cast<string>("spdf")))); break;

                case 7: periodNumB = inputInteger("\tSpecify the Element Period # (0 = unknown or 1...7) :", 1, 7); break;

                case 8: meltingPointB = inputDouble("\tSpecify the Element Melting Point (celsius degree) :"); break;

                case 9: boilingPointB = inputDouble("\tSpecify the Element Boiling Point (celsius degree) :"); break;

                case 10: discoveryYearB = inputInteger("\tSpecify the Element Discovery Year :", 0, 2025); break;

                case 11: strncpy_s(discoveredByB, inputString("\tSpecify a new Element Discoverred By :", boolalpha).c_str(), sizeof(discoveredByB) - 1); break;

                case 0:

                    element[i].symbol; // this might not be needed as its passed argument 
                    strncpy_s(element[i].symbol, sizeof(element[i].symbol), symbolB, _TRUNCATE);

                    element[i].name;
                    strncpy_s(element[i].name, nameB, sizeof(nameB) - 1);

                    element[i].mass = massB;
                    element[i].stateType = stateTypeB;
                    element[i].groupNum = groupNumB;
                    element[i].blockType = blockTypeB;
                    element[i].periodNum = periodNumB;
                    element[i].meltingPoint = meltingPointB;
                    element[i].boilingPoint = boilingPointB;
                    element[i].discoveryYear = discoveryYearB;

                    element[i].discoveredBy;
                    strncpy_s(element[i].discoveredBy, discoveredByB, sizeof(discoveredByB) - 1);

                    setColor(10);
                    cout << "\nCONFIRMATION: Element with Atomic # " << element[i].atomicNum << " has been updated into vector.\n";
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
        cout << "\n\t ERROR: Element with Atomic#(" << a_num << ") does not existed in the vector. Please perform other valid option.\n\n";
        setColor(15);
        return 1;
    }
    return 0;
}


int optionC5(vector<Element>& element)
{
    system("cls");
    cout << "\tSort the vector by Name in ascending order...\n";

    if (element.data() == 0)
    {
        setColor(12);
        cout << "\n\tERROR: Vector is empty. Therefore, sort cannot be completed.\n";
        setColor(15);
        return 1;
    }

    sort(element.begin(), element.end(), sortAscendingVector);

    setColor(10);
    cout << "\n\tCONFIRMATION: Vector has been sorted by Name in ascending order. Please perform Option#2 to display the newly sorted vector.\n\n";
    setColor(15);
}

int binarySearchV(const vector<Element>& element, const char* target)
{
    int left = 0;
    int right = element.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

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

int optionC6(vector<Element>& element)
{
    system("cls");
    cout << "\tSearch an element from the the vector by Name...\n";


    if (element.data() == 0)
    {
        setColor(12);
        cout << "\n\tERROR: Vector is empty. Therefore, search can be performed.\n\n";
        setColor(15);
        return 1;
    }

    char nameC[25] = "UNK";
    strncpy_s(nameC, inputString("\n\n\tSpecify a Name of an element to search : ", boolalpha).c_str(), sizeof(nameC) - 1);


    sort(element.begin(), element.end(), sortAscendingVector);


    int result = binarySearchV(element, nameC);

    if (result != -1)
    {
        setColor(10);
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


void vectorToFile(string filename, vector<Element>& element)
{
    fstream file;
    file.open(filename, ios::binary | ios::out);

    for (size_t i = 0; i < element.size(); i++)
        file.write(reinterpret_cast<char*>(&element[i]), sizeof(element[i]));
    file.close();
}


int optionC7(vector<Element>& element)
{
    system("cls");
    cout << "\n\tWriting elements from the vector to binary data file...\n";

    if (element.data() == 0)
    {
        setColor(12);
        cout << "\n\tERROR: Vector is empty. Therefore, write to binary file cannot be completed.\n\n";
        setColor(15);
        return 1;
    }


    string NameofFile = inputString("\n\tEnter a binary data file name to store elements: ", false);


    vectorToFile(NameofFile, element);

    setColor(10);
    cout << "CONFIRMATION: ELements(s) from dynamic array have been stored into file, " << NameofFile << ".\n\n";
    setColor(15);

    return 0;
}


void sectionC()
{
    int SIZE = 0;

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
        cout << "\n\t 7) Store elements from the vector into the binary data file";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t 0) return";
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


void optionX()
{
    system("cls");


    setColor(15);
    cout << "\n\tSize of the Element structure and its members (NOT HARDCODED)...\n";
    setColor(10);
    cout << "\n\tElement                (total)    : " << sizeof(Element) << " bytes";
    cout << "\n\t\tAtomic #       (short)    :   " << sizeof(Element::atomicNum) << " bytes";
    cout << "\n\t\tSymbol         (c-string) :   " << sizeof(Element::symbol) << " bytes";
    cout << "\n\t\tName           (c-string) :  " << sizeof(Element::name) << " bytes";
    cout << "\n\t\tMass           (float)    :   " << sizeof(Element::mass) << " bytes";
    cout << "\n\t\tState type     (char)     :   " << sizeof(Element::stateType) << " byte";
    cout << "\n\t\tGroup #        (short)    :   " << sizeof(Element::groupNum) << " bytes";
    cout << "\n\t\tPeriod #       (short)    :   " << sizeof(Element::periodNum) << " bytes";
    cout << "\n\t\tBlock type     (short)    :   " << sizeof(Element::blockType) << " bytes";
    cout << "\n\t\tMelting point  (float)    :   " << sizeof(Element::meltingPoint) << " bytes";
    cout << "\n\t\tBoiling point  (float)    :   " << sizeof(Element::boilingPoint) << " bytes";
    cout << "\n\t\tDiscovery year (short)    :   " << sizeof(Element::discoveryYear) << " bytes";
    cout << "\n\t\tDiscoverred by (c-string) : " << sizeof(Element::discoveredBy) << " bytes\n\t";
    setColor(15);

    /*
    FOR REFERENCE

    char symbol[3];          // Symbol (H)
    char name[25];           // Name (Hydrogen)
    float mass;              // Atomic mass
    char stateType;          // State type ('s' for solid, 'l' for liquid, 'g' for gas)
    short groupNumber;       // Group number
    short periodNumber;      // Period number
    short blockType;         // Block type (1 for s-block, 2 for p-block, 3 for d-block, 4 for f-block)
    float meltingPoint;      // Melting point in Celsius
    float boilingPoint;      // Boiling point in Celsius
    short discoveryYear;     // Discovery year
    char discoveredBy[100];  // Discovered by
    */

}
