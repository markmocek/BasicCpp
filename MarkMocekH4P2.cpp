// Mark Mocek, Homework 4, 2/26/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class c
{
public:
	int data;
	c *prev, *next;
};
c *head = NULL, *last = NULL;

void main()
{
	srand(time(0));

	for (int ii = 0; ii < 1000; ii++)
	{
		c *n = new c;
		n->data = rand() % 10;
		n->next = NULL;
		n->prev = NULL;

		if (head == NULL)
		{
			head = n;
		}
		else
		{
			n->next = head;
			head->prev = n;
			head = n;
		}
	}

	for (c *p = head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;

	for (c *p = head; p != NULL; p = p->next)
	{
		c *temp;

		if (p->data % 2 != 0)
		{
			if (p == head)
			{
				temp = p->next;
				p->next->prev = NULL;
				delete p;
				p = temp;
			}
			else if (p->next == NULL)
			{
				temp = p->prev;
				p->prev->next = NULL;
				delete p;
				p = temp;
			}
			else
			{
				temp = p->prev;
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				p = temp;
			}
		}
	}

	for (c *p = head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}