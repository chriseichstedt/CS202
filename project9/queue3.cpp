#include "queue3.h"
#include <iostream>

using namespace std;

//node queue

Node :: Node(int a, Node *b)
{
	data = a;
	next = b;
}

Queue :: Queue(int a)
{
	front = new Node(0, NULL);
	rear = new Node(0, NULL);
	front->next = rear;
}

Queue :: Queue(const Queue &a)
{
	front = a.front;
	rear = a.rear;
}

Queue :: ~Queue()
{
	front = NULL;
	rear = NULL;
}

Queue& Queue :: operator=(const Queue &a)
{
	front = a.front;
	rear = a.rear;
	
	return *this;
}

bool Queue :: enqueue(int a)
{
	Node *tempN = new Node(a, NULL);
	rear->next = tempN;
	rear = rear->next;
	tempN = NULL;
}

bool Queue :: dequeue(int &a)
{
	a = front->next->next->data;
	front = front->next;
}

bool Queue :: empty() const
{
	if(rear == front->next)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool Queue :: full() const
{
	return false;
}

bool Queue :: clear()
{
	if(empty())
	{
		return false;
	}
	
	else
	{
		front->next = rear;
		return true;
	}
}

bool Queue :: operator ==(const Queue &a) const
{
	bool flag = false;
	Node *temp1, *temp2;
	temp1 = new Node(front->next->next->data, front->next->next->next);
	temp2 = new Node(a.front->next->next->data, a.front->next->next->next);

	while (temp1 != NULL && temp2 != NULL)
	{
		if(temp1->data != temp2->data)
		{
			flag = true;
			return false;
		}
		else
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	return true;
}

ostream& operator <<(ostream &out, const Queue &a)
{
	if(a.empty())
	{
		out << "the queue is empty" << endl;
		return out;
	}
	
	else
	{
		Node *tempN;
		tempN = new Node(a.front->next->next->data, a.front->next->next->next);
	
		while (tempN != NULL)
		{
			out << tempN->data << " ";
			tempN = tempN->next;
		}
	}
		
		return out;
}
