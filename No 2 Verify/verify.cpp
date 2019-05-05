#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
/*
<start> ->PROGRAM<pname>; VAR, dec - list>; BEGIN <stat - list> END.
<pname>     -> <id>
<id>        -> <letter>{<letter> | <digit>}
<dec - list>  -> <dec> : <type>
<dec>       -> <id>, <dec> | <id>

<stat - list> -> <stat>; | <stat>; <stat - list>
<stat>      -> <print> | <assign>
<print>     -> PRINT(<output>)
<output>    ->[“string”, } <id>
<assign>    -> <id> = <expr>

<expr>      -> <term> | <expr> +<term> | <expr> -<term>
<term>      -> <term> * <factor> | <term> / <factor> | <factor>
<factor>    -> <id> | <number> | <(<expr>)
<number>    -> <digit>{<digit>}
<type>      -> INTEGER
<digit>     -> 0 | 1 | 2 | … | 9
<letter>    -> a | b | c | d | e | f
*/

void print(vector<string> const &input)
{
	//prints a vector
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << endl;
	}
}

void start(vector<string> const &input)
{
	//Checks if PROGRAM exists or is spelled wrong
	string str = input.at(0);

	if (str[0] != 'P')
		cout << "PROGRAM is expected" << endl;
	else if (str[1] != 'R')
		cout << "PROGRAM is expected" << endl;
	else if (str[2] != 'O')
		cout << "PROGRAM is expected" << endl;
	else if (str[3] != 'G')
		cout << "PROGRAM is expected" << endl;
	else if (str[4] != 'R')
		cout << "PROGRAM is expected" << endl;
	else if (str[5] != 'A')
		cout << "PROGRAM is expected" << endl;
	else if (str[6] != 'M')
		cout << "PROGRAM is expected" << endl;
	else if (str[7] != ' ')
		cout << "PROGRAM is expected" << endl;
}
void pname(vector<string> const &input)
{
	string str = input.at(0);

	//starts after PROGRAM. check if every number/letter is vaild -> 0 | 1 | 2 | … | 9 | a | b | c | d | e | f
	for (int i = 8; i < str.length() - 1; i++) {
		if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e' || str[i] == 'f' || str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
		}
		else
			cout << "UNKNOWN IDENTIFIER" << endl;
	}
	//checks if the end of the string is a ';'
	if (str[str.length() - 1] == ';')
	{
	}
	else cout << "; is missing" << endl;
}
void var(vector<string> const &input)
{
	//Checks if VAR exists or is spelled wrong
	string str = input.at(1);
	if (str != "VAR")
		cout << "VAR is expected" << endl;
}

void decList(vector<string> const &input, vector<string>* variable)
{
	string str = input.at(2);
	string createVar = "";

	//starts after PROGRAM. check if every number/letter is vaild -> 0 | 1 | 2 | … | 9 | a | b | c | d | e | f
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e' || str[i] == 'f' || str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
			//creates a string to push into new vector
			createVar.push_back(str[i]);
		}
		else if (str[i] == ',')
		{
			//push string into new vector
			(*variable).push_back(createVar);
			createVar = "";
			i++;
		}
		else if (str[i] == ' ')
		{
			(*variable).push_back(createVar);
			createVar = "";
			i++;
			if (str[i] != ':')
			{
				cout << ": is missing"; break;
			}
			i++; i++;
			if (str[i] != 'I')
				cout << "not accepted" << endl; i++;
			if (str[i] != 'N')
				cout << "not accepted" << endl; i++;
			if (str[i] != 'T')
				cout << "not accepted" << endl; i++;
			if (str[i] != 'E')
				cout << "not accepted" << endl; i++;
			if (str[i] != 'G')
				cout << "not accepted" << endl; i++;
			if (str[i] != 'E')
				cout << "not accepted" << endl; i++;
			if (str[i] != 'R')
				cout << "not accepted" << endl; i++;
			if (str[i] != ';')
				cout << "; is missing" << endl;
			break;
		}
		else
			cout << "UNKNOWN IDENTIFIER" << endl;
	}

}

void checkBEGIN(vector<string> const &input)
{
	//Checks if BEGIN exists or is spelled wrong
	string str = input.at(3);
	if (str != "BEGIN")
		cout << "BEGIN is expected" << endl;
}
void statList(vector<string> const &input, vector<string>const &variable)
{
	string createVar = "";
	for (int i = 4; i < input.size() - 1; i++)
	{
		string str = input.at(i);
		//First check if its a PRINT function
		if (str[0] == 'P' && str[1] == 'R'  && str[2] == 'I' && str[3] == 'N' && str[4] == 'T' && str[5] == '(')
		{
			//start checking after PRINT
			for (int j = 6; j < str.size(); j++)
			{

				if (str[j] == '\'')
				{

					for (int i = 7; i < str.size(); i++)
					{
						if (str[i] == '\'')
						{
							i++;
							if (str[i] != ',')
							{
								cout << ", is missing" << endl;
							}
							j = i;


						}

					}

				}
				//Checking if variable was defined
				if (str[j] == 'a' || str[j] == 'b' || str[j] == 'c' || str[j] == 'd' || str[j] == 'e' || str[j] == 'f' || str[j] == '0' || str[j] == '1' || str[j] == '2' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '6' || str[j] == '7' || str[j] == '8' || str[j] == '9')
				{
					createVar.push_back(str[j]);

					if (str[j + 1] == ' ' || str[j + 1] == ')' || str[j + 1] == ',')
					{

						for (int compare = 0; compare < variable.size(); compare++)
						{
							if (variable.at(compare) == createVar)
							{
								createVar = "";
								break;
							}
							else if (compare == variable.size() - 1)
							{
								createVar = "";
								cout << "IDENTIFIER NOT DEFINED" << endl;

							}
						}
					}
				}
				//check if the PRINT function ends with ");"
				if (j == str.size() - 1)
				{
					if (str[j] != ';')
					{
						cout << "; is missing" << endl;
						if (str[j] != ')')
						{
							cout << ") is missing" << endl;
						}
					}
					else if (str[j - 1] != ')')
					{
						cout << ") is missing" << endl;
					}
				}
			}
		}
		//Checking if it is an assign statement
		else
		{
			//testing
			cout << "This is an assign test" << endl;
		}
	}
}

void checkEND(vector<string> const &input)
{
	//Check if END. exists or is spelled wrong
	string str = input.at(input.size() - 1);
	if (str != "END.")
		cout << "END. is expected" << endl;
}

int main()
{
	ifstream input;
	input.open("output.txt");
	//create a vector to hold output file from Part 1
	vector<string> programFile;
	vector<string> holdVariables;
	string str;
	// Read the next line from File until it reaches the end.
	while (getline(input, str))
	{
		// Line contains string of length > 0 then save it in vector
		if (str.size() > 0)
			programFile.push_back(str);
	}

	//prints vector
	//print(programFile);
	start(programFile);
	pname(programFile);
	var(programFile);
	decList(programFile, &holdVariables);
	//print variables created in output file
	//print(holdVariables);
	checkBEGIN(programFile);
	statList(programFile, holdVariables);
	checkEND(programFile);


	system("pause");
	return 0;
}