// Mark Mocek, Homework 1, 12/5/17
#include <iostream>
using namespace std;

void arraycpy(int *array_a, int *array_b, int size)
{
	for (int ii = 0; ii < size; ii++)
	{
		*(array_b + ii) = *(array_a + ii);
	}

}

void main()
{
	int a[5], b[5];

	cout << "Enter five numbers: ";

	for (int ii = 0; ii < 5; ii++)
	{
		cin >> a[ii];
	}

	arraycpy(a, b, 5);

	for (int ii = 0; ii < 5; ii++)
	{
		cout << b[ii] << " ";
	}

	cout << endl;
}
