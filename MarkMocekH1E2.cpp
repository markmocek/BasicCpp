// Mark Mocek, Homework 1, 12/5/17
#include <iostream>
using namespace std;

void swap_3(int *a, int *b, int *c)
{
	int d;

	if (*a > *b && *a > *c)
	{
		if (*c > *b)
		{
			d = *b;
			*b = *c;
			*c = d;
		}
	}
	else if (*b > *a && *b > *c)
	{
		if (*a > *c)
		{
			d = *a;
			*a = *b;
			*b = d;
		}
		else
		{
			d = *a;
			*a = *b;
			*b = *c;
			*c = d;
		}
	}
	else
	{
		if (*a > *b)
		{
			d = *a;
			*a = *c;
			*c = *b;
			*b = d;
		}
		else
		{
			d = *a;
			*a = *c;
			*c = d;
		}
	}
}

void main()
{
	int x, y, z;

	cout << "Enter three numbers: ";
	cin >> x;
	cin >> y;
	cin >> z;

	swap_3(&x, &y, &z);

	cout << "Ordered: " << x << " " << y << " " << z << endl;

}
