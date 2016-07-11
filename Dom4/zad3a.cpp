// zad3.cpp : Defines the entry point for the console application.
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

int numWords(char * string)
{
	int i = 0;


	char * pch;

	pch = strtok(string, " ,.-");
	while (pch != NULL)
	{
		pch = strtok(NULL, " ,.-");
		i++;
	}
	return i;
}

void merge(char* string, char ** words, char ** marks, int choise, int lenWords, int lenMarks)
{
	int i = 0;
	int j = 0;
	switch (choise) {
	case 1:
		strcpy(string, words[0]);
		i++;
		while (1>0)
		{
			if (j < lenMarks)
			{
				strcat(string, marks[j]);

			}
			if (i < lenWords)
			{
				strcat(string, words[i]);

			}
			if (j == lenMarks - 1 && i == lenWords)
				break;
			i++;
			j++;
		}
		break; 
	case 2:
		strcpy(string, marks[0]);
		j++;
		while (1>0)
		{	
			if (i < lenWords)
			{
				strcat(string, words[i]);
			
			}
			if (j < lenMarks)
			{
				strcat(string, marks[j]);
				
			}
			if (j == lenMarks && i == lenWords - 1)
				break;
			i++;
			j++;
		}
		break; 

	default: 
		break;
	}
	
}
char * stringReplace(const char * str)
{
	char *string = new(nothrow) char[256];
	strcpy(string, str);

	char **words = new(nothrow) char*[256];
	char **marks = new(nothrow) char*[256];

	int i = 0;

	int len = numWords(string);
	strcpy(string, str);

	char * pch;

	pch = strtok(string, " ,.-");
	while (pch != NULL)
	{
		words[i] = new(nothrow) char[strlen(pch)];
		strcpy(words[i], pch);
		pch = strtok(NULL, " ,.-");
		i++;
	}

	for (int i = 0; i < len; ++i)
	{
		swap(words[i]);
	}
	strcpy(string, str);
	char * pch2;
	pch2 = strtok(string, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	int j = 0;
	while (pch2 != NULL)
	{
		marks[j] = new(nothrow) char[strlen(pch2)];
		strcpy(marks[j], pch2);
		pch2 = strtok(NULL, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
		j++;
	}
	
	if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
		merge(string, words, marks, 1, i, j);
	else
		merge(string, words, marks, 2, i, j);
	

	return string;

	delete[] string;

	for (int i = 0; i < len; i++)
		delete[] words[i];
	delete[] words;
}
int main()
{
	char *string = new(nothrow) char[256];


	cin.getline(string, 256);


	string = stringReplace(string);
	cout << string << endl;

	delete[] string;

	return 0;
}