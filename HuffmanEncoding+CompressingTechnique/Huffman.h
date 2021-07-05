#pragma once
#include<iostream>
//#include "Priority.h"


using namespace std;

struct HuffmanNode
{
    int freq;
    char character;
    bool valueRead;
    HuffmanNode* next;
    HuffmanNode* parent;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode()
    {
        freq = 0;
        character = '\0';
        valueRead = false;
        left = nullptr;
        parent = nullptr;
        right = nullptr;
        next = nullptr;
    }
};