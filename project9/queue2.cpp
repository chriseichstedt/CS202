#include "queue2.h"
#include <iostream>

using namespace std;

//wrap queue

Queue :: Queue (int a)
{
	max = a;
	front = 0;
	rear = -1;
	data = new int[max];
	data[front] = 0;
}

Queue :: Queue(const Queue &a)
{
	max = a.max;
	data = new int[max];
	front = a.front;
	rear = a.rear;
	
	for(int i = 0; i < max; i++)
	{
		data[i] = a.data[i];
	}
}

Queue :: ~Queue()
{
	delete [] data;
	rear = max = front = 0;
	data = NULL;
}

Queue& Queue :: operator=(const Queue &a)
{
	max = a.max;
	front = a.front;
	rear = a.rear;
	
	for(int i = 0; i < max; i++)
	{
		data[i] = a.data[i];
	}
	
	return *this;
}

bool Queue :: enqueue(int a)
{
	if (full())
	{
		return false;
	}
	
	else
	{
		rear++;
		rear = rear%max;
		data[rear] = a;
		//data[rear%max] = a;
		return true;
	}
}

bool Queue :: dequeue(int &a)
{
	if (empty())
	{
		return false;
	}
	
	else
	{
		front++;
		front = front%max;
		a = data[front];
		//data[front%max] = a;
		return true;	
	}
}

bool Queue :: empty() const
{
	if(front == 0 && rear == -1)
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
	if(rear == -1)
	{
		return false;
	}
	
	int counter = rear + 1;
	
	if(counter%max == front)
	{
		return true;
	}
}

bool Queue :: clear()
{
	if (empty())
	{
		return false;
	}
	else
	{
		rear = -1;
		front = 0;
		return true;
	}
}

bool Queue :: operator==(const Queue &a) const
{
	if (max != a.max || front != a.front || rear != a.rear)
	{
		return false;
	}
	
	else
	{
		for(int i = 0; i < max; i++)
		{
			if(data[i] != a.data[i])
			{
				return false;
			}
		}
		
		return true;
	}
}

ostream& operator <<(ostream &out, const Queue &a)
{
	if (a.empty())
	{
		out << "the queue is empty" << endl;
	}
	
	else
	{
		int temp = a.front + 1;
		out << "(" << a.data[a.front] << ")" << " ";
		
		while(temp%a.max != a.rear)
		{
			out << a.data[temp%a.max] << " ";
			temp++;
			temp = (temp%a.max);
		}
		
		out << a.data[a.rear] << " ";
	}
	
	return out;
}
