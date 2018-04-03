// Mark Mocek, Homework 2, 2/12/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void deleteVar(int *arry, int size, int index)
{
	for (int ii = index; ii < size; ii++)
	{
		if (ii == size - 1)
			arry[ii] = 0;
		else
			arry[ii] = arry[ii + 1];
	}
}

int searchArray(int *arry, int size, int target)
{
	for (int ii = 0; ii < size; ii++)
	{
		if (arry[ii] == target)
		{
			deleteVar(arry, size, ii);

			return ii;
		}

		if (ii == size - 1)
			return -1;
	}
}

void main()
{
	int num = 5, target, indexT;

	int *p = new int[num];

	for (int ii = 0; ii < num; ii++)
	{
		p[ii] = ii + 1;
	}

	for (int ii = 0; ii < num; ii++)
	{
		cout << p[ii] << " ";
	}

	cout << endl << "Enter target number: ";
	cin >> target;

	indexT = searchArray(p, num, target);

	if (indexT == -1)
		cout << "Target not found." << endl;
	else
		cout << "Target found at index: " << indexT << endl;

	for (int ii = 0; ii < num; ii++)
	{
		cout << p[ii] << " ";
	}

	delete[] p;
}