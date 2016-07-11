// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Square(int N)
{
	//Printing first line
	if (N > 9)
	{//For bigger then one digit
		for (int i = 1; i <= N; i++)
			cout << setw(2) << i;
	}
	else
	{
		for (int i = 1; i <= N; i++)
			cout << i;
	}
	cout << endl;
	//cnt for the midle
	int cnt = 0;
	//Cheking for even or odd
	if (N % 2 == 0)
	{
		cnt = (N / 2) - 1;
	}
	else
		cnt = N / 2;

	int numberFront = 2;
	int numberBack = N - 1;
	int cntSpace = 0;
	int cntSpaceMidle = N - 4;
	//Printing the decreases of the numbers(the up side)
	while (cnt > 0)
	{
		if (N > 9)
		{//For bigger then one digit
			cout << setw(2) << "1";
			for (int i = 0; i < cntSpace; i++)
				cout << setw(2) <<  " ";
			
			cout << setw(2) << numberFront;

			for (int i = 0; i < cntSpaceMidle; i++)
				cout << setw(2) << " ";
	
			if (numberFront != numberBack)
				cout << setw(2) << numberBack;
	
			for (int i = 0; i < cntSpace; i++)
				cout << setw(2) << " ";
	
			cout << setw(2) << N << endl;
	
			numberFront++, numberBack--, cntSpace++, cntSpaceMidle--, cntSpaceMidle--, cnt--;
		}
		else
		{
			cout << "1";
			for (int i = 0; i < cntSpace; i++)
				cout << " ";

			cout << numberFront;

			for (int i = 0; i < cntSpaceMidle; i++)
				cout << " ";

			if (numberFront != numberBack)
				cout << numberBack;

			for (int i = 0; i < cntSpace; i++)
				cout << " ";

			cout << N << endl;

			numberFront++, numberBack--, cntSpace++, cntSpaceMidle--, cntSpaceMidle--, cnt--;

		}
	}


	//Cheking for even to print the midle line a second time
	if (N % 2 == 0)
	{
		int cntSpaceOdd = (N - 4) / 2;
		if (N > 9)
		{	
			//For bigger then one digit
			cout << setw(2) << 1;
			for (int i = 0; i < cntSpaceOdd; i++)
				cout << setw(2) << " ";
			cout << setw(2) << N / 2;
			cout << setw(2) << (N / 2) + 1;
			for (int i = 0; i < cntSpaceOdd; i++)
				cout << setw(2) << " ";
			cout << setw(2) << N << endl;
		}
		else
		{
			cout << 1;
			for (int i = 0; i < cntSpaceOdd; i++)
				cout << " ";
		//	cout << N / 2;
			cout << (N / 2) + 1;
			for (int i = 0; i < cntSpaceOdd; i++)
				cout << " ";
			cout << N << endl;
		}
	}

	//Cheking for even or odd
	if (N % 2 == 0)
	{//For bigger then one digit
		cnt = (N / 2) - 2;
		numberFront = (N / 2) - 1;
		numberBack = (N / 2) + 2;
		cntSpaceMidle = 2;
	}
	else
	{
		cnt = (N / 2) - 1;
		numberFront = N / 2;
		numberBack = (N / 2) + 2;
		cntSpaceMidle = 1;
	}
	
	
	cntSpace--;
	cntSpace--;
	

	//Printing the increases of the numbers(the down side)
	while (cnt > 0)
	{
		if (N > 9)
		{//For bigger then one digit
			cout << setw(2) << "1";
			for (int i = 0; i < cntSpace; i++)
				cout << setw(2) << " ";

			cout << setw(2) << numberFront;

			for (int i = 0; i < cntSpaceMidle; i++)
				cout << setw(2) << " ";

			if (numberFront != numberBack)
				cout << setw(2) << numberBack;

			for (int i = 0; i < cntSpace; i++)
				cout << setw(2) << " ";

			cout << setw(2) << N << endl;

			numberFront--, numberBack++, cntSpace--, cntSpaceMidle++, cntSpaceMidle++, cnt--;
		}
		else
		{
			cout << "1";
			for (int i = 0; i < cntSpace; i++)
				cout << " ";

			cout << numberFront;

			for (int i = 0; i < cntSpaceMidle; i++)
				cout << " ";

			if (numberFront != numberBack)
				cout << numberBack;

			for (int i = 0; i < cntSpace; i++)
				cout << " ";

			cout << N << endl;

			numberFront--, numberBack++, cntSpace--, cntSpaceMidle++, cntSpaceMidle++, cnt--;
		}
	}

	//Printing last line
	if (N > 9)
	{//For bigger then one digit
		for (int i = 1; i <= N; i++)
			cout << setw(2) << i;
	}
	else
	{
		for (int i = 1; i <= N; i++)
			cout << i;
	}
	cout << endl;
}


int main()
{
	int N;
	cout << "N:";
	cin >> N;


	Square(N);


    return 0;
}

