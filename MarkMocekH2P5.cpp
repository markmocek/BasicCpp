// Mark Mocek, Homework 2, 2/12/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void fillArray(int *array, int size)
{
	for (int ii = 0; ii < size; ii++)
	{
		array[ii] = ii + 2;
		cout << array[ii] << " ";
	}
	cout << endl;
}

void cubeArray(int *array, int size)
{
	int temp;

	for (int ii = 0; ii < size; ii++)
	{
		array[ii] = array[ii] * array[ii] * array[ii];
		cout << array[ii] << " ";
	}
	cout << endl;
}

void deleteArray(int *array, int size)
{
	delete[] array;
}

void main()
{
	int size;

	cout << "Enter size of array: ";
	cin >> size;

	int *p = new int [size];

	fillArray(p,size);
	cubeArray(p, size);
	deleteArray(p, size);
}