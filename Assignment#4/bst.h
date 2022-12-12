
/*
    Program #4
    -----------
    Devin Smith *** CS260 *** Professor Liang
    -----------------------------------------
    This is the header file for the Binary Search Tree

*/


//structs
struct temp{
    char topic[100];
    char address[100];
    char summary[100];
    char review[100];
    int rating = 0;
    int key = 0;
};


#ifndef BST_HH
#define BST_HH


#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

//class
class tree{

    public:
        tree();
        ~tree();
        bool insert(temp);
        int keyGen(temp);
        bool search(temp);
        bool display();
        bool retrieve(temp, temp[], int &);
        bool delHelper(temp);
        int height();
        bool read(temp &);
        bool remove_topic(temp);

    private:
        struct website{
            char *topic;
            char *address;
            char *summary;
            char *review;
            int rating = 0;
            int key = 0;
        };
        struct branch{
            website data;
            branch *left;
            branch *right;
        };

        branch *root;

        bool ordered(branch *&, bool &);
        bool add(branch *&temp_leaf, temp &);
        bool copy(branch *&temp_leaf, temp);
        bool match(branch *&, int);
        bool retrieveR(branch *, temp, temp [], int &);
        int heightR(branch *);
        bool topicR(branch *&, temp, bool &);
        bool del(branch *&, temp);
        bool remove(branch *&, temp &);
        void wipe(branch *&);
        bool destroy(branch *&);

};

#endif
