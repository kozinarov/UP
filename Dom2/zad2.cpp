// zad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void Table(int N)
{
	int table[256];
	int num = 1;

	//Filling the arrray
	for (int i = 0; i < N*N; i++)
	{
		table[i] = num;
		num = num * 2;
	}

	//Show wath is in the array
	cout << "In table: ";
	for (int i = 0; i < N*N; i++)
	{
		cout << table[i] << " ";
	}
	cout << endl;

	//Making the partial sums
	int tempNum = 0;
	for (int i = 0; i < N*N; i++)
	{
		cout << tempNum << "; ";
		tempNum = tempNum + table[i];
	}

	//Show all the sums
	cout << tempNum << ";" << endl;
}

int main()
{
	int N;
	cout << "N:";
	cin >> N;

	Table(N);

    return 0;
}

