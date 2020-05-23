#include <iostream>
#include "stackN.h"

using namespace std;

Stack :: Stack(int a)
{
	top = new Node('\0', NULL);
}

Stack :: Stack(const Stack &a)
{
	top = new Node(a.top->data, a.top->next);
}

Stack :: ~Stack()
{
	top = NULL;
}

Stack& Stack :: operator=(const Stack &a)
{
	top = new Node(a.top->data, a.top->next);
	return *this;	
}

bool Stack :: push(char a)
{
	if(!full())
	{
		Node *temp;
		temp = new Node(a, top);
		top = temp;
		temp = NULL;
		return true;
	}
	else
		return false;
}

bool Stack :: pop(char& a)
{
	if(!empty())
	{
		a = top->data;
		top = top -> next;
		return true;
	}
	else
		return false;
}

bool Stack :: empty() const
{
	if (top->next == NULL)
	{
		return true;
	}
	else
		return false;
}

bool Stack :: full() const
{
	return false;
}

bool Stack :: clear()
{
	top->next = NULL;
	top->data = '\0';
	return true;
}

bool Stack :: operator ==(const Stack &a) const
{
	bool flag = false;
	Node *temp1, *temp2;
	temp1 = new Node(top->data, top->next);
	temp2 = new Node(a.top->data, a.top->next);
	
	do{
		while (temp1->next != NULL && temp2->next != NULL)
		{
			if(temp1->data == temp2->data)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else
			{
				flag = true;
				return false;
			}
		}
	}while(!flag);
	return true;
}

ostream& operator <<(ostream &out, const Stack &a)
{
	Node *temp;
	temp = new Node(a.top->data, a.top->next);
	
	while (temp->next != NULL)
	{
		out << temp->data << " ";
		temp = temp->next;
	}
}
