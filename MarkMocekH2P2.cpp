// Mark Mocek, Homework 2, 2/12/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));

	int a[1000], noZero = 0;

	for (int ii = 0; ii < 1000; ii++)
	{
		a[ii] = rand() % 10;
	}

	for (int ii = 0; ii < 1000; ii++)
	{
		if (a[ii] == 0)
			continue;
		else
			noZero++;
	}

	int *p = new int [noZero];

	noZero = 0;

	for (int ii = 0; ii < 1000; ii++)
	{
		if (a[ii] == 0)
			continue;
		else
		{
			p[noZero] = a[ii];
			noZero++;
		}
	}

	for (int ii = 0; ii < noZero; ii++)
	{
		cout << p[ii] << " ";
	}

	cout << endl;

	delete[] p;
}
