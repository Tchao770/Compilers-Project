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


	print(programFile);

	system("pause");
	return 0;
}