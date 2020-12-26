// Lab_06_4.cpp
// < Кузів Назар >
// Лабораторна робота № 6.4-2
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 6

#include <iostream>
#include <time.h>
#include <string>
#include <iomanip> 

using namespace std;

void Create(int* a, const int size, const int Low, const  int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);

}

void Cout(int* a, const int size, int i)
{
	cout << setw(4)<< a[i];

	if (i < size - 1)
		Cout(a, size, i + 1);
	else
		cout <<"}"<< endl;
}

int SearchMin(int* a, const int size, int min, int i)
{
		if (a[i] < min)
		{
			min = a[i];
		}
		if(i < size-1)
			return SearchMin(a, size, min, i+1);
		else
			return min;
}

void CoutMin(int min)
{
	cout << "1.1) Min = " << min << endl;

}

int SearchFirst(int* a, const int size,int f, int i)
{
	if (a[i] > 0)
	{
		f = i;
		return f;
	}

	else
		if (i < size-1)

			return SearchFirst(a, size, f , i + 1);
	else
			return f;
}

int SearchLast(int* a, int f, int i,const int First)
{
	if (a[i] > 0 && i != First)
	{
		f = i;
		return f;
	}

	else
		if (i >= 0)

			return SearchLast(a, f, i - 1, First);
		else
			return f;
}

int Sum(int* a, int Last,int S, int i)
{
	S += a[i];

	if (i < Last-1)
		return Sum(a, Last, S, i + 1);
	else
		return S;
}

void CoutSum(int Sum)
{
	cout << "1.2) Sum = " << Sum << endl;
	cout << endl;
}

int SearchZero(int* a,const int size,int f, int i ) 
{
	if (a[i] == 0)
	{
		f = i;
		return f;
	}
	else
		if (i < size - 1)

			return SearchZero(a, size, f, i+1);
		else
			return f;
	
}

void Sort(int* a, const int size,int i)
{
	int z;

	for (int j = i + 1; j < size; j++)
	{
		if (a[j] == 0)
		{
			z = a[j];
			a[j] = a[i];
			a[i] = z;
		}
	}
	if (i < size - 1)
		Sort(a, size, i + 1);
}


int main()
{
	srand((unsigned)time(NULL));

	int Low, High, n, Min, f = -1, S = 0;

	cout << "Array size ="; cin >> n;

	int* a = new int[n];

	cout << "Low ="; cin >> Low;
	cout << "High ="; cin >> High;
	cout << endl;

	Create(a, n, Low, High, 0);

	cout << "a[] = {";
	Cout(a, n, 0);
	cout << endl;

	Min = a[0];
	Min = SearchMin(a, n, Min, 1);
	CoutMin(Min);
	cout << endl;

	 int First = SearchFirst(a, n, f, 0);
	 int Last = SearchLast(a, f, n - 1, First);

	cout << "First a[" << First << "] = " << a[First] << endl;
	cout << "Last a[" << Last << "] = " << a[Last] << endl;
	cout << endl;


	if (First == -1 || Last == -1)
	{
		cout << "Error" << endl;
		cout << endl;
	}
	else
	{	
		int i = First + 1;
		S = Sum(a, Last, S, i );
		CoutSum(S);
	}

	int zero = SearchZero(a, n, f, 0);

	if (zero == -1)
	{
		cout << "There are no zeros in this array" << endl;
		cout << endl;
	}
	else
	{
		Sort(a, n,0);

		cout << "a[] = {";
		Cout(a, n, 0);
		cout << endl;
	}

	return 0;
}

