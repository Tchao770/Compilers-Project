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
		cout << "line 1: PROGRAM is expected" << endl;
	else if (str[1] != 'R')
		cout << "line 1: PROGRAM is expected" << endl;
	else if (str[2] != 'O')
		cout << "line 1: PROGRAM is expected" << endl;
	else if (str[3] != 'G')
		cout << "line 1: PROGRAM is expected" << endl;
	else if (str[4] != 'R')
		cout << "line 1: PROGRAM is expected" << endl;
	else if (str[5] != 'A')
		cout << "line 1: PROGRAM is expected" << endl;
	else if (str[6] != 'M')
		cout << "line 1: PROGRAM is expected" << endl;
	else if (str[7] != ' ')
		cout << "line 1: PROGRAM is expected" << endl;
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
			cout << "line 1: UNKNOWN IDENTIFIER" << endl;
	}
	//checks if the end of the string is a ';'
	if (str[str.length() - 1] == ';')
	{
	}
	else cout << "line 1: ';' is missing" << endl;
}
void var(vector<string> const &input)
{
	//Checks if VAR exists or is spelled wrong
	string str = input.at(1);
	if (str != "VAR")
		cout << "line 2: VAR is expected" << endl;
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
				cout << "line 3: ':' is missing"; break;
			}
			i++; i++;
			if (str[i] != 'I')
			{
				cout << "line 3: INTEGER is expected" << endl;
				break;
			} i++;
			if (str[i] != 'N')
			{
				cout << "line 3: INTEGER is expected" << endl;
				break;
			} i++;
			if (str[i] != 'T')
			{
				cout << "line 3: INTEGER is expected" << endl;
				break;
			} i++;
			if (str[i] != 'E')
			{
				cout << "line 3: INTEGER is expected" << endl;
				break;
			} i++;
			if (str[i] != 'G')
			{
				cout << "line 3: INTEGER is expected" << endl;
				break;
			} i++;
			if (str[i] != 'E')
			{
				cout << "line 3: INTEGER is expected" << endl;
				break;
			} i++;
			if (str[i] != 'R')
			{
				cout << "line 3: INTEGER is expected" << endl;
				break;
			} i++;
		}
		else
			cout << "line 3: UNKNOWN IDENTIFIER" << endl;
	}
	if (str[str.length() - 1] != ';')
		cout << "line 3: ';' is missing" << endl;

}

void checkBEGIN(vector<string> const &input)
{
	//Checks if BEGIN exists or is spelled wrong
	string str = input.at(3);
	if (str != "BEGIN")
		cout << "line 4: BEGIN is expected" << endl;
}
void statList(vector<string> const &input, vector<string>const &variable)
{
	string createVar = "";
	for (int ch = 4; ch < input.size() - 1; ch++)
	{
		string str = input.at(ch);
		//First check if its a PRINT function
		if (str[0] == 'P' && str[1] == 'R'  && str[2] == 'I' && str[3] == 'N' && str[4] == 'T')
		{
			//start checking after PRINT
			if (str[5] != '(')
			{
				cout << "line " << ch + 1 << ": '(' is missing" << endl;
			}
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
								cout << "line " << ch + 1 << ": ',' is missing" << endl;
							}

							j = i;
							break;

						}
						else if (i == str.size() - 1 && str[i - 1] != '\'')
						{
							cout << "line " << ch + 1 << ": ' is missing" << endl;
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
								cout << "line " << ch + 1 << ": IDENTIFIER NOT DEFINED" << endl;

							}
						}
					}
				}
				//check if the PRINT function ends with ");"
				if (j == str.size() - 1)
				{
					if (str[j] != ';')
					{
						cout << "line " << ch + 1 << ": ';' is missing" << endl;
						if (str[j] != ')')
						{
							cout << "line " << ch + 1 << ": ')' is missing" << endl;
						}
					}
					else if (str[j - 1] != ')')
					{
						cout << "line " << ch + 1 << ": ')' is missing" << endl;
					}
				}
			}
		}
		//Checking if it is an assign statement
		else if (str[0] != 'P' && str[1] != 'R'  && str[2] != 'I' && str[3] != 'N' && str[4] != 'T')
		{

			for (int k = 0; k < str.length(); k++)
			{
				//check if variable exists
				if (str[k] == 'a' || str[k] == 'b' || str[k] == 'c' || str[k] == 'd' || str[k] == 'e' || str[k] == 'f' || str[k] == '0' || str[k] == '1' || str[k] == '2' || str[k] == '3' || str[k] == '4' || str[k] == '5' || str[k] == '6' || str[k] == '7' || str[k] == '8' || str[k] == '9')
				{
					createVar.push_back(str[k]);

					if (str[k + 1] == ' ' || str[k + 1] == ';')
					{
						k++;
						for (int compare = 0; compare < variable.size(); compare++)
						{
							if (variable.at(compare) == createVar)
							{
								createVar = "";
								k++;
								break;
							}
							else if (compare == variable.size() - 1)
							{
								createVar = "";
								cout << "line " << ch + 1 << ": IDENTIFIER NOT DEFINED" << endl;
								k++;
								break;

							}
						}
						//check for assignment (=)
						if (str[k] != '=')
						{
							cout << "line " << ch + 1 << ": '=' is missing" << endl;
							break;
						}
						else
						{
							k++; k++;
							for (int l = k; l < str.length(); l++)
							{
								//check if variable exists
								if (str[l] == 'a' || str[l] == 'b' || str[l] == 'c' || str[l] == 'd' || str[l] == 'e' || str[l] == 'f' || str[l] == '0' || str[l] == '1' || str[l] == '2' || str[l] == '3' || str[l] == '4' || str[l] == '5' || str[l] == '6' || str[l] == '7' || str[l] == '8' || str[l] == '9')
								{
									createVar.push_back(str[l]);
									if (str[l + 1] == ' ' || str[l + 1] == ';')
									{
										for (int compare = 0; compare < variable.size(); compare++)
										{
											if (variable.at(compare) == createVar)
											{
												createVar = "";

												l++;
												if (str[l] == ';')
												{
													k = l;
													break;
												}
												l++;

												if (str[l] == '*' || str[l] == '+' || str[l] == '/' || str[l] == '-')
												{
													l++;
													k = l;
													break;
												}
											}
											//if it isn't a variable then check if its a digit
											else if (isdigit(createVar[0]))
											{
												createVar = "";
												l++;
												if (str[l] == ';')
												{
													k = l;
													break;
												}
												l++;

												if (str[l] == '*' || str[l] == '+' || str[l] == '/' || str[l] == '-')
												{
													l++;
													k = l;
													break;
												}

											}
											else if (compare == variable.size() - 1)
											{
												//checks after an identifier that has not been defined
												createVar = "";
												l++;
												cout << "line " << ch + 1 << ": IDENTIFIER NOT DEFINED" << endl;
												l++;
												if (str[l] == ';')
												{
													k = l;
													break;
												}
												if (str[l] == '*' || str[l] == '+' || str[l] == '/' || str[l] == '-')
												{
													l++;
													k = l;
													break;
												}
												k = l;
												break;
											}
										}
									}
								}
								else if (str[l] == ' ' && createVar != "" && str[l] != ';')
								{
									cout << "line " << ch + 1 << ": ERROR" << endl;
								}
								if (l == str.size() - 1)
								{
									if (str[l] != ';')
									{
										cout << "line " << ch + 1 << ": ';' is missing" << endl;
									}
								}
								//
							}
						}
					}
				}
				else
				{
					cout << "line " << ch + 1 << ": IDENTIFIER NOT DEFINED" << endl;
				}
			}
		}
		else
			//if PRINT is mispelled or unknown identifier
		{
			cout << "line " << ch + 1 << ": ERROR" << endl;
		}

	}
}

void checkEND(vector<string> const &input)
{
	//Check if END. exists or is spelled wrong
	string str = input.at(input.size() - 1);
	if (str != "END.")
		cout << "line " << input.size() << ": END. is expected" << endl;
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