#include <iostream>
#include <fstream>
#include <string>
#include "includes/lexer.h"
using namespace std;
using namespace SeaMonkey;

int main()
{
	ifstream ifs("myfile.mky");
	string content((istreambuf_iterator<char>(ifs)),
		(istreambuf_iterator<char>()));
	
	Lexer l(content);
	vector<Token*>* tokenList = l.Tokenize();
	
	for (vector<Token*>::iterator it = tokenList->begin() ; it != tokenList->end(); ++it)
    	cout << "{Token." << (*it)->type << ", \"" <<  (*it)->literal << "\"}" << endl;
	return 0;
}


