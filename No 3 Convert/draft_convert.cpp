#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// This is the code what I have so far 
// It’s just a draft, not complete yet 
// you guys can run and check the ouput of ab13.cpp file

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
					if (line.compare(6, 1, "\"") == 0)
						output << "cout << "<< line.substr(6, 6) << " << "<< line.substr(line.size()-5,3) << ";" << endl;
					else
						output << "cout << "<< line.substr(line.size()-5,2) << ";" << endl;
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
