#include "stack.h"
#include <iostream>

using namespace std;

Stack :: Stack(int size)
{
	data = new char[size];
	max = size - 1;
	top = -1;
	*data = '\0';
}

Stack :: Stack(const Stack &a)
{
	data = new char[a.max +1];
	max = a.max - 1;
	top = 0;
	*data = '\0';
}

Stack :: ~Stack()
{
	delete[] data;
	max = 0;
	top = 0;
	data = NULL;
}

Stack& Stack :: operator =(const Stack &a)
{
	max = a.max;
	top = a.top;
	
	for(int i = 0; i <= a.max + 1; i++)
	{
		data = NULL;
	}
}

bool Stack :: push(char a)
{
	if(full())
	{
		return false;
	}
	
	else
	{
		data[++top] = a;
		return true;
	}
}

bool Stack :: pop(char &a)
{
	if(empty())
	{
		return false;
	}
	
	else
	{
		a = data[top--];
		return true;
	}
}

bool Stack :: empty() const
{
	if (top < 0)
	{
		return true;
	}
	
	else 
	{
		return false;
	}
}

bool Stack :: full() const
{
	if (top == max)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool Stack :: clear()
{
	if (top == -1)
	{
		return false;
	}
	
	else
	{
		delete[] data;
		data = new char[max + 1];
	}
}

bool Stack :: operator ==(const Stack &a) const
{
	bool flag = false;
	
	do{
	
		if (max != a.max)
		{
			return false;
		}
		
		if (top != a.top)
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

ostream& operator <<(ostream &out,const Stack &a)
{	
	for(int i = a.top; i >= 0; i--)
	{
		if (i == a.top)
		{
			out << "(" << a.data[i] << ")" << endl;
		}
		
		else
		{
			out << a.data[i] << endl;
		}
	}
	
	return out;
}
