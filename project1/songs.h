/*
Devin Smith *** Project 1 *** CS260 *** Professor Liang
This files holds the class that manages the songs
*/

#ifndef SONGS_H
#define SONGS_H

#include "list.h"

class list;
struct node;

struct user{
    char artist[100];
    char title[100];
    float length;
    long likes;
};

class songs
{
    public:
        songs();
        ~songs();
        bool add_new(user &input, list &insert);
        void copy1(user &input, list &insert);
        void copy2(user &input, list &insert, node *temp);
        void append(user &input, list &insert);
        

    private:
        char *artist;
        char *title;
        float length;
        long likes;

        friend class list;
};
#endif
