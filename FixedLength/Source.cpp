#include<iostream>
#include<string.h>
#include<fstream>
#include "Header.h"
//#include "Huffman.h"
//#include <bits/stdc++.h> 
//#include <cmath>
//#include <iterator> 
//#include <map>
#include<ctime>


using namespace std;


void ReadUniqueCharacters(string filename) {

	Tree T;
	fstream file;
	fstream file2;
	file.open(filename);
	
	string bits[100];

	char uniquechar[100];
	char readchar;
	int size = 0;
	bool valueExists = false;
	int filecount = 0;
	
	int i = 0;
	while (!file.eof())
	{
		valueExists = false;
		file >> readchar;
		filecount++;
		int j = 0;
		while (j < size)
		{
			if (uniquechar[j] == readchar)
			{
	//			file2 << bits[j];
				valueExists = true;
				
				break;
			}
			j++;
		}
		if (valueExists == false)
		{
			 uniquechar[j] = readchar;
//			bits[j]=T.makeTree(uniquechar[j]);
		
//			cout << bits[j];
	//		file2 << bits[j];
		//	cout << uniquechar[j] << " ";
			size++;
		}
		i++;
	}

	cout << endl;
	cout << "Total Unique Characters: " << size << endl;

	file.close();
	

	int k = 0;
	int noofbits;
	
	while (k < 20)
	{
		if (pow(2, k) >= size)
		{
			noofbits = k;
			break;
		}
		else
		{
			k++;
		}
	}
	file.open(filename);
	file2.open("EncodedFixedLength2.txt", ios::out);  //ENCODING FILE

	i = 0;
	size = 0;
	while (!file.eof())
	{
		valueExists = false;
		file >> readchar;
		//filecount++;
		 int j = 0;
		while (j < size)
		{
			if (uniquechar[j] == readchar)
			{
				file2 << bits[j];
				valueExists = true;

				break;
			}
			j++;
		}
		if (valueExists == false)
		{
		//	uniquechar[j] = readchar;
		bits[j]=T.makeTree(uniquechar[j], noofbits);

	//		cout << bits[j];
			file2 << bits[j];
	//		cout << uniquechar[j] << " ";
			size++;
		}
		i++;
	}



	cout << "No of bits we will use: " << noofbits << endl;

	file2.close();

	T.Decode(filecount, noofbits);  // DECODING FILE
	
}



int main()
{

	

	clock_t startClock, finishClock;
	double timeCount;
	string filename= "file1.txt";

/*	startClock = clock();
	ReadUniqueCharacters(filename);

	finishClock = clock();
	timeCount = finishClock - startClock;


	cout << "\nFilename : " << filename << endl;
	ifstream file2(filename, ios::binary);
	file2.seekg(0, ios::end);
	int file_size = file2.tellg();
	cout << "Size of the original file is" << " " << file_size << " " << "bytes";
	cout << "\nTime taken for Fixed Length  " << timeCount << endl;*/


	startClock = clock();

	ReadUniqueCharacters(filename);

	finishClock = clock();
	timeCount = finishClock - startClock;

	cout << "\nFilename : " << filename << endl;
	ifstream file2(filename, ios::binary);
	file2.seekg(0, ios::end);
	int file_size = file2.tellg();
	cout << "Size of the original file is" << " " << file_size << " " << "bytes";
	cout << "\nTime taken for Fixed Length  " << timeCount << endl;


	

	





	return 0;
}