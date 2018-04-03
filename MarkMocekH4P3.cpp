// Mark Mocek, Homework 4, 2/26/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class c
{
public:
	int data;
	c *prev, *next, *top, *bot;
};
c *head = NULL, *ll = NULL;

void main()
{
	srand(time(0));
	int ff = 0, userIn = 0;

	for (int ii = 0; ii < 100; ii++)
	{
		ff++;

		c *n = new c;
		n->data = rand() % 10;
		n->next = NULL;
		n->prev = NULL;
		n->top = NULL;
		n->bot = NULL;

		if (head == NULL)
		{
			head = n;
			ll = n;
		}
		else if (ff < 11)
		{
			n->next = head;
			head->prev = n;
			head = n;
		}
		else if ((ff - 1) % 10 == 0)
		{
			n->bot = ll;
			ll = n;
			head = n;
		}
		else
		{
			n->next = head;
			head->prev = n;
			n->bot = head->bot->prev;
			head = n;
		}
	}

	while (userIn < 1 || userIn > 10)
	{
		cout << "Enter row to print(1-10): ";
		cin >> userIn;
	}

	c *tmp = head;

	for (int ii = 0; ii < userIn; ii++)
	{
		tmp = tmp->bot;
	}

	for (c *p = tmp; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
	userIn = 0;


	while (userIn < 1 || userIn > 10)
	{
		cout << "Enter column to print(1-10): ";
		cin >> userIn;
	}

	tmp = head;

	for (int ii = 0; ii < userIn; ii++)
	{
		tmp = tmp->next;
	}

	for (c *p = tmp; p != NULL; p = p->bot)
	{
		cout << p->data << " ";
	}
	cout << endl;
}