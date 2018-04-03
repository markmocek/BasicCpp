// Mark Mocek, HomeWork 7, 3/19/17
#include <iostream>
#include <time.h>
using namespace std;

void selectSort(int arr[], int x)
{
	for (int ii = 0; ii < x; ii++)				// (1; n+1; n)
	{
		int least = ii;							// n

		for (int ff = ii; ff < x; ff++)			// n*(1; log(n) + 1; log(n) 
		{
			if (arr[ff] < arr[least])			// n*(log(n))
			{
				least = ff;						// n*(log(n))
			}
		}

		int temp = arr[ii];						// n
		arr[ii] = arr[least];					// n
		arr[least] = temp;						// n
	}
}

void insertSort(int arr[], int x)
{
	int ff = 0, key = 0;

	for (int ii = 1; ii < x; ii++)				// (1; n+1; n)
	{
		key = arr[ii];							// n
		ff = ii - 1;							// n

		while ((ff >= 0) && (arr[ff] > key))	// n*(log(n))
		{
			arr[ff + 1] = arr[ff];				// log(n)
			ff -= 1;							// log(n)
		}

		arr[ff + 1] = key;						// n
	}
}

int findIndex(int arr[], int x, int y)
{
	for (int ii = 0; ii < x; ii++)
	{
		if (arr[ii] == y)
			return ii;
	}
}

void smallSequence(int arr[], int x)
{
	int lw = 0, hg = x, flg = 0;

	for (int ii = 0; ii < x; ii++)
	{
		for (int ff = ii; ff < x; ff++)
		{
			if (arr[ff] < arr[ii])
			{
				lw = ii;
				flg = 1;
				break;
			}
		}

		if (flg == 1)
			break;
	}

	int cHi = x - 1;
	flg = 0;

	for (int ii = x - 1; ii > lw; ii--)
	{
		for (int ff = ii; ff > lw; ff--)
		{
			if (arr[ff] > arr[ii])
			{
				cHi = ii;
				flg = 1;
				break;
			}
		}

		if (flg == 1)
			break;
	}

	cout << "Only need to sort between index " << lw << " and " << cHi << endl;
}

void main()
{
	srand(time(0));

//******************Exercise 1********************
	int arr[] = { 34,32,756,4,3,7,9,0,-12,44 };

	selectSort(arr, 10);

	for (int ii = 0; ii < 10; ii++)
		cout << arr[ii] << " ";

	cout << endl;




//******************Exercise 2********************
	int tha[1000];

	for (int ii = 0; ii < 1000; ii++)
	{
		tha[ii] = rand() % 101;
	}

	insertSort(tha, 1000);

	for (int ii = 0; ii < 1000; ii++)
		cout << tha[ii] << " ";

	cout << endl;



	
//******************Exercise 3********************
	/*
	Analyze selection sort and insertion sort with the Big-O notation.
	Comment your count on every codeline.
	What is the conclusion?

	1. Comments in functions
		Selection sort:
			2n + 2 + 4n + n*(4log(n) + 2)
			6n + 2 + 4nlog(n) + 2n
			~ 4nlog(n) + 8n + 2 ~
			O(nlog(n))
		Insert sort:
			2n + 2 + 3n +n*(3log(n))
			~ 3nlog(n) + 5n + 2 ~
			O(nlog(n))

	2. The two sorting algorithms are very similar in performance.
	*/




//******************Exercise 4********************
	int aNum[] = { 15, 16, 19, 20, 25, 1, 3 ,4 ,5 ,7, 10, 14 };

	cout << "The index of the number 1 is: " << findIndex(aNum, 12, 1) << endl;



//******************Exercise 5********************
	int semiSort[] = { 1,2,4,7,10,11,7,12,6,7,16,18,19 };

	smallSequence(semiSort, 13);

}