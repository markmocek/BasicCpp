// Mark Mocek, Homework 3, 2/19/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class house
{
public:
	float area;
	house *next;
};

void main()
{
	house *head = NULL, *p;
	char inp[20];
	int exit = 0;
	float sm = 0;

	while (exit != 1)
	{
		cin.getline(inp, 20);

		if (inp == "end")
		{
			exit = 1;
		}
		else if (inp == "list")
		{
			cout << "List of areas: " << endl;

			for (p = head; p != NULL; p = p->next)
			{
				cout << p->area << " ";
			}
			cout << endl;
		}
		else if (inp == "remove smallest")
		{
			sm = head->area;

			for (p = head; p != NULL; p = p->next)
			{
				if (p->area < sm)
					sm = p->area;
			}

			if (head->area == sm)
			{
				house *B = head->next;
				delete head;
				head = B;
			}
			else
			{
				for(p = head; p->next != NULL; p = p->next)
				{
					if (p->next->area == sm)
					{
						house *B = p->next;
						p->next = p->next->next;
						delete B;
					}
				}
			}
			cout << "Removed " << sm << endl;
		}
		else
		{
			house *n = new house;

			cout << "Enter area: ";
			cin >> n->area;

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

			cout << "New house " << inp << " created. House has area of: " << n->area << endl;
		}
	}
}