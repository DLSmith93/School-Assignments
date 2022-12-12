/*
Devin Smith *** Project 1 *** CS260 *** Professor Liang
This files contains the class that maintains the list of songs
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include "songs.h"

class songs;

struct node{
    songs info;
    node *next;
};

class list
{
    public:
        list();
        ~list();
        bool add(user &input, list &insert);
        bool display(list &insert);
        void print(node *temp);
        bool search(user input);
        bool del(user input);
        bool loadfile(user &input, list &insert);
        bool savefile(user &input, list &insert);

        friend class songs;

    private:
        node *head;

        friend class songs;
        songs to_add; 

};
#endif
