// Mark Mocek, Homework 3, 2/19/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class taxpayer
{
public:
	char name[100];
	taxpayer *next;
};

taxpayer * find_last_element(taxpayer *head)
{
	for (taxpayer *p = head; p != NULL; p = p->next)
	{
		if (p->next->next == NULL)
		{
			taxpayer *T = p->next;
			p->next = p->next->next;
			return T;
		}
	}
}

void main()
{
	taxpayer *head = NULL, *p;

	for (int ii = 0; ii < 5; ii++)
	{
		taxpayer *n = new taxpayer;

		cout << "Enter name: ";
		cin.getline(n->name, 20);

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
		cout << p->name << " ";
	}
	cout << endl;

	while (head != NULL)
	{
		if (head->next == NULL)
		{
			taxpayer *D = head->next;
			delete head;
			head = D;
		}
		else 
		{
			taxpayer *D = find_last_element(head);
			delete D;
		}
	}
}