/*

*** Devin Smith *** Projects 3 Hash Table *** CS260 *** Professor Liang ***
This is the header files that houses the class that manages the hash table

*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

//temp struct for the client
struct temp{
            
    char name[100];
    char address[100];
    char summary[100];
    char review[100];
    int rating;

};


class hash_table{

    public:
        hash_table();
        ~hash_table();
        bool insert(temp);
        bool search(temp, temp [], int &);
        bool display();
        bool remove(temp);
        bool edit(temp &, int, char [], char []);
        bool read(temp &);
        bool del_low(temp &);
        bool performance();


    private:

        //struct for enter data in the hash table
        struct website{
            
            char *name;
            char *address;
            char *summary;
            char *review;
            int rating;

        };

        //struct for list in table
        struct node{

            website data;
            node *next;
        };

        //struct for hash table
        struct hash{

            node *head;
            int colisions = 0;

        };

        hash table[26];
        int key;

        void hash_key(temp);
        bool build(temp);
        bool add(temp);
        void del(node *&, node *&);
        bool copy(temp, node *&);
        bool retrieve(temp, temp [], int &);
        

};

#endif
