// zad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


//swapping the given rows
void swap(double *row1, double *row2)
{
	double tmp = *row1;
	*row1 = *row2;
	*row1 = tmp;
}

//finding the answers
double * xAnswers(double **matrix, int N)
{
	double * x = new double[N];

	for (int i = N - 1; i >= 0; i--) {
		x[i] = matrix[i][N] / matrix[i][i];
		for (int t = i - 1; t >= 0; t--) {
			matrix[t][N] -= matrix[t][i] * x[i];
		}
	}
	return x;
	delete[]x;
}

//printing the final matrix
void printMatrix(double ** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N + 1; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

//print the answers
void printAnswers(double * answers, int N)
{
	cout << "Answers: ";
	for (int i = 0; i < N; i++)
	{
		cout << answers[i] << " ";
	}
	cout << endl;
}


void Gauss(double **matrix, int N)
{	
	

	for (int i = 0; i<N; i++) {
		//find the maximum row
		double maxEl = matrix[i][i];
		int maxRow = i;
		for (int t = i + 1; t<N; t++) 
		{
			if (matrix[t][i] > maxEl)
			{
				maxEl = matrix[t][i];
				maxRow = t;
			}
		}
		

		// Swapping the rows
		for (int t = i; t < N + 1; t++) 
		{
			swap(matrix[maxRow][t], matrix[i][t]);
		}

		//make everything below the diagonal
		for (int t = i + 1; t < N; t++) 
		{
			double c = - matrix[t][i] / matrix[i][i];
			for (int j = i; j < N + 1; j++)
			{
				if (i == j) 
				{
					matrix[t][j] = 0;
				}
				else 
				{
					matrix[t][j] += c * matrix[i][j];
				}
			}
		}
	}
	
	cout << endl;
	printMatrix(matrix, N);
	printAnswers(xAnswers(matrix, N), N);

}

int main()
{
	int N;
	cout << "N:";
	cin >> N;

	if (N > 500)
	{
		cout << "N > 500" << endl;
		return 0;
	}

	double ** matrix = new double*[N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new double[N + 1];
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N + 1; j++)
			cin >> matrix[i][j];
	
	Gauss(matrix, N);

	for (int i = 0; i < N; i++)
		delete[]matrix[i];
	delete[]matrix;

    return 0;
}

