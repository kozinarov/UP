// zad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const double  gold = 1.618;
const double epsilon = 0.1;

void goldenRatio(double a, double b)
{
	double res;
	
	if (a > b)
	{
		res = a / b;
		//make res pozitive number
		if (res < 0)
			res = res*-1;

		if (res - gold <= epsilon)
		{
			cout << "True";
		}
		else
			cout << "False";
	}
	else if (b > a)
	{
		res = b / a;
		//make res positive number
		if (res < 0)
			res = res*-1;

		if (res - gold <= epsilon)
		{
			cout << "True";
		}
		else
			cout << "False";
	}

}

int main()
{	
	//Test numbers a = 5 and b = 3
	double a,b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	goldenRatio(a, b);
	cout << endl;
	
    return 0;
}

