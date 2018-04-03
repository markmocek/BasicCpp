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
	
	for (int ii = 0; ii < 100; ii++)
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
		
		if (p->next == NULL)
			last = p;
	}
	cout << endl;

	for (c *p = last; p != NULL; p = p->prev)
	{
		cout << p->data << " ";
	}
	cout << endl;
}