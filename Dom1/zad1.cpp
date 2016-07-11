// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool isIn(int x, int y)
{
	//4 quadrant
	if (y >= 0 && x <= 0 && x*x + y*y <= 3 * 3)
	{
		return true;
	}
	//1 quadrant
	else if (x >= 0 && x <= 3 && y >= 0 && y <= 3)
	{
		return true;
	}
	//2 quadrant
	else if (x >= 0 && y <= 0 && x*x + y*y <= 3 * 3)
	{
		return true;
	}
	//3 quadrant
	else if (x <= 0 && x >= -3 && y <= 0 && y >= -3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	float x;
	float y;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;

	if (isIn(x, y) == true)
	{
		cout << "It's in";
	}
	else 
	{
		cout << "It's out";
	}
	cout << endl;
	

    return 0;
}

