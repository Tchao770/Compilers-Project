#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

// Struct to store the type and if there are multiple variable declarations
struct t_variable
{
    string type;
    list<string> variables;
};

// Parses line by spaces and exclude (') and (")
vector<string> separate(string line)
{
    int state = 0;
    vector<string> words;
    string temp;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ',' || line[i] == ';'){}
        
        else if (line[i] != ' ')
        {
            if(line[i] == '\'')
            {
                temp += line[i];
                i++;

                while(line[i] != '\'')
                {
                    temp += line[i];
                    i++;
                }
            }
            else
                temp += line[i];
        }
        else
        {
                words.push_back(temp);
                temp = "";
        }
    }
    words.push_back(temp);
    return words;
}

// Separate string vector and assigns to t_variable object
t_variable format(vector<string> sep, t_variable item)
{
    for (int i = 0; i < sep.size(); i++)
    {
        if (sep[i] == ":"){}
        else if (sep[i] == "INTEGER")
            item.type = "int";
        else
            item.variables.push_back(sep[i]);
    }
    return item;
}

// Create code string for variable declaration
string buildVar(t_variable item)
{
    string code = item.type;
    for (auto it = item.variables.begin(); it != item.variables.end(); it++)
        code = code + ' ' + (*it) + ',';
    code[code.length() - 1] = ';';
    return code;
}

// Print function that constructs appropriate cout statement and quotations
string buildPrint(vector<string> sep)
{
    string code = "cout << ";
    
    for(int i = 1; i < sep.size(); i++)
    {
        string compare = sep[i];
        
        if(compare[0] == '\'')
        {
            sep[i][0] = '"';
            code = code + sep[i] + "\" << ";
        }
        else if(sep[i] == ")"){}
        else
            code = code + sep[i];
    }
    code += ";";

    return code;
}

int main()
{
    vector<string> sep;
    t_variable item;
    string line;

    ifstream doc;
    ofstream output;
    doc.open("input.txt");

    if (doc.is_open())
    {
        string fileName;

        getline(doc, line);
        sep = separate(line);
        fileName = sep[1] + ".cpp";
        output.open(fileName);

        if (output.is_open())
        {
            if (sep[0] == "PROGRAM")
            {
                output << "#include <iostream>" << endl;
                output << "using namespace std;" << endl;
                output << "int main()" << endl;
                output << "{" << endl;
            }

            while (!doc.eof())
            {
                while (getline(doc, line))
                {
                    sep = separate(line);
                    /*
                    for (auto const &c : sep)
                        std::cout << c << " | ";
                    cout << endl;
                    */

                    // If line is VAR, read next line
                    if (line == "VAR")
                    {
                        getline(doc, line);
                        sep = separate(line);
                        output << buildVar(format(sep, item)) << endl;
                    }

                    // Do nothing if the  line begin with those word
                    else if (line == "BEGIN")
                        output << "";

                    //If the line begin with "Print"
                    else if (sep[0].find("PRINT") != string::npos)
                    {
                        output << buildPrint(sep) << endl;
                    }

                    else if (line == "END.")
                    {
                        output << "return 0;" << endl;
                        output << "}" << endl;
                    }

                    else
                        output << line << endl;
                }
            }
            doc.close();
            output.close();
        }
    }
    return 0;
}
