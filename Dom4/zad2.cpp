// zad2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include "cstring"

using namespace std;


char * stringReplace(const char * str, const char * what, const char * with)
{
	char *string = new(nothrow) char[256];
	strcpy(string, str);
	while (strstr(string, what) != NULL)
	{
		char * part;
		part = strstr(string, what);
		strncpy(part, with, strlen(with));
	
	}
	return string;
	delete[] string;
}
int main()
{
	char *string = new(nothrow) char[256];
	char *what = new(nothrow) char[256];
	char *with = new(nothrow) char[256];


	cin.getline(string, 256);
	cout << "What: ";
	cin >> what;
	cout << "With: ";
	cin >> with;

	if (strlen(what) != strlen(with))
	{
		cout << "what and with have diferent lenght" << endl;
		return 0;
	}

	string = stringReplace(string, what, with);
	cout << string << endl;

	delete[] string;
	delete[] what;
	delete[] with;

	return 0;
}

