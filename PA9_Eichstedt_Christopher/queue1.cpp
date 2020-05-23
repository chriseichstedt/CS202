#include "queue1.h"
#include <iostream>

using namespace std;

//stay queue

Queue :: Queue(int a)
{
	data = new int[a];
	data[0] = 0;
	max = a;
	front = 0;
	rear = -1;
}

Queue :: Queue(const Queue &a)
{
	data = new int[a.max];
	max = a.max;
	front = 0;
	rear = a.rear;
	
	for(int i = 0; i < a.max; i++)
	{
		data[i] = a.data[i];
	}
}

Queue :: ~Queue()
{
	delete[] data;
	max = 0;
	front = 0;
	rear = 0;
	data = NULL;
}

Queue& Queue :: operator=(const Queue &a)
{
	max = a.max;
	front = 0;
	rear = a.rear;
	
	for(int i = 0; i < a.max; i++)
	{
		data[i] = a.data[i];
	}
	
	return *this;
}

bool Queue :: enqueue(int a)
{
	if(full())
	{
		return false;
	}
	
	else
	{
		data[++rear] = a;
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
		a = data[front];
		
		for(int i = 0; i < rear; i++)
		{
			data[i] = data[i+1];
		}
		rear--;
		return true;
	}
}

bool Queue :: empty() const
{
	if (rear < 0)
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
	if (rear == max - 1)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool Queue :: clear()
{
	if(empty())
	{
		return false;
	}
	
	else
	{
		rear = -1;
		return true;
	}
}

bool Queue :: operator==(const Queue &a) const
{
	bool flag = false;
	
	do{
	
		if (max != a.max)
		{
			return false;
		}
		
		if (rear != a.rear)
		{
			return false;
		}
		
		for (int i = 0; i < max; i++)
		{
			if (data[i] == a.data[i])
			{
				flag = true;
			}
			
			else if(data[i] != a.data[i])
			{
				return false;
			}
		}
	}while(!flag);
	
	if(flag)
	{
		return true;
	}
}

ostream& operator <<(ostream &out,const Queue &a)
{	
	if(a.empty())
	{
		out << "the queue is empty" << endl;
		return out;
	}
	
	for(int i = 0; i <= a.rear; i++)
	{
		if (i == 0)
		{
			out << "(" << a.data[i] << ")" << " ";
		}
		
		else
		{
			out << a.data[i] << " ";
		}
	}
	
	return out;
}
