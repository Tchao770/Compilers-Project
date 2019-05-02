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
			if (line[2] == 'O' )
				getline(doc, line);
				if (line[0] == 'V')
					getline(doc, line);
					output <<  line << endl;
					getline(doc, line);
					if(line[0] == 'B')
						getline(doc, line);
						output << line << endl;
						if (line[0] == 'P')
							output << "cout << "  << line <<   " << " << line << endl;
							getline(doc, line);
							if (line[0] == 'E')
								getline(doc, line);
							output << line << endl;


			
		}
		output << "return 0;" << endl;
		output << "}" << endl;
		doc.close();
		output.close();
	}
	return 0;
	
}