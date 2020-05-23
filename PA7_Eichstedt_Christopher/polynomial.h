#include <iostream>
#include <fstream>
using namespace std;

class polynomial
{
	public:
		polynomial ();
		polynomial (int, int*);
		polynomial (const polynomial&);
		~polynomial ();
		
		int solve(int);
		polynomial operator =(polynomial&);
		bool operator ==(polynomial&);
		bool operator !=(polynomial&);
		polynomial operator *(polynomial&);
		polynomial operator *(int);
		
		friend polynomial operator +(polynomial&, polynomial&);
		friend polynomial operator -(polynomial&, polynomial&);
		friend ostream& operator <<(ostream&, const polynomial&);
		friend ifstream& operator >>(ifstream&, polynomial&);
	private:
		int *coefficents;
		int maxDegree;
};
