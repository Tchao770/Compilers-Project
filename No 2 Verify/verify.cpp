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
	if (str[0] != 'V')
		cout << "VAR is expected" << endl;
	else if (str[1] != 'A')
		cout << "VAR is expected" << endl;
	else if (str[2] != 'R')
		cout << "VAR is expected" << endl;
	else if (str[3] != NULL)
		cout << "VAR is expected" << endl;
}

void decList(vector<string> const &input)
{
	string str = input.at(2);

	//starts after PROGRAM. check if every number/letter is vaild -> 0 | 1 | 2 | … | 9 | a | b | c | d | e | f
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e' || str[i] == 'f' || str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
		{
		}
		else if (str[i] == ',') { i++; }
		else if (str[i] == ' ')
		{
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

void BEGIN(vector<string> const &input)
{
	//Checks if BEGIN exists or is spelled wrong
	string str = input.at(3);
	if (str[0] != 'B')
		cout << "BEGIN is expected" << endl;
	else if (str[1] != 'E')
		cout << "BEGIN is expected" << endl;
	else if (str[2] != 'G')
		cout << "BEGIN is expected" << endl;
	else if (str[3] != 'I')
		cout << "BEGIN is expected" << endl;
	else if (str[4] != 'N')
		cout << "BEGIN is expected" << endl;
	else if (str[5] != NULL)
		cout << "BEGIN is expected" << endl;
}

int main()
{
	ifstream input;
	input.open("output.txt");
	//create a vector to hold output file from Part 1
	vector<string> programFile;
	string str;
	// Read the next line from File untill it reaches the end.
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
	decList(programFile);
	BEGIN(programFile);


	system("pause");
	return 0;
}