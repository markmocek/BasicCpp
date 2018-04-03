// Mark Mocek, Homework 3, 2/19/17
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class dog
{
public:
	char breed[20];
	dog *next;
};

void find_last_element(dog *head)
{
	for (dog *p = head; p != NULL; p = p->next)
	{
		if (p->next == NULL)
		{
			cout << "Last breed is: " << p->breed << endl;
		}
	}
}

void main()
{
	dog *head = NULL, *p, *head2 = NULL;

	for (int ii = 0; ii < 10; ii++)
	{
		dog *n = new dog;
		
		cout << "Enter dog breed: ";
		cin.getline(n->breed, 20);

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
		cout << p->breed << " ";
	}
	cout << endl;


	find_last_element(head);



	for (int ii = 0; ii < 10; ii++)
	{
		dog *n = new dog;

		if (head->next == NULL)
		{
			dog *C = head->next;

			for (int ii = 0; ii < 20; ii++)
			{
				n->breed[ii] = head->breed[ii];
			}

			delete C;
		}
		else
		{
			for (dog *p = head; p->next != NULL; p = p->next)
			{
				if (p->next->next == NULL)
				{
					for (int ii = 0; ii < 20; ii++)
					{
						n->breed[ii] = p->next->breed[ii];
					}
					dog* B = p->next;
					p->next = p->next->next;
					delete B;

					break;
				}
			}
		}
		n->next = NULL;

		if (head2 == NULL)
		{
			head2 = n;
		}
		else
		{
			for (p = head2; p != NULL; p = p->next)
			{
				if (p->next == NULL)
					break;
			}
			p->next = n;
		}
	}

	for (p = head2; p != NULL; p = p->next)
	{
		cout << p->breed << " ";
	}
	cout << endl;
}