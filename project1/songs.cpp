/*
Devin Smith *** Project 1 *** CS260 *** Professor Liang
This file holds all the function for adding song information
*/

#include "list.h"
using namespace std;

//cundtructor
songs::songs(){

    artist = NULL;
    title = NULL;
    length = 0;
    likes = 0;
}



//deconstructor
songs::~songs(){

    delete [] artist;
    delete [] title;
}



//wwrapper function for adduing new songs to list
bool songs::add_new(user &input, list &insert){

    bool error = false;
    //calls fucntion that builds and creates new nodes
    error = insert.add(input, insert);

    return error;
}



//copies song info into head
void songs::copy1(user &input, list &insert){

    //capies user input into the list of only head exists
    insert.head->info.artist = new char[strlen(input.artist) + 1];
    insert.head->info.title = new char[strlen(input.title) + 1];

    strcpy(insert.head->info.artist, input.artist);
    strcpy(insert.head->info.title, input.title);
    insert.head->info.length = input.length;
    insert.head->info.likes = input.likes;
}



//copies song info into the list
void songs::copy2(user &input, list &insert, node *temp){

    //copies user input into the list
    temp->info.artist = new char[strlen(input.artist) + 1];
    temp->info.title = new char[strlen(input.title) + 1];

    strcpy(temp->info.artist, input.artist);
    strcpy(temp->info.title, input.title);
    temp->info.length = input.length;
    temp->info.likes = input.likes;
}

//appends the number of likes for a song
void songs::append(user &input, list &insert){

    node * current = insert.head;

    while(current && strcmp(current->info.title, input.title) != 0){
        current = current->next;
    }

    current->info.likes = input.likes;

    cout << "Artist: " << current->info.artist << endl;
    cout << "Title: " << current->info.title << endl;
    cout << "Length: " << current->info.length << endl;
    cout << "Likes: " << current->info.likes << endl;

}

