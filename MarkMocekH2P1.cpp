// Mark Mocek, Homework 2, 2/12/17
#include <iostream>
#include <string>
using namespace std;

void main()
{
	int sNum, noE;

	char text[] = { "Hello World, this is an example of a long sentence." };

	sNum = strlen(text);

	cout << sNum << endl;

	noE = sNum;

	for (int ii = 0; ii < sNum; ii++)
	{
		if (text[ii] == 'e' || text[ii] == 'E')
			noE--;
	}

	char *p = new char[noE];

	noE = 0;

	for (int ii = 0; ii < sNum; ii++)
	{
		if (text[ii] == 'e' || text[ii] == 'E')
			continue;
		else
		{
			p[noE] = text[ii];
			noE++;
		}
	}

	for (int ii = 0; ii < noE; ii++)
	{
		cout << p[ii];
	}

	cout << endl;

	delete[] p;
}
