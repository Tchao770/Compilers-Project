// Tommy Chao
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Function when beginning of line is a comment
string document(string line)
{
    return "";
}

// Handles all cases of the string including: extra spaces
// and proper spacing between punctuations
string converter(string line)
{
    string conv;
    int m = line.length();
    for(int i = 0; i < m; i++)
    {
        char n = line[i];

        // Remove tab
        if(line[i] == '\t')
            i++;
        
        // Remove newlines
        else if(line[i] == '\n')
            i++;
        
        // Removes all spaces unless it is between two alphabets
        else if(line[i] == ' ')
        {
            if(conv[i - 1] == ' ' || line[i + 1] == ' ')
                i++;
            else if(isalpha(line[i - 1]) && isalpha(line[i + 1]))
                conv += line[i];
        }

        // Removes comments by incrementing "i" until asterisk and parenthesis
        else if(line[i] == '(' && line[i + 1] == '*')
        {
            while(line[i] != ')')
                i++;
        }

        // Properly spaces comma
        else if(line[i] == ',')
        {
            if(line[i + 1] == ' ')
                conv += ", ";
            
            else if(line[i - 1] == ' ')
                conv += ", ";
        }
        
        // Add appropriate spaces between operators/punctuations
        else if(n == '=' || n == ':' || n == '+' || n == '/' || n == '-' || n == '*')
            conv = conv + ' ' + line[i] + ' ';
        
        // Append to string to be returned
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
