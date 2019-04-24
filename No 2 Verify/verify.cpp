#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

string RESERVED[6] = {
    "PROGRAM", "VAR",   // 0 1
    "BEGIN", "END.",    // 2 3
    "INTEGER", "PRINT"  // 4 5
};

int main()
{
    ifstream input;
    input.open("");
    return 0;
}