// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int ** solve(int **matrix, int N)
{	
	int number = 0;
	int i = N - 1;
	int j = 0;
	int tmpj = 0;
	int tmpi = 0;

	while (i > 0 || j < N - 1)
	{	
		//if it is on the position matix[N-1][j] and save the currernt j
		if (i == N - 1)
		{
			tmpj = j;
		}
		//if it is on the position matix[i][N-1] and save the currernt i
		if (j == N - 1)
		{
			tmpi = i;
		}

		//if we are i the positin matrix[0][0] we input the number and locate the next positin which is matric[N-2][N-1]
		if (i == 0 && j == 0) 
		{
			matrix[i][j] = number;
			number++;
			i = tmpi - 1;
			j = N - 1;
		}
		//if we are on the positin matrix[i][0] we input the number and locate the next positin which is matric[N-1][tmpj +1](it's tmpj+1 because tmpj remember the last j of the this row)
		else if (j == 0)
		{
			matrix[i][j] = number;
			number++;
			j = tmpj + 1;
			i = N - 1;
		}
		//if we are on the positin matrix[0][j] we input the number and locate the next positin which is matric[tmpj - 1][N-1](it's tmpj-1 because tmpi remember the last i of the this column)
		else if (i == 0)
		{
			matrix[i][j] = number;
			number++;
			i = tmpi - 1;
			j = N - 1;
		}
		//its inputting number in the matrix while going diagonal brom the bottom to left and up
		else
		{
			matrix[i][j] = number;
			number++;
			j--;
			i--;
		}
	}
	//input the last number
	matrix[i][j] = number;
	


	return matrix;
}

//printing the matrix
void print(int ** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(2) << matrix[i][j] << " ";
		cout << endl;
	}
}


int main()
{
	int N;
	cout << "N: ";
	cin >> N;

	int ** matrix = new int*[N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[N];
	
	
	print(solve(matrix, N), N);

	for (int i = 0; i < N - 1; i++)
		delete[] matrix[i];
	delete[] matrix;

    return 0;
}

