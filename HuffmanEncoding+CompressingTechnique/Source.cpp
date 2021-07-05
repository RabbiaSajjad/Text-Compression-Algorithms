#include <iostream>
#include <fstream>
#include "Priority.h"
//#include "Encode.cpp"
//#include "Huffman.h"
#include"compressing.h"
#include <ctime>
using namespace std;




Priority_Queue CalculateFrequency(string filename, int& s)
{

	Priority_Queue Q;
	fstream file;
	int frequency[100];
	char uniquechar[100];
	char readchar;
	int size = 0;
	bool valueExists = false;
	int filecount = 0;


	file.open(filename);

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
				valueExists = true;
				frequency[j] = frequency[j] + 1;

				break;
			}
			j++;
		}
		if (valueExists == false)
		{

			uniquechar[j] = readchar;
			frequency[j] = 1;

			size++;
		}
		i++;
	}
	s = size;

	cout << endl;
	cout << "Total Unique Characters: " << size << endl;

	for (int k = 0; k < size; k++)
	{
		Q.insert(uniquechar[k], frequency[k]);
	}

//	Q.show();


	file.close();

	return Q;
}


int main()
{
	Priority_Queue queue, queue2;
	Huffman T;
	int size = 0;
	clock_t startClock, finishClock;
	double timeCount;

	startClock = clock();
	queue = CalculateFrequency("file1.txt", size);
//	cout << "Queue recieved: ";
	//cout << "s " << s;
	//queue.show();
	EncodedValues* encode;
	encode = new EncodedValues[size];

	for (int i = 0; i < size; i++)
	{
		encode[i].character = queue.getCharacter(i);
	}

	while (queue.getQueueSize() > 1)
	{
//		cout << "size: " << queue.getQueueSize() << endl;
		queue = T.makeTree(queue);
//			queue.show();
	//	cout << "size: " << queue.getQueueSize() << endl;
		cout << endl << endl;
	}

	HuffmanNode* N = queue.getNode();

//	queue.show();

	T.Traversal(encode, queue, size);



//	for (int i = 0; i < size; i++)
//	{
//		cout << encode[i].character << " : " << encode[i].bitvalue << endl;
//	}
	string filename = "Challenge.txt";
	fstream file;
	T.encodeFile(filename, size, encode);
	finishClock = clock();
	timeCount = finishClock - startClock;


	cout << "\nFilename : " << filename << endl;
	ifstream file2(filename, ios::binary);
	file2.seekg(0, ios::end);
	int file_size = file2.tellg();
	cout << "Size of the original file is" << " " << file_size << " " << "bytes";
	cout << "\nTime taken for Huffman Enocding  " << timeCount << endl;


	startClock = clock();
	T.decodeFile(N);


	finishClock = clock();
	timeCount = finishClock - startClock;

	ifstream file3("Encodefile.txt", ios::binary);
	file3.seekg(0, ios::end);
	file_size = file3.tellg();
	cout << "Size of the encoded file is" << " " << file_size << " " << "bytes";

	cout << "\nTime taken for Huffman Decoding : " << timeCount << endl;

	startClock = clock();

	compressingTechnique("Challenge.txt"); //Step 3


	finishClock = clock();
	timeCount = finishClock - startClock;

	cout << "\nTime taken on our own technique : " << timeCount << endl;

	ifstream file4("encodeCompressingTechnique.txt", ios::binary);
	file4.seekg(0, ios::end);
	 file_size = file4.tellg();
	cout << "Size of the Encoded file is" << " " << file_size << " " << "bytes";
	cout << endl;




	return 0;
}