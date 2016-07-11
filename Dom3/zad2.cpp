// zad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

void Solve(int *arr, int N)
{	
	int mostPopular;
	int tmpNumber;
	int tmpNumbrerCnt = 0;
	int mostPopularCnt = 0;

	for (int i = 0; i < N; i++)
	{
		tmpNumber = arr[i];
		tmpNumbrerCnt = 0;
		//it is counting the times that every number is fined 
		for (int j = 0; j < N; j++)
		{
			if (tmpNumber == arr[j])
			{
				tmpNumbrerCnt++;
			}
		}
		//check if we have new most popular number
		if (tmpNumbrerCnt > mostPopularCnt)
		{
			mostPopular = tmpNumber;
			mostPopularCnt = tmpNumbrerCnt;
		}
	}
	
	cout << "Most popular number is: " << mostPopular << endl;
	

}

int main()
{
	int N;
	cout << "N:";
	cin >> N;
	int *arr;

	if (N > 0)
	{
		 arr = new int[N];
	}
	else
	{
		cout << "N is not even" << endl;
		return 0;
	}

	for (int i = 0; i < N; i++)
	{	
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
		if (arr[i] > 5000) 
		{ 
			cout << "parametur is bigger then 5000" << endl; 
			return 0;
		}
	}

	Solve(arr, N);

	delete[]arr;

		
	return 0;
}

