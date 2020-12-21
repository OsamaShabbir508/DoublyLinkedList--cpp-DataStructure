// C++ Dounbly Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
	int data;
    Node * pre;
	Node *next;
};
 Node *first,*t,*p,*last,*temp;

void CreateFirstNode(int n)
{
	first = new Node;
	last = first;
	first->data = n;
	first->pre = NULL;
	first->next = NULL;
	
}
void CreateBeforeFirst(int n)
{
	t = new Node;
	t->data = n;
	t->pre = first->pre;
	t->next = first;
	first->pre = t;

	first = t;

}
void CreatAtLast(int n)
{
	t = new Node;
	t->data = n;
	t->next = last->next;
	last->next = t;
	t->pre = last;
	last = t;
}
void CreateNodeAtAnyGivenPossition(int n, int poss)
{
	int x=0;
	p = first;
	if (poss > 0)
	{
		while (p != NULL && x < (poss - 2))
		{
			p = p->next;
			x++;

		}

		if (p == NULL)
		{
			cout << " The Possition you have given me is not found in the very linked list: thank u!" << endl;
		}
		else
		{
			t = new Node;
			t->next = p->next;
			p->next->pre = t;
			p->next = t;
			t->pre = p;
			t->data = n;
		}
	}
	else
	{
		cout << " You want to create a Node at posstion 0, for that u have another separate function.";
		cout << "how ever the linked list is here"<< endl;
	}
}
void DeleteA_NodeAtPossition(int n)
{
	int x=1;
	if (n == 0)
	{
		p = first;
		p = p->next;
		delete first;
		first = p;
	}
	else
	{
		p = first;
		while (p!=NULL && x<n)
		{
			t = p;
			p = p->next;
			x++;
			
		}
		if (p!=NULL)
		{
			t->next = p->next;
			p->next->pre = t;
			delete p;
		}
		else
		{
			cout << "The possition you have entered to delete is not in linked list" << endl;
		}

	}

}
void DeleteAtLat()
{
	last->pre->next = NULL;
	p= last->pre;
	delete last;
	last = p;
}
void ReverseLinkedList()
{
	p = first;
	while (p!=NULL)
	{
		temp = p->next;
		p->next = p->pre;
		p->pre = temp;
		p = p->pre;
		
		if (p!=NULL && p->next==NULL)
		{
			first = p;

		}

	}

}

void Display(Node *n)
{
	p = n;
	while (p!= NULL)
	{	cout << p->data;
		cout << " ";
		p = p->next;
	}
}


int main()
{
	int y;
	CreateFirstNode(50);
	CreateBeforeFirst(20);
	CreateBeforeFirst(10);
	CreateBeforeFirst(6);
	CreateBeforeFirst(4);
	CreateNodeAtAnyGivenPossition(5, 100);
	CreatAtLast(100);
	DeleteA_NodeAtPossition(4);
	Display(first);
	cout << endl;
	DeleteAtLat();
	Display(first);
	cout << endl;
	ReverseLinkedList();
	cout << endl;
	Display(first);

	cin >> y
		;
	
    return 0;
}

 

