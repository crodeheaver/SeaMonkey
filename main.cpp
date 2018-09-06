#include <iostream>
#include <fstream>
#include <string>
#include "includes/lexer.h"
using namespace std;
using namespace SeaMonkey;

int main()
{
	std::ifstream ifs("myfile.txt");
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	
	Lexer l(content);
	vector<Token*>* tokenList = l.Tokenize();
	
	for (vector<Token*>::iterator it = tokenList->begin() ; it != tokenList->end(); ++it)
    	cout << (*it)->literal << endl;
	return 0;
}


