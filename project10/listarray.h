#include <iostream>
using namespace std;

template <typename T>
class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray<T>&);
    ~ListArray();

    bool insertBefore(const T&);
    bool insertAfter(const T&);
    bool get(T&) const;
    bool remove(T&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray<T>& operator = (const ListArray<T>&);

    template <typename S>
    friend ostream& operator << (ostream&, const ListArray<S>&);

private:
    T *data;
    int cursor;
    int actual;
    int size;
};

template <typename T>
ListArray<T> :: ListArray(int a)
{
	data = new T(a);
	cursor = -1;
	actual = 0;
	size = a;
}

template <typename T>
ListArray<T> :: ListArray(const ListArray<T> &a)
{
	data = new T(a.size);
	cursor = a.cursor;
	actual = a.actual;
	size = a.size;
	
	for(int i = 0; i < actual; i++)
	{
		data[i] = a.data[i];
	}
}

template <typename T>
ListArray<T> :: ~ListArray()
{
	delete[] data;
	cursor = actual = size = 0;
	data = NULL;
}

template <typename T>
bool ListArray<T> :: insertBefore(const T &a)
{
	if (isFull())
	{
		return false;
	}
	
	else
	{
		T temp;
		T temp2 = a;
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

template <typename T>
bool ListArray<T> :: insertAfter(const T &a)
{
	if (isFull())
	{
		return false;
	}
	
	else
	{
		T temp;
		T temp2 = a;
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

template <typename T>
bool ListArray<T> :: get(T &a) const
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

template <typename T>
bool ListArray<T> :: remove (T &a)
{
	if (isEmpty())
	{
		return false;
	}
	
	else
	{
		T temp;
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

template <typename T>
void ListArray<T> :: clear()
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

template <typename T>
bool ListArray<T> :: goToBeginning()
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

template <typename T>
bool ListArray<T> :: goToEnd()
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

template <typename T>
bool ListArray<T> :: goToNext()
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

template <typename T>
bool ListArray<T> :: goToPrior()
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

template <typename T>
bool ListArray<T> :: isEmpty() const
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

template <typename T>
bool ListArray<T> :: isFull() const
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

template <typename T>
ListArray<T>& ListArray<T> :: operator=(const ListArray<T> &a)
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

template <typename S>
ostream& operator <<(ostream &out, const ListArray<S> &a)
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

