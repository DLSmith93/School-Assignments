/*

*** Devin Smith *** Projects 3 Hash Table *** CS260 *** Professor Liang ***
This file holds all the fucntions that will alter the data structures in the class
*/

#include "hashtable.h"
using namespace std;

///   Public Functions   \\\

hash_table::hash_table(){


    for(int i = 0; i < 26; ++i){
        table[i].head = nullptr;
    }
}
hash_table::~hash_table(){

    for(int i = 0; i < 26; ++i){
        node *temp = table[i].head;

        if(temp){
            while(temp){
                table[i].head = temp->next;

                delete []temp->data.name;
                delete []temp->data.address;
                delete []temp->data.summary;
                delete []temp->data.review;
                delete temp;

                temp = table[i].head;;
            }
        }
    }
}



//calls the fucntions to eithjer build or add an item to a list in the table
bool hash_table::insert(temp to_add){

    hash_key(to_add);

    if(!table[key].head)
        return build(to_add);
    else
        return add(to_add);

}



//displays everything in the table
bool hash_table::display(){
    
    for(int i = 0; i < 26; ++i){
        node *current = table[i].head;
        if(table[i].head){
            cout << "\nChain #" << i + 1 << " -- Colisions: " << table[i].colisions << endl;
            cout << "================================\n";
        
        while(current){
            cout << "\nTopic: " << current->data.name;
            cout << "\nAddress:  " << current->data.address;
            cout << "\nSummary:  " << current->data.summary;
            cout << "\nReview:  " << current->data.review;
            cout << "\nRating:  " << current->data.rating;
            cout << "\n----------------------\n";
            current = current->next;
        }
        }
    }
    return true;
}



//searches and displays all sites of a specific topic
bool hash_table::search(temp search, temp found[], int &num_matches){

    hash_key(search);

    if(!table[key].head)
        return false;
    else
        return retrieve(search, found, num_matches);

}



//edits a website
bool hash_table::edit(temp &to_change, int choice, char temp_name[], char temp_address[]){

    node *current = table[tolower(temp_name[0]) - 97].head;
    node *previous;

    cout<<current->data.name<<endl;

    while(current && strcmp(temp_address, current->data.address) != 0){
        previous = current;
        current = current->next;
    }

    if(choice == 1){

        delete []current->data.name;
        current->data.name = new char[strlen(to_change.name + 1)];
        strcpy(current->data.name, to_change.name);

        
        strcpy(to_change.name, current->data.name);
        strcpy(to_change.address, current->data.address);
        strcpy(to_change.summary, current->data.summary);
        strcpy(to_change.review, current->data.review);
        to_change.rating = current->data.rating;

        --table[tolower(temp_name[0]) - 97].colisions;

        node *temp = current;

        if(current == table[tolower(temp_name[0]) - 97].head)
            table[tolower(temp_name[0]) - 97].head = temp->next;
        else
            previous->next = current->next;
        delete []temp->data.name;
        delete []temp->data.address;
        delete []temp->data.summary;
        delete []temp->data.review;
        delete temp;

        insert(to_change);
        
    }
    if(choice == 2){
        delete []current->data.address;
        current->data.address = new char[strlen(to_change.address + 1)];
        strcpy(current->data.address, to_change.address);
    }
    if(choice == 3){
        delete []current->data.summary;
        current->data.summary = new char[strlen(to_change.summary + 1)];
        strcpy(current->data.summary, to_change.summary);

    }
    if(choice == 4){
        delete []current->data.review;
        current->data.review = new char[strlen(to_change.review + 1)];
        strcpy(current->data.review, to_change.review);

    }
    if(choice == 5){
        current->data.rating = to_change.rating;
    }

    return true;
}



//trverses teh table then calls fuxntion to remove website from table
bool hash_table::remove(temp to_remove){

    hash_key(to_remove);
    
    if(table[key].head){
        node *temp = table[key].head;
        node *previous;

        while(temp && strcmp(temp->data.address, to_remove.address) != 0){
            previous = temp;
            temp = temp->next;
        }

        del(temp, previous);
        return true;
    }
    else 
        return false;
}


//deletes all websites with a rating of 1 or lower
bool hash_table::del_low(temp &to_remove){

    node *temp;
    node *previous;
    bool error = false;

    for(int i = 0; i < 26; ++i){
        if(table[i].head){
            temp = table[i].head;
            strcpy(to_remove.name, temp->data.name);
            hash_key(to_remove);

            while(temp){
                if(temp->data.rating < 2){
                    del(temp, previous);
                    error = true;
                }
                previous = temp;
                temp = temp->next;
            }
        }
    }

    return error;

}



//displays how many collsions each chain of the table has
bool hash_table::performance(){

    bool error = false;

    for(int i = 0; i < 26; ++i){
        if(table[i].head){
            cout << "\nChain " << i + 1 << " has " << table[i].colisions << " colision/s!\n";
            error = true;
        }
    }

    return error;
}


///   Private Functions   \\\

//builds each of the list in the table
bool hash_table::build(temp to_add){

    node *temp = table[key].head;
    temp = new node;

    copy(to_add, temp);

    table[key].head = temp;

    return true;

}



//adds a node to each list in th table
bool hash_table::add(temp to_add){

    if(!table[key].head)
        return false;
    else{;
        node *temp = new node;
        copy(to_add, temp);
        temp->next = table[key].head;
        table[key].head = temp;

        return true;

    }

}


//generates the hash key for the table
void hash_table::hash_key(temp to_add){

    key = tolower(to_add.name[0]) - 97;

}


//copies data from the client into a new node
bool hash_table::copy(temp to_add, node *&insert){

    ++table[key].colisions;

    insert->data.name = new char[strlen(to_add.name) + 1];
    insert->data.address = new char[strlen(to_add.address) + 1];
    insert->data.summary = new char[strlen(to_add.summary) + 1];
    insert->data.review = new char[strlen(to_add.review) + 1];

    strcpy(insert->data.name , to_add.name);
    strcpy(insert->data.address , to_add.address);
    strcpy(insert->data.summary , to_add.summary);
    strcpy(insert->data.review , to_add.review);
    insert->data.rating = to_add.rating;

    return true;

}



//reads data in from external file
bool hash_table::read(temp &to_add){

    ifstream inFile;
    inFile.open("hashtable.txt");

    if(!inFile)
        return false;
    if(inFile){

        inFile.get(to_add.name, 100); inFile.ignore(100, '\n');
        while(!inFile.eof()){
            inFile.get(to_add.address, 100); inFile.ignore(100, '\n');
            inFile.get(to_add.summary, 100); inFile.ignore(100, '\n');
            inFile.get(to_add.review, 100); inFile.ignore(100, '\n');
            inFile >> to_add.rating; inFile.ignore(100, '\n');

            insert(to_add);

            inFile.get(to_add.name, 100); inFile.ignore(100, '\n');
        }

    }

    return true;

}



//deletes a website from the table
void hash_table::del(node *&temp, node *&previous){

    if(temp == table[key].head)
        table[key].head = temp->next;
    else
        previous->next = temp->next;

    --table[key].colisions;

    delete []temp->data.name;
    delete []temp->data.address;
    delete []temp->data.summary;
    delete []temp->data.review;
    delete temp;


}


//copies found webistes into an array to be displayed by the client
bool hash_table::retrieve(temp search, temp found[], int &num_matches){

    node *current = table[tolower(search.name[0]) - 97].head;
    int i = 0;

    while(current){

        if(strcmp(current->data.name, search.name) == 0){
            strcpy(found[i].name, current->data.name);
            strcpy(found[i].address, current->data.address);
            strcpy(found[i].summary, current->data.summary);
            strcpy(found[i].review, current->data.review);
            found[i].rating = current->data.rating;
            ++num_matches;
            ++i;
        }
        current = current->next;
    }
    return true;

}



