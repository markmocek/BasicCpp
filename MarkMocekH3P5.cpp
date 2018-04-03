// Mark Mocek, Homework 3, 2/19/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class lList
{
public:
	int num;
	lList *next;
};

int isInfinite(lList *head)
{
	int temp, counter;

	for (lList *p = head; p != NULL; p = p->next)
	{
		temp = p->num;
		counter = 0;

		for (lList *q = head; q != NULL; q = q->next)
		{
			if (temp == q->num)
				counter++;
			if (counter == 2)
			{
				cout << q->num << " repeated." << endl;
				return 1;
			}
		}
	}
	return 0;
}

void main()
{
	lList *head = NULL, *p;

	for (int ii = 0; ii < 10; ii++)
	{
		lList *n = new lList;

		cout << "Enter a number: ";
		cin >> n->num;

		n->next = NULL;

		if (head == NULL)
		{
			head = n;
		}
		else
		{
			for (p = head; p != NULL; p = p->next)
			{
				if (p->next == NULL)
					break;
			}
			p->next = n;
		}
	}

	for (p = head; p != NULL; p = p->next)
	{
		cout << p->num << " ";
	}
	cout << endl;

	if (isInfinite(head) == 0)
		cout << "Is an infinite loop." << endl;
	else
		cout << "Is not an infinite loop." << endl;
}