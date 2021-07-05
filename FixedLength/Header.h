#pragma once

#include<iostream>
#include<string.h>
#include<fstream>
//#include <bits/stdc++.h> 
#include <cmath>
using namespace std;


struct node {
	char value;
	bool valueFilled;
	node* left;
	node* right;


	node()
	{
		value = '\0';
		valueFilled = false;
		left = NULL;
		right = NULL;
	}

};

class Tree
{
	
	node* root;
	node* temp;
	node* parent;

public:

	Tree()
	{
		root = new node;
		temp = new node;
		parent = new node;
	}

	string makeTree(char character, int noofbits)
	{
		
	

		char bitValue[10];
		temp = root;
		parent = temp;

		int depth = 1;
				
		for (int i = 1; i <= noofbits; i++)  //depth 7
		{

			if (temp->left == NULL)
			{
				
				temp->left = new node;
			}

			if (temp->right == NULL)
			{
				temp->right = new node;
			}


			if (temp->left->valueFilled == false)
			{
				bitValue[i-1] =  '0';
				parent = temp;
				temp = temp->left;
				depth++;
			}
	
			

			else if (temp->right->valueFilled == false)
			{
				bitValue[i-1] = '1';
				parent = temp;
				temp = temp->right;
				depth++;
			}

			
			else {
				temp->valueFilled = true;
				
					temp = root;
				parent = temp;
				i = 0;
				
				
			}

		}
		
		temp->value = character;
		temp->valueFilled = true;

		cout << "Bit Value of " << character << " : ";

		for (int i = 0; i < noofbits; i++)
			cout << bitValue[i];

		bitValue[noofbits] = '\0';
		cout << endl;

		return bitValue;
	}

	void Decode(int filesize, int noofbits)
	{

		fstream f3,f4;
		char readchar;
		f3.open("EncodedFixedLength2.txt");
		f4.open("DecodedFixedLength2.txt", ios::out);
		int characterno = 1;
		int i = 0;
		while (i<filesize)
		{
			temp = root;
			for (int i = 0; i < noofbits; i++)
			{
				f3 >> readchar;

				if (readchar == '0')
					temp = temp->left;

				else if (readchar == '1')
					temp = temp->right;

				else
				{
					cout << "Character number: " << characterno;
					exit(0);
				}

			}
			
			f4 << temp->value;
			characterno++;
//			cout << temp->value << "  ";
			
			i++;
		}

	}

	

};
