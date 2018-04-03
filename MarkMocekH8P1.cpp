//Mark Mocek, HomeWork 8, 4/2/17
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

class StopWatchMicro_
{
private:
	LARGE_INTEGER last, frequency;
public:
	StopWatchMicro_()
	{
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&last);

	}
	long double elapse_micro()
	{
		LARGE_INTEGER now, dif;
		QueryPerformanceCounter(&now);
		dif.QuadPart = now.QuadPart - last.QuadPart;
		long double fdiff = (long double)dif.QuadPart;
		fdiff /= (long double)frequency.QuadPart;
		return fdiff*1000000.;
	}
	long double elapse_milli()
	{
		elapse_micro() / 1000.;
	}
	void start()
	{
		QueryPerformanceCounter(&last);
	}
};

int partition(int ar[], int hi, int lo)
{
	int pivot = ar[hi];
	int i = lo;

	for (int j = lo; j < hi; j++)
	{
		if (ar[j] <= pivot)
		{
			int temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;

			i = i + 1;
		}
	}

	int tmp = ar[i];
	ar[i] = ar[hi];
	ar[hi] = tmp;

	return i;
}

void quicksort(int ar[], int hi, int lo)
{
	if (lo < hi)
	{
		int p = partition(ar, hi, lo);
		quicksort(ar, p - 1, lo);
		quicksort(ar, hi, p + 1);
	}
}

void insertionSort(int ar[], int len)
{
	for (int ii = 1; ii < len; ii++)
	{
		int j = ii;

		while (j>0 && ar[j - 1] > ar[j])
		{
			int temp = ar[j];
			ar[j] = ar[j - 1];
			ar[j - 1] = temp;

			j = j - 1;
		}
	}
}

void bubbleSort(int ar[], int len)
{
	int swapped = 1;
	int j = 0;
	int tmp;
	while (swapped == 1)
	{
		swapped = 0;
		j++;
		for (int i = 0; i < len - j; i++)
		{
			if (ar[i] > ar[i + 1])
			{
				tmp = ar[i];
				ar[i] = ar[i + 1];
				ar[i + 1] = tmp;
				swapped = 1;
			}
		}
	}
	return;
}

void randomFiller(int ar[], int len)
{
	for (int ii = 0; ii < len; ii++)
	{
		ar[ii] = rand() % 100;
	}
}

void main()
{
	/*
	

	||===========||=======||=========||===========||===========||
	||   Sort    ||  100  ||  1,000  ||  10,000   ||  100,000  ||
	||===========||=======||=========||===========||===========||
	|| QuickSort || 13.87 || 196.64  || 5422.60   || 340076.00 ||
	||===========||=======||=========||===========||===========||
	|| Inerstion || 17.57 || 1419.07 || 191988.00 || 1.98e+7   ||
	||===========||=======||=========||===========||===========||
	||  Bubble   || 40.07 || 4184.46 || 399289.00 || 4.03e+7   ||
	||===========||=======||=========||===========||===========||

	Quicksort is the best in every category.
	Bubblesort is horrendously slow for large arrays.
	*/

	StopWatchMicro_ x;
	srand(time(0));
	int ar0[100], ar1[1000], ar2[10000], ar3[100000];

	//-------------ARRAY 100----------------
	randomFiller(ar0, 100);

	//QuickSort
	x.start();
	quicksort(ar0, 99, 0);
	cout << x.elapse_micro() << endl;

	randomFiller(ar0, 100);

	//Insertion Sort
	x.start();
	insertionSort(ar0, 100);
	cout << x.elapse_micro() << endl;

	randomFiller(ar0, 100);

	//Bubble Sort
	x.start();
	bubbleSort(ar0, 100);
	cout << x.elapse_micro() << endl;

	//------------ARRAY 1,000---------------
	randomFiller(ar1, 1000);

	//QuickSort
	x.start();
	quicksort(ar1, 999, 0);
	cout << x.elapse_micro() << endl;

	randomFiller(ar1, 1000);

	//Insertion Sort
	x.start();
	insertionSort(ar1, 1000);
	cout << x.elapse_micro() << endl;

	randomFiller(ar1, 1000);

	//Bubble Sort
	x.start();
	bubbleSort(ar1, 1000);
	cout << x.elapse_micro() << endl;

	//------------ARRAY 10,000---------------
	randomFiller(ar2, 10000);

	//QuickSort
	x.start();
	quicksort(ar2, 9999, 0);
	cout << x.elapse_micro() << endl;

	randomFiller(ar2, 10000);

	//Insertion Sort
	x.start();
	insertionSort(ar2, 10000);
	cout << x.elapse_micro() << endl;

	randomFiller(ar2, 10000);

	//Bubble Sort
	x.start();
	bubbleSort(ar2, 10000);
	cout << x.elapse_micro() << endl;

	//------------ARRAY 100,000---------------
	randomFiller(ar3, 100000);

	//QuickSort
	x.start();
	quicksort(ar3, 99999, 0);
	cout << x.elapse_micro() << endl;

	randomFiller(ar3, 100000);

	//Insertion Sort
	x.start();
	insertionSort(ar3, 100000);
	cout << x.elapse_micro() << endl;

	randomFiller(ar3, 100000);

	//Bubble Sort
	x.start();
	bubbleSort(ar3, 100000);
	cout << x.elapse_micro() << endl;
}