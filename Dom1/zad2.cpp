// zad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

char card[13] = { ' A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'};
char paint[4] = { 'C', 'D', 'H', 'S' };
	
void  beforeAndAfter(char c, char p)
{	
	
	for (int i = 0; i < 13; i++)
	{
		if (card[i] == c)
		{
			for (int j = 0; j < 4; j++)
			{
				if (paint[j] == p)
				{

					//If the input is A/C
					if (card[i] == card[0] && paint[j] == paint[0])
					{
						cout << "Previous: " << card[12] << "/" << paint[3] << endl;
						cout << "Next: " << card[i] << "/" << paint[j+1] << endl;
						break;
					}
					//If the input is K/S
					if (card[i] == card[12] && paint[j] == paint[3])
					{
						cout << "Previous: " << card[i] << "/" << paint[j-1] << endl;
						cout << "Next: " << card[0] << "/" << paint[0] << endl;
						break;
					}
					//If input paint is C
					if (paint[j] == paint[0])
					{
						cout << "Previous: " << card[i - 1] << "/" << paint[3] << endl;

					}
					else
						cout << "Previous: " << card[i] << "/" << paint[j - 1] << endl;
					//If input paint is S
					if (paint[j] == paint[3])
					{
						cout << "Next: " << card[i + 1] << "/" << paint[0] << endl;
					}
					else
						cout << "Next: " << card[i] << "/" << paint[j + 1] << endl;


				}
			}
		}
		
	}
}

int main()
{
	char c;
	char p;
	cout << "Enter card number: ";
	cin >> c;
	cout << "Enter paint: ";
	cin >> p;
	cout << "Your card: " << c << "/" << p << endl;

	beforeAndAfter(c, p);


    return 0;
}

