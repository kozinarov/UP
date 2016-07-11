// zad1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

char matr[100][100];
char buff[1024];

int strlen(char*str)
{
	int res = 0;
	while (*(str++))
	{
		res++;
	}
	return res;
}

char table[100][100];
int cntWords = 0;

int testHorizontal(int jPosition, int hor)
{
	if (jPosition<0 || jPosition >= hor)
	{
		return 0;
	}
}

int testVertical(int iPosition, int ver)
{
	if (iPosition<0 || iPosition >= ver)
	{
		return 0;
	}
}

int testAcross(int jPosition, int iPosition, int hor, int ver)
{
	if (iPosition < 0 || iPosition >= ver)
	{
		return 0;
	}
}

bool timesCheck(int cnt, int len)
{

	if (cnt == len)
	{
		return 1;
	}
	else
		return 0;
}


bool checkrows(int lines, int columns)
{
	int cnt;
	int numFind = 0, tmpNumFind = 0;
	int len = strlen(buff);
	for (int time = 1; time <= 2; ++time)
	{
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (*buff == table[i][j])
				{
					cnt = 0;
					//Horizontal left to right
					for (int k = 0; k < len; k++)
					{
						testHorizontal(j, columns);

						if (time == 2 && i == j + k && table[i][j + k] == *(buff + k))
						{
							break;
						}

						if (table[i][j + k] == *(buff + k))
						{
							cnt++;
						}

						numFind += timesCheck(cnt, len);
					}

					cnt = 0;
					//Horizontal right to left
					for (int k = 0; k < len; k++)
					{
						testHorizontal(j, columns);
						if (time == 2 && i == j - k && table[i][j - k] == *(buff + k))
						{
							break;
						}
						if (table[i][j - k] == *(buff + k))
						{
							cnt++;
						}

						numFind += timesCheck(cnt, len);
					}

					cnt = 0;
					//Vertical up to bottom
					for (int k = 0; k < len; k++)
					{
						testVertical(i, lines);

						if (time == 2 && i + k == j && table[i + k][j] == *(buff + k))
						{
							break;
						}
						if (table[i + k][j] == *(buff + k))
						{
							cnt++;
						}

						numFind += timesCheck(cnt, len);
					}


					cnt = 0;
					//Vertical bottom to up
					for (int k = 0; k < len; k++)
					{
						testVertical(i, lines);

						if (time == 2 && i - k == j && table[i - k][j] == *(buff + k))
						{
							break;
						}

						if (table[i - k][j] == *(buff + k))
						{
							cnt++;
						}

						numFind += timesCheck(cnt, len);
					}
				}
			}
		}
		if (time == 1)
			tmpNumFind = numFind;

		if (tmpNumFind == 0)
		{
			return false;
		}
		else if (tmpNumFind > numFind && numFind > 0)
		{
			return false;
		}
		numFind = 0;
	}
	return true;
}



int main()
{
	int N, M, T;

	char letter;


	cout << "Enter N and M: ";
	cin >> N;
	cin >> M;

	if (N <= 3 || N>M || M >= 100)
	{
		cout << "Error" << endl;
	}

	cout << "Enter T: ";
	cin >> T;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			cin >> letter;
			if (letter<66 && letter>123)
			{
				cout << "Error, the letter is not small." << endl;
				return 0;
			}
			//matr[i][j] = letter;
			table[i][j] = letter;
		}
	}

	cin.getline(buff, 1024);

	for (int i = 0; i<T; i++)
	{
		cin.getline(buff, 1024);

		if (checkrows(N, M) == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		char buff[1024] = { 0 };
	}


	return 0;
}
