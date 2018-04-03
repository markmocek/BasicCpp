// Mark Mocek, Homework 2, 2/12/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class dynamic_array
{
public:
	int *p;
	int size;

	dynamic_array()
	{
		p = NULL;
	}

	void make_array(int s)
	{
		if (p == NULL)
		{
			p = new int[s];
		}

		size = s;
	}

	void Remove_array()
	{
		delete[] p;
	}
};

void main()
{
	dynamic_array a;

	int x = 2;

	a.make_array(x);

	cout << a.size << endl;

	for (int ii = 0; ii < a.size; ii++)
	{
		a.p[ii] = ii;
		cout << a.p[ii] << " ";
	}

	cout << endl;

	a.Remove_array();
}