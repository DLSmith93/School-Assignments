/*
Devin Smith *** Project #2 *** CS260 *** Professor Liang
--------------------------------------------------------
This is the header file that holds the data structre that
manages the queue.

*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include "stack.h"
  

class stack;

//structs for the client
struct temp_contact{
    char email[100];
    char name[100];
};
struct temp_waiting{
    char groupName[100];
    int numPeople;
    char spclSeating[100];
};

class queue{

    public:
        queue();
        ~queue();
        bool enqueue(temp_waiting waiting);
        bool dequeue();
        bool peek();
        int dsply(int choice, temp_waiting waiting);
        bool append(temp_waiting change, char temp_name[], int selection, int choice);
        bool saveFile();
        bool readFile(temp_waiting &waiting);

    private:
        struct party{
            char *groupName;
            int numPeople;
            char *spclSeating;
            int position;
        };

        struct queueNode{
            party data;
            queueNode *next;
        };
        
        bool build(temp_waiting waiting);
        bool copy(temp_waiting to_copy, queueNode *temp);
        bool add(temp_waiting waiting);
        bool remove(temp_waiting change);
        bool destroy();


        queueNode *head;
        queueNode *rear;
        int size = 0;
        
        friend class stack;

};

#endif
