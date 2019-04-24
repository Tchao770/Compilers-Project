/*
Remove all documentation, blank lines, and extra spaces from the program.  
The program should look like the following.  You are going to use this 
program to check the grammar of each statement.
    PROGRAM aba13;
    VAR
    ab5, cb, be, eb : INTEGER;
    BEGIN
    ab5 = 5;
    cb = 10;
    PRINT(‘ab5=’, ab5);
    cb = cb + ab5;
    PRINT( cb );
    be = 2 * ab5 + eb;
    PRINT( be );
    END.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string document(string line)
{
    return "";
}
string converter(string line)
{
    string conv;
    int n = line.length();
    for(int i = 0; i < n; i++)
    {
        if(line[i] == '\t')
            i++;
        else if(line[i] == ' ' && line[i + 1] == ' ')
            cout << "oof";
        else
            conv += line[i];
    }
    return conv;
}

int main()
{
    string line;
    ifstream doc;
    ofstream output;
    bool comment;
    doc.open("final.txt");
    output.open("output.txt");
    if(doc.is_open() && output.is_open())
    {
        while(!doc.eof())
        {
            getline(doc, line);
            comment = (line[0] == '(') ? true : false;
            if(line[0] == '(' || comment)
            {
                output << document(line) << endl;;
            }
            else if(line[line.length() - 1] == ')' && comment)
            {
                comment = false;
                output << document(line) << endl;
            }
            else
                output << converter(line) << endl;
        }
        doc.close();
        output.close();
    }
    return 0;
}