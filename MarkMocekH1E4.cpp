// Mark Mocek, Homework 1, 12/5/17
#include <iostream>
using namespace std;
/*
Write a function “analyze” which gets a float array, an integer which contains the size of the
array and 3 float addresses for the result :
 Calculate the average of all elements in the array.Store it in “avg”. (1 point)
 Calculate the maximum and minimum number in the array.Store it in “vmin” and
“vmax”. (1 point)
void analyze(float data[], int size, float *avg, float *vmin, float *vmax);
Sort the numbers from high to low.
To get the credits for this homework, proof the functionality in the main function.
*/

void analyze(float data[], int size, float *avg, float *vmin, float *vmax)
{
	*avg = 0;
	int ii;

	for (ii = 0; ii < size; ii++)
	{
		*avg = *avg + data[ii];
	}
	*avg = *avg / size;

	*vmin = data[0];
	for (ii = 0; ii < size; ii++)
	{
		if (*vmin > data[ii])
			*vmin = data[ii];
	}
	
	*vmax = data[0];
	for (ii = 0; ii < size; ii++)
	{
		if (*vmax < data[ii])
			*vmax = data[ii];
	}

	for (int ff = 0; ff < size; ff++)
	{
		float x = data[0], y;
		for (ii = 0; ii < size; ii++)
		{
			if (x >= data[ii])
			{
				x = data[ii];
			}
			else
			{
				data[ii - 1] = data[ii];
				data[ii] = x;
			}
		}
	}

}

void main()
{
	float data[5], avg, vmin, vmax;
	int size = 5;

	cout << "Enter five floats: ";

	for (int ii = 0; ii < 5; ii++)
	{
		cin >> data[ii];
	}

	analyze(data, size, &avg, &vmin, &vmax);

	cout << "Numbers: ";

	for (int ii = 0; ii < 5; ii++)
	{
		cout << data[ii] << " ";
	}

	cout << endl << "Average: " << avg << endl;
	cout << "Min: " << vmin << endl;
	cout << "Max: " << vmax << endl;

}
