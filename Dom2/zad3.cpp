// zad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h> 

using namespace std;

void Binary(int number1, int number2)
{
	int array1[32], array2[32];
	//Fill arrays with binary
	for (int i = 0; i < 32; ++i) {  
		array1[i] = number1 & (1 << i) ? 1 : 0;
		array2[i] = number2 & (1 << i) ? 1 : 0;
	
	}
	
	//swap array1
	int front = 0;
	int back = 31;
	while (front < back)
	{
		int tmp = array1[front];
		array1[front] = array1[back];
		array1[back] = tmp;
		front++;
		back--;
	}
	//swap array2
	front = 0;
	back = 31;
	while (front < back)
	{
		int tmp = array2[front];
		array2[front] = array2[back];
		array2[back] = tmp;
		front++;
		back--;
	}

	cout << "number1: ";
	for (int i = 0; i < 32; ++i) {  
		cout << array1[i];
	}
	cout << endl << "number2: ";
	for (int i = 0; i < 32; ++i) {  
		cout << array2[i];
	}

	int finalnum1 = 0;
	int finalnum2 = 0;
	int degree = 0;
	int cnt = 0;
	int IP1[4];
	int IP2[4];
	int j = 3;
	//Making from array1 and array2 IP address
	for (int i = 31; i >= 0; i--)
	{
		
		finalnum1 += array1[i] * pow(2, degree);
		finalnum2 += array2[i] * pow(2, degree);
		degree++;
		cnt++;
		if (cnt == 8)
		{
			IP1[j] = finalnum1;
			IP2[j] = finalnum2;
			finalnum1 = 0;
			finalnum2 = 0;
			cnt = 0;
			j--;
			degree = 0;
		}
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i < 3)
			cout << IP1[i] << ".";
		else
			cout << IP1[i] << ";";
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i < 3)
			cout << IP2[i] << ".";
		else
			cout << IP2[i] << ";";
	}
	cout << endl;

	//Prefix length
	int lenght = 0;
	for (int i = 0; i < 32; ++i) {
		if (array1[i] == array2[i])
		{
			lenght++;
		}
		else
			break;
	}
	cout << "Prefix length : " << lenght << ";" << endl;

	//Prefix binary
	int prefBinery[32];
	int cnti = 0;
	while (lenght > 0)
	{
		prefBinery[cnti] = 1;
		lenght--;
		cnti++;
	}
	while (cnti < 32)
	{
		prefBinery[cnti] = 0;
		cnti++;
	}
	cout << "Prefix binary : ";
	for (int i = 0; i < 32; i++)
		cout << prefBinery[i];
	cout << ";" << endl;


	int finalnumPref = 0;
	degree = 0;
	cnt = 0;
	int IPpref[4];
	j = 3;
	//Making from Prefix binary to IP address(Prefix octets)
	for (int i = 31; i >= 0; i--)
	{

		finalnumPref += prefBinery[i] * pow(2, degree);
	
		degree++;
		cnt++;
		if (cnt == 8)
		{
			IPpref[j] = finalnumPref;
		
			finalnumPref = 0;
			cnt = 0;
			j--;
			degree = 0;
		}
	}
	cout << "Prefix octets : ";
	for (int i = 0; i < 4; i++)
	{
		if (i < 3)
			cout << IPpref[i] << ".";
		else
			cout << IPpref[i] << ";";
	}
	cout << endl;
}

int main()
{
	int number1 = 1537212452;
	int number2 = 1477444609;
	/*cout << "number1: ";
	cin >> number1;
	cout << "number2: ";
	cin >> number2;
	*/
	Binary(number1, number2);

    return 0;
}

