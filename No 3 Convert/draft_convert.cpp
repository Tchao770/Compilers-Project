#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;




int main()
{
	string line;
	ifstream doc;
	ofstream output;
	doc.open("draft_output.txt"); // This is a text file I used to translate
	output.open("abc13.cpp");
	if (doc.is_open() && output.is_open())
	{
		output << "#include <iostream>" << endl;
		output << "using namespace std;" << endl;
		output << "int main()" << endl;
		output << "{" << endl;
		output << "int ";
		while (!doc.eof())
		{
			getline(doc, line);
			while (getline(doc, line))
			{
				// Do nothing if the  line begin with those word
				if (line == "PROGRAM" || line == "VAR" || line == "BEGIN" || line == "END.")
				{
					output << "";
				}

				// If the last word in the line is Integer then print all the string before it 
				else if (line.compare(line.size()-8,7,"INTEGER") == 0)
				{
					output << line.substr(0, line.size() - 11) << ";" << endl;
				}

				//If the line begin with "Print"
				else if (line.compare(0, 5, "PRINT") == 0)
				{
					//If after the string "Print(" is double quote
					if (line.compare(6, 1, "\"") == 0)
						output << "cout << "<< line.substr(6, 8) << " << "<< line.substr(line.size()-5,3) << " << endl;" << endl;

					
					else
						output << "cout << "<<  line.substr(line.size() - 5, 2) << " << endl;" << endl;
				}
				else
					output << line << endl;
			}
		


			
		}
		output << "return 0;" << endl;
		output << "}" << endl;
		doc.close();
		output.close();
	}
	return 0;
	
}
