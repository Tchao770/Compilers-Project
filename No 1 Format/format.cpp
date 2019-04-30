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
#include <algorithm>
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
        else if(line[i] == '\n')
            i++;
        else if(line[i] == ' ' && line[i + 1] == ' ')
            i++;
        else if(line[i] == '(' && line[i + 1] == '*')   //increment i until asterisk and parenthesis
            while(line[i] != ')')
            {
                //cout << "comment removal";
                i++;
            }
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

            if(line.empty())
                getline(doc, line);
            
            comment = (line[0] == '(' && line[1] == '*') ? true : false;
            if(comment)
            {
                while(line[line.length() - 1] != ')')
                {
                    getline(doc, line);
                    output << document(line);
                }
                comment = false;
            }
            else
                output << converter(line) << endl;
        }
        doc.close();
        output.close();
    }
    return 0;
}