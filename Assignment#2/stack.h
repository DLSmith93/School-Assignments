/*
Devin Smith *** Project #2 *** CS260 *** Professor Liang
--------------------------------------------------------
This is the header file that will hold the data structure
that manages the stack.

*/

#ifndef STACK_H
#define STACK_H

#include "queue.h"

struct temp_contact;
//class queue;

class stackList{
    
    public:
        stackList(int CAP);
        ~stackList();
        bool push(temp_contact temp);
        bool pop(int selection, temp_contact to_remove);
        int peek(int choice);
        bool display();
        bool readFile(temp_contact &to_add);
        bool saveFile();

    private:
        struct contact{
            char *email;
            char *name;
        };

        struct stackNode{
            contact *patrons;
            stackNode *next;
        };


        bool build(temp_contact temp);
        bool add(temp_contact temp);
        bool copy(temp_contact to_add, stackNode *temp);
        bool destroy(stackNode *current);
        bool remove(temp_contact to_remove);

        stackNode *head;

        int top;
        int MAX_CAP;
        int size = 0;

        friend class queue;

};

#endif 
