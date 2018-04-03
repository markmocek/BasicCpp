// Mark Mocek, Homework 1, 12/5/17
#include <iostream>
#include <string>
using namespace std;

void printingSentence(string sentence)
{
	for (int ii = 0; ii < sentence.size(); ii++)
	{
		cout << "Index: " << ii << " ";
		cout << "Pointer Position: " << &sentence+ii << " ";
		cout << "Letter: " << sentence[ii] << " " << endl;
	}
}

void main()
{
	string s;

	cout << "Enter a sentence: ";
	getline(cin, s);

	printingSentence(s);
}
