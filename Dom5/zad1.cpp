// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


void PrintWhiteSpace1(int x)
{
	if (x == 1)
		return;

	if (x <= 10)
		cout << " ";

	else
		cout << "  ";
	return PrintWhiteSpace1(x - 1);
}

void PrintWhiteSpace2(int x)
{
	if (x <= 1)
		return;
	if (x < 10)
		cout << " ";
	else
		cout << "  ";

	return PrintWhiteSpace2(x - 1);
}

void PrintUp(int x, int y)
{
	if (x == 1)
		return;
	if (x == y)
	{
		cout << x;
		return;
	}
	cout << x;
	return PrintUp(x - 1, y);
}

void PrintDown(int x, int y)
{
	if (x == y)
	{
		cout << x;
		return;
	}
	cout << y;
	return PrintDown(x, y + 1);
}

void MainRecursion(int x, int cnt)
{
	if (x == cnt)
	{
		return;
	}
	PrintUp(x, x - cnt);
	PrintWhiteSpace1(x - cnt);
	PrintWhiteSpace2((x-1) - cnt);
	PrintDown(x, x - cnt);
	cout << endl;

	return MainRecursion(x, cnt + 1);
}



int main()
{
	int N;

	cin >> N;

	MainRecursion(N, 0);

	return 0;
}

