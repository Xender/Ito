#include "../lines.h"

#include <fstream>
#include <iostream>
using namespace std;

void standard()
{
	ifstream in("lines-in.txt");

	string s;
	while(getline(in, s))
	{
		cout << "standard: " << s <<endl;
	}
}

void ito_lines()
{
	ifstream in("lines-in.txt");

	for(string/*  & ?  && ?  */ s : ito::lines(in))
	{
		cout << "ito_lines: " << s << endl;
	}
}

int main()
{
	standard();
	cout << endl;
	ito_lines();
}
