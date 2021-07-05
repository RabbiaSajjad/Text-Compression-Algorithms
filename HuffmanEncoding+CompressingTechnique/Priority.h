#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include "Huffman.h"
#include "Encode.cpp"


using namespace std;
class Priority_Queue
{
private:

    HuffmanNode* front;
    HuffmanNode* temp;
    int queueSize;

public:
    Priority_Queue()
    {
        front = nullptr;
        temp = nullptr;
        queueSize = 0;
    }
    void insert(char i, int p, HuffmanNode* t = new HuffmanNode)
    {
        //t = new HuffmanNode;
        HuffmanNode* q = new HuffmanNode;
        temp = t;
        temp->freq = p;
        temp->character = i;
        if (front == nullptr || temp->freq < front->freq) {
            temp->next = front;
            front = temp;
        }
        else {
            q = front;
            while (q->next != nullptr && q->next->freq <= temp->freq)
                q = q->next;
            temp->next = q->next;
            q->next = temp;
        }
        queueSize++;
    }

    HuffmanNode* extractNode()
    {

        if (front == nullptr) //if queue is null
            cout << "Queue Underflow\n";
        else {
            temp = front;
    //        cout << "Deleted item is: " << temp->character << endl;
            front = front->next;
            queueSize--;
            return temp;
            // free(temp);
        }

    }
    void show() //print queue
    {
        HuffmanNode* ptr;
        ptr = front;
        if (front == NULL)
            cout << "Queue is empty\n";
        else
        {
            cout << "Queue is :\n";
            cout << "Priority Item\n";
            while (ptr != NULL)
            {
                cout << ptr->freq << " " << ptr->character << endl;
                ptr = ptr->next;
            }
        }
    }

    int getQueueSize()
    {
        return this->queueSize;
    }

    char getCharacter(int i)
    {
        HuffmanNode* q = front;
        int k = i;
        while (k > 0)
        {
            q = q->next;
            k--;
        }
        return q->character;

    }
    HuffmanNode* getNode()
    {
        return this->front;
    }
};

//HUFFMAN
class Huffman
{
    HuffmanNode* root;
    HuffmanNode* temp;
  //  HuffmanNode* parent;

public:
    Huffman()
    {
        root = nullptr;
        temp = nullptr;
     //   parent = nullptr;
    }


    Priority_Queue makeTree(Priority_Queue q)
    {
        HuffmanNode* t = new HuffmanNode;


        t->left = q.extractNode();
        t->right = q.extractNode();

        t->character = '*';
        t->freq = t->left->freq + t->right->freq;
        q.insert(t->character, t->freq, t);

        return q;

    }

    void Traversal(EncodedValues* e, Priority_Queue q, int size)
    {
        string bits;
        root = q.getNode();
        int j = 0;
        int i = 0;
        while (i < size)
        {
           
            temp = root;
            bits.clear();
          //  temp->parent = root;
            while (temp->left != nullptr && temp->right != nullptr)
            {
               
                
                if (temp->right->valueRead == 1 && temp->left->valueRead == 1)
                {
                    bits.clear();
                    temp->valueRead = true;
                    temp = root;
                    
                }
                if (temp->left != nullptr && temp->left->valueRead != 1)
                {

                    //   e[i].bitvalue += '0';
                    bits += '0';
                    //    cout << "0";
                    temp->parent = temp;
                    temp = temp->left;
                }
                else if (temp->right != nullptr && temp->right->valueRead != 1)
                {

                    //  e[i].bitvalue += '1';
                    bits += '1';
                    temp->parent = temp;
                    //  cout << "1";
                    temp = temp->right;

                }



            }
            temp->valueRead = true;
            if (temp->valueRead != 0)
            {
                //      cout << "Character found " << temp->character << " frequency: " << temp->freq;
               
                e[j].character = temp->character;
                e[j].bitvalue = bits;
                cout << "Character : " << e[j].character << " : bitvalue :  " << e[j].bitvalue << endl;

                //        cout << "  Bit value:  " << e[j].bitvalue << endl;

                j++;
                //  e[i].bitvalue=

            }
            else
            {
                size++;
            }
            //    temp->character = '\0';
            i++;
        }


        //    cout << "total elements : " << j << endl;
    }

    void encodeFile(string filename, int size, EncodedValues* e)
    {
        char readchar;
        fstream file, file2;
        file.open("Encodefile.txt", ios::out);
        file2.open(filename);

        while (file2 >> readchar)
        {
            for (int j = 0; j < size; j++)
            {
                if (e[j].character == readchar)
                {
                    file << e[j].bitvalue;
               //     file << ' ';
                }
            }
        }

        file.close();
        file2.close();
    }


    void decodeFile(HuffmanNode* q)
    {
        temp = q;
        fstream file_D, file_E;
        char bitvalue;
        file_E.open("Encodefile.txt");
        file_D.open("decodefile.txt", ios::out);

        while (file_E >> bitvalue)
        {

           
            if (bitvalue == '0')
            {
                temp = temp->left;
                if (temp->left == nullptr && temp->right == nullptr)
                {
                    file_D << temp->character;
                    temp = q;
                }
            }

            else
            {
                temp = temp->right;
                if (temp->left == nullptr && temp->right == nullptr)
                {
                    file_D << temp->character;
                    temp = q;
                }
            }
        }
        file_E.close();
        file_D.close();

    }


};
