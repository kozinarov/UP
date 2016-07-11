// zad3_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "cstring"
using namespace std;


void swap(char * word)
{
	int front = 0, end = strlen(word) - 1;
	char tmp;
	int len = strlen(word);

	for (unsigned int i = 0; i < (len / 2); ++i)
	{
		tmp = word[front];
		word[front] = word[end];
		word[end] = tmp;
		front++;
		end--;

	}
}
void reverseWords(char* str)
{
	int start, end = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{	
		
			start = i;
			//finds from whwre to where is a word
			for (int j = start; j < strlen(str); ++j)
			{
				if (str[j] == ' ' || str[j] == '.' /*|| j == strlen(str) - 1*/)
				{
					end = j;
					i = end;
					break;
				}
			}
			int lenword = end - start;
			char * word = new(nothrow) char[lenword+1];
			int k = 0;

			
			for (int p = start; p < end; ++p)
			{
				word[k] = str[p];
				k++;

			}
		
			word[k] = '\0';
			k = 0;

			swap(word);
			
			for (int p = start; p < end; ++p)
			{
				str[p] = word[k];
				k++;

			}
			delete[] word;
			
		}
	
	}
	//cout << str << endl;
}

int main()
{
	char *string = new(nothrow) char[256];


	cin.getline(string, 256);
	int len = strlen(string);
	string[len + 1] = '\0';

	reverseWords(string);
	cout << string << endl;

	delete[] string;

    return 0;
}

