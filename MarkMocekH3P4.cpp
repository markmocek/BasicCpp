// Mark Mocek, Homework 3, 2/19/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class pal
{
public:
	char letr;
	pal *next;
};

char forward_Data(pal *head, int ff)
{
	int t = 0;
	for (pal *p = head; p != NULL; p = p->next)
	{
		if (t == ff)
			return p->letr;
		t++;
	}
}
char back_Data(pal *head, int ff)
{
	int t = 0;
	for (pal *p = head; p != NULL; p = p->next)
	{
		if (t == 4 - ff)
			return p->letr;
		t++;
	}
}

void main()
{
	pal *head = NULL, *p;
	int palin = 1;

	for (int ii = 0; ii < 5; ii++)
	{
		pal *n = new pal;

		cout << "Enter a letter: ";
		cin >> n->letr;

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
		cout << p->letr << " ";
	}
	cout << endl;

	for (int ii = 0; ii < 5; ii++)
	{
		if (forward_Data(head, ii) != back_Data(head, ii))
			palin = 0;
	}

	if (palin == 0)
		cout << "Not a palindrome." << endl;
	else
		cout << "Is a palindrome." << endl;
}