#pragma once
#include<iostream>
#include<string>

using namespace std;


struct encodeNode {
	string value;
	char symbol;



	encodeNode()
	{
		value = "";
		symbol = '\0';
		
	}
};


void compressingTechnique(string filename)
{
	fstream file1, file2;
	encodeNode letters[20];
	bool valueExists=false;
	char symb = '!';
	char readchar[3];
	int ascii[3];
	file1.open(filename);
	file2.open("encodeCompressingTechnique.txt", ios::out);
	int size = 0;
	file1 >> readchar[0];
	file1 >> readchar[1];
	file1 >> readchar[2];
	
	while (file1 >> readchar[0])
	{
		
		valueExists = false;
		
		file1 >> readchar[1];

		if (readchar[0] != readchar[1])
		{

			int k = 0;
			while (k < 2)
			{
				for (int i = 0; i < size; i++)
				{

					if (letters[i].value[0] == readchar[k])
					{
			//			file2 << letters[i].symbol;
						valueExists = true;
					}



				}
				if (valueExists == false)
				{

					letters[size].value = readchar[k];
					letters[size].symbol = symb;
					symb++;
					size++;
				}
				k++;
			}
		}

		else if(readchar[0] == readchar[1])
		{
			file1 >> readchar[2];

			int k = 0;
		

			if (readchar[0] == readchar[2])
			{
				for (int i = 0; i < size; i++)
				{
					if (letters[i].value[0] == readchar[0] && letters[i].value[1] == readchar[1] && letters[i].value[2] == readchar[2])
					{

			//			file2 << letters[i].symbol;
						valueExists = true;
					}

				}
				if (valueExists == false)
				{
					letters[size].value = readchar[0];
					letters[size].value += readchar[1];
					letters[size].value += readchar[2];
					letters[size].symbol = symb;
					symb++;
					size++;
				}
			}

			else {
				
					for (int i = 0; i < size; i++)
					{


						if (letters[i].value[0] == readchar[0] && letters[i].value[1] == readchar[1])
						{
							
				//				file2 << letters[i].symbol;
								valueExists = true;
							
						}

					}
					if (valueExists == false)
					{
						letters[size].value = readchar[0];
						letters[size].value += readchar[1];
						letters[size].symbol = symb;
						symb++;
						size++;
					}
					
					valueExists = false;

				for (int i = 0; i < size; i++)
				{


					if (letters[i].value[0] == readchar[2])
					{

//						file2 << letters[i].symbol;
						valueExists = true;

					}

				}
				if (valueExists == false)
				{
					letters[size].value = readchar[2];
					letters[size].symbol = symb;
					symb++;
					size++;
				}


			}

		}



	}

	for (int i = 0; i < size; i++)
	{
		cout << "Letters : " << letters[i].value << " : Encoded values : " << letters[i].symbol << endl;
	}
	file1.close();
	file2.close();

	file1.open(filename);
	file2.open("encodeCompressingTechnique.txt");
	file1 >> readchar[0];
	file1 >> readchar[1];
	file1 >> readchar[2];
	

	while (file1 >> readchar[0])
	{
		file1 >> readchar[1];
		file1 >> readchar[2];

		if (readchar[0] == readchar[1])
		{
			if (readchar[0] == readchar[2])
			{
				for (int i = 0; i < size; i++)
				{
					if (letters[i].value[0] == readchar[0] && letters[i].value[1] == readchar[1] && letters[i].value[2] == readchar[2])
					{
						file2 << letters[i].symbol;
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					if (letters[i].value[0] == readchar[0] && letters[i].value[1] == readchar[1])
					{
						file2 << letters[i].symbol;
						break;
					}
				}
				for (int i = 0; i < size; i++)
				{
					if(letters[i].value[0] == readchar[2])
					{
						file2 << letters[i].symbol;
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (letters[i].value[0] == readchar[0])
				{
					file2 << letters[i].symbol;
					break;
				}
			}

			if (readchar[1] == readchar[2])
			{
				for (int i = 0; i < size; i++)
				{
					if (letters[i].value[1] == readchar[1] && letters[i].value[2] == readchar[2])
					{
						file2 << letters[i].symbol;
						break;
					}
				}
			}

			else
			{

				for (int i = 0; i < size; i++)
				{

					if (letters[i].value[0] == readchar[1])
					{
						file2 << letters[i].symbol;
						break;
					}
				}
				for (int i = 0; i < size; i++)
				{
					if (letters[i].value[0] == readchar[2])
					{
						file2 << letters[i].symbol;
						break;
					}
				}
			}
		}

	}

	file1.close();
	file2.close();

	fstream file, file3;
	string str;
	file.open("encodeCompressingTechnique.txt");
	file3.open("decodeCompressingTechnique.txt", ios::out);
	char readcharacter;

	while (file >> readcharacter)
	{
		for (int i = 0; i < size; i++)
		{
			if (letters[i].symbol == readcharacter)
			{
				file3 << letters[i].value;
			}
		}
	}

	file.close();
	file3.close();
}






