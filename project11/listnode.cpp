#include "listnode.h"
#include <iostream>

using namespace std;

Node :: Node(int a, Node *b)
{
	data = a;
	next = b;	
}

ListNode :: ListNode(int a)
{
	head = cursor = NULL;
	head = new Node(0, NULL);
	cursor = head;
}

ListNode :: ListNode(const ListNode &a)
{
	head = cursor = NULL;
	head = new Node(a.head->data, a.head->next);
	cursor = a.cursor;
}

ListNode :: ~ListNode()
{
	head = cursor = NULL;
}

bool ListNode :: insertBefore(int a)
{
	if (isFull())
	{
		return false;
	}
	
	else
	{
		if (cursor == head->next)
		{
			Node *temp = new Node(a, cursor);
			cursor = head;
			cursor->next = temp;
			cursor = temp;
			temp = NULL;
			return true;
		}
		
		else
		{
			Node *beforeCursor = new Node(head->data, head->next);
			Node *temp = new Node(a, cursor);
		
			while (beforeCursor->next != cursor)
			{
				beforeCursor = beforeCursor->next;
			}
		
			cursor = beforeCursor;
			cursor->next = temp;
			beforeCursor = NULL;
			cursor = temp;
			temp = NULL;
			return true;
		}
	}
}

bool ListNode :: insertAfter(int a)
{
	if (isFull())
	{
		return false;
	}

	else
	{
		Node *temp = new Node (a, cursor->next);
		cursor->next = temp;
		cursor = temp;
		temp = NULL;
	}
	
	return true;
}

bool ListNode :: get(int &a) const
{
	return a = cursor->data;
}

bool ListNode :: remove(int &a)
{
	if (head->next == cursor)
	{
		cursor = cursor->next;
		head->next = cursor;
		return true;
	}
	else
	{
		Node *temp = new Node (head->data, head->next);
	
		while (temp->next != cursor)
		{
			temp = temp->next;
		}
	
		a = cursor->data;
		cursor = cursor->next;
		temp->next = cursor;
		cursor = temp;
		temp = NULL;
		return true;
	}
}

void ListNode :: clear()
{
	head->next = NULL;
	cursor = head;
	return;
}

bool ListNode :: goToBeginning()
{
	if (cursor == head->next)
	{
		return false;
	}
	
	else
	{
		cursor = head->next;
		return true;
	}
}

bool ListNode :: goToEnd()
{
	if (cursor->next == NULL)
	{
		return false;
	}
	
	else
	{
		Node *temp = new Node(head->data, head->next);
	
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	
		cursor = temp;
		temp = NULL;
		return true;
	}
}

bool ListNode :: goToNext()
{
	cursor = cursor->next;
	return true;
}

bool ListNode :: goToPrior()
{
	Node *temp = new Node(head->data, head->next);
	
	while (temp->next != cursor)
	{
		temp = temp->next;
	}
	
	cursor = temp;
	temp = NULL;
	return true;
}

bool ListNode :: isEmpty() const
{
	if (head->next == NULL)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool ListNode :: isFull() const
{
	return false;
}

ListNode& ListNode :: operator=(const ListNode &a)
{
	head = a.head;
	cursor = a.cursor;
	return *this;
}

ostream& operator<< (ostream &out, const ListNode &a)
{
	if (a.head->next == NULL)
	{
		out << "the list is empty";
		return out;
	}
	
	else
	{
		Node *temp = new Node(a.head->next->data, a.head->next->next);
	
		while(temp != NULL)
		{
			out << "(" << temp->data << ")" << " ";
			temp = temp->next;
		}
		
		return out;
	}
}
