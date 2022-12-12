/*
Devin Smith *** Project 1 *** CS260 *** Professor Liang
This files holds all the functions for maintinging the list of songs
*/

#include "list.h"
using namespace std;

//constructer fucntion
list::list(){

    head = NULL;
    //head->info.artist = NULL;
    //head->info.title = NULL;
    //head->info.length = 0;
    //head->info.likes = 0;
  
}



//deconstructor fucntion
list::~list(){

    node *current = head;

    while(current){
        head = current->next;
        delete current;
        current = head;
    }
}



//builds and adds new song to list
bool list::add(user &input, list &insert){

    node *temp = new node;

    //builds the list
    if(!head){
        head = new node;
        to_add.copy1(input, insert);
        head->next = nullptr;
        
        return true;
    }
    //checks if song entered has more likes than head
    else if(head->info.likes < input.likes){
        if(strcmp(head->info.title, input.title) == 0){
            return false;
         }
        to_add.copy2(input, insert, temp);
        temp->next = head;
        head = temp;
        
        return true;
    }
    //adds song in list in apropriate order
    else{
        node *current = head;
        node *previous = head;
        node *test = head;

        //checks to see if the song is already in the list
        while(test){
            if(strcmp(test->info.title, input.title) == 0)
                return false;
            test = test->next;
        }

        to_add.copy2(input, insert, temp);


        while(current && current->info.likes >= input.likes){
            previous = current;
            current = current->next;
        }

        previous->next = temp;
        temp->next = current;

        return true;

    }
}



//wrapper function for recursive display
bool list::display(list &insert){

    node *temp = head;
    
    //calls recursive fucntion
    print(temp);

    if(head)
        return true;
    else 
        return false;

}



//recursice function for displaying list
void list::print(node *temp){

    if(!temp)
        return;

    cout << "\nArtist: " << temp->info.artist << endl;
    cout << "Title: " << temp->info.title << endl;
    cout << "Length: " << temp->info.length << endl;
    cout << "Likes: " << temp->info.likes << endl;
    
    print(temp->next);
}



//displays all songs of artist searched by user
bool list::search(user input){

    node *current = head;
    bool error = false;
    

    while(current){
        if(strcmp(current->info.artist, input.artist) == 0){
            cout << "\nArtist: " << current->info.artist << endl;
            cout << "Title: " << current->info.title << endl;
            cout << "Length: " << current->info.length << endl;
            cout << "Likes: " << current->info.likes << endl;

            error = true;
        }
        current = current->next;
    }

    return error;
}



//deletes all songs under specific amount of likes entered
//by user
bool list::del(user input){
    node *current = head;
    node *temp = NULL;
    bool error = false;

    if(!head){
        return false;
    }

    if(input.likes > head->info.likes){

        while(current){
            head = current->next;
            delete current;
            current = head;
        }
        return true;
    }

    while(current){

        if(current->info.likes < input.likes){
            if(temp){
                temp->next = current->next;
            }
            delete current;
            current = temp->next;
            error = true;
        }
        else{
            temp = current;
            current = current->next;
        }
   }

   return error;
}



//reads in song info from an external text file
bool list::loadfile(user &input, list &insert){

    ifstream inFile;
    inFile.open("input.txt");
    bool error = false;

    if(!inFile)
        error =  false;
    if(inFile){

        inFile.get(input.artist, 100, '\n'); inFile.ignore(100, '\n');
        while(!inFile.eof()){
              
            inFile.get(input.title, 100, '\n'); inFile.ignore(100, '\n');
            inFile >> input.length; inFile.ignore(100, '\n');
            inFile >> input.likes; inFile.ignore(100, '\n');

            //calls fucntion to add song info into list
            add(input, insert);

            inFile.get(input.artist, 100, '\n'); inFile.ignore(100, '\n');

        }

        error = true;
    }

    inFile.close();
    return error;
}



//saves the list to and external file
bool list::savefile(user &input, list &insert){

    ofstream outFile;
    outFile.open("input.txt");

    if(outFile){
        node *current = head;

        while(current){
            outFile << current->info.artist << endl;
            outFile << current->info.title << endl;
            outFile << current->info.length << endl;
            outFile << current->info.likes << endl;

            current = current->next;
       }
       outFile.close();
       return true;
   }
   else
       return false;
}
