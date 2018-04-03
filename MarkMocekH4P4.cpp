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
c *head = NULL, *last = NULL, *m = NULL;

void main()
{
	int palin = 0;

	for (int ii = 0; ii < 3; ii++)
	{
		c *n = new c;
		cout << "Enter a number(0-9): ";
		cin >> n->data;
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
		if (p->next == NULL)
			last = p;
	}

	m = head;
	while (m->next != NULL)
	{
		if (m->data != last->data)
		{
			palin = 1;
			break;
		}
		
		for (c *p = head; p != NULL; p = p->next)
		{
			if (p->next == last)
				last = p;
		}
		
		m = m->next;
	}


	for (c *p = head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;

	if (palin == 0)
	{
		cout << "Is a palindrome." << endl;
	}
	else
	{
		cout << "Is not a palindrome." << endl;
	}
}