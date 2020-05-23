#include <iostream>
using namespace std;

class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray&);
    ~ListArray();

    bool insertBefore(const int&);
    bool insertAfter(const int&);
    bool get(int&) const;
    bool remove(int&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray& operator = (const ListArray&);
    friend ostream& operator << (ostream&, const ListArray&);

private:
    int *data;
    int cursor;
    int actual;
    int size;
};

ListArray :: ListArray(int a)
{
	data = new int[a];
	cursor = -1;
	actual = 0;
	size = a;
}

ListArray :: ListArray(const ListArray &a)
{
	data = new int[a.size];
	cursor = a.cursor;
	actual = a.actual;
	size = a.size;
	
	for(int i = 0; i < actual; i++)
	{
		data[i] = a.data[i];
	}
}

ListArray :: ~ListArray()
{
	delete[] data;
	cursor = actual = size = 0;
	data = NULL;
}

bool ListArray :: insertBefore(const int &a)
{
	if (isFull())
	{
		return false;
	}
	
	else
	{
		int temp;
		int temp2 = a;
		actual++;
		
		for(int i = cursor; i < size; i++)
		{
			if (i == cursor)
			{
				temp = data[i];
				data[i] = a;
			}
			
			else
			{
				temp2 = data[i];
				data[i] = temp;
				temp = temp2;
			}
		}
		
		return true;
	}
}

bool ListArray :: insertAfter(const int &a)
{
	if (isFull())
	{
		return false;
	}
	
	else
	{
		int temp;
		int temp2 = a;
		actual++;
		cursor++;
		
		for(int i = cursor; i < actual; i++)
		{
			if (i == cursor)
			{
				temp = data[i];
				data[i] = a;
			}
			
			else
			{
				temp2 = data[i];
				data[i] = temp;
				temp = temp2;
			}
		}
		
		return true;
	}
}

bool ListArray :: get(int &a) const
{
	if (isEmpty())
	{
		return false;
	}
	
	else
	{
		return a = data[cursor];
	}
}

bool ListArray :: remove (int &a)
{
	if (isEmpty())
	{
		return false;
	}
	
	else
	{
		int temp;
		temp = data[cursor];
		
		if (cursor == actual-1)
		{
			cursor = 0;
		}
		
		else
		{
			for (int i = cursor; i < (actual-1); i++)
			{
				data[i] = data[i+1];
			}
		}
		
		actual--;
		return true;
	}
}

void ListArray :: clear()
{
	if (isEmpty())
	{
		cout << "cannot clear when list is empty" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = '\0';
		}
		
		actual = 0;
		cursor = -1;
	}
}

bool ListArray :: goToBeginning()
{
	if (cursor == 0)
	{
		return false;
	}
	
	else
	{
		cursor = 0;
		return true;
	}
}

bool ListArray :: goToEnd()
{
	if (cursor == actual-1)
	{
		return false;
	}
	
	else
	{
		cursor = actual-1;
		return true;
	}
}

bool ListArray :: goToNext()
{
	if (cursor == (size-1))
	{
		return false;
	}
	
	else
	{
		cursor ++;
		return true;
	}
}

bool ListArray :: goToPrior()
{
	if (cursor == 0)
	{
		return false;
	}
	
	else
	{
		cursor --;
		return true;
	}
}

bool ListArray :: isEmpty() const
{
	if (actual == 0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool ListArray :: isFull() const
{
	if (actual == size)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

ListArray& ListArray :: operator=(const ListArray &a)
{
	cursor = a.cursor;
	actual = a.actual;
	size = a.size;
	
	for(int i = 0; i < actual; i++)
	{
		data[i] = a.data[i];
	}
	
	return *this;
}

ostream& operator <<(ostream &out, const ListArray &a)
{
	if (a.isEmpty())
	{
		out << "the list is empty" << endl;
	}
	
	else
	{
		for (int i = 0; i < a.actual; i++)
		{
			out << "(" << a.data[i] << ")" << " ";
		}
	}
	
	return out;
}

