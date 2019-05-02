#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// This is the code what I have so far 
// It’s just a draft, not complete yet 

int main()
{
	string line;
	ifstream doc;
	ofstream output;
	doc.open("output.txt");
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
				
				if (line == "PROGRAM" || line == "VAR" || line == "BEGIN" || line == "END.")
				{
					output << "";
				}
				else if (line.compare(line.size()-8,7,"INTEGER") == 0)
				{
					output << line.substr(0, line.size() - 10) << ";" << endl;
				}
				else if (line.compare(0, 5, "PRINT") == 0)
				{
					
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
