// Mark Mocek, Homework 4, 2/26/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class c
{
public:
	int data;
	c *next;
};
c *head = NULL, *last = NULL, *thead = NULL;

void main()
{
	srand(time(0));

	for (int ii = 0; ii < 20; ii++)
	{
		c *n = new c;
		n->data = rand() % 10;
		n->next = NULL;

		if (head == NULL)
		{
			head = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
	}

	for (c *p = head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;

	//Order new linked list
	thead = head;
	head = NULL;

	while (thead != NULL)
	{
		int lwt = 99;

		//Set lowest value
		for (c *p = thead; p != NULL; p = p->next)
		{
			if (p->data < lwt)
				lwt = p->data;
		}

		//New node
		c *n = new c;
		n->data = lwt;
		n->next = NULL;

		if (head == NULL)
		{
			head = n;
		}
		else
		{
			n->next = head;
			head = n;
		}

		//Delete old node
		if (thead->data == lwt)
		{
			c *tmp = thead->next;
			delete thead;
			thead = tmp;
		}
		else
		{
			for (c *p = thead; p->next != NULL; p = p->next)
			{
				if (p->next->data == lwt)
				{
					c *D = p->next;
					p->next = p->next->next;
					delete D;
					break;
				}
			}
		}
	}

	cout << "List in reverse order: " << endl;

	for (c *p = head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;


	// Average
	int total = 0, cntr = 0;
	float avr = 0;

	for (c *p = head; p != NULL; p = p->next)
	{
		total = total + p->data;
		cntr++;
	}

	avr = float(total) / cntr;
	cout << "Average is: " << avr << endl;

	// Mean (center)
	int mid2 = 0, jj = 1, midD;
	float mid = 0, aMid;

	if (cntr % 2 == 0)
	{
		mid = cntr / 2;
		mid2 = mid + 1;
		for (c *p = head; p != NULL; p = p->next)
		{
			if (jj == mid)
			{
				midD = p->data;
			}
			if (jj == mid2)
			{
				midD = midD + p->data;
				aMid = float(midD) / 2;

				cout << "Mean is: " << aMid << endl;

				break;
			}
			jj++;
		}
	}
	else
	{
		mid = (float(cntr) / 2) + .5;

		for (c *p = head; p != NULL; p = p->next)
		{
			if (jj == mid)
			{
				cout << "Mean is: " << p->data << endl;
				break;
			}

			jj++;
		}
	}

	// Mode (most frequent)
	thead = head;
	int tnum = 0, tfrq = 0, mfrq = 0, mnum = 0;

	while(thead != NULL)
	{
		tnum = thead->data;

		for (c *p = head; p != NULL; p = p->next)
		{
			if (p->data == tnum)
			{
				tfrq++;
			}
		}

		if (tfrq > mfrq)
		{
			mfrq = tfrq;
			mnum = tnum;
		}

		thead = thead->next;
	}

	cout << "Mode is: " << mnum << endl;
}