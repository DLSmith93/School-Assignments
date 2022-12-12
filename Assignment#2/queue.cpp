/*
Devin Smith *** Project #2 *** CS260 *** Professor Liang
--------------------------------------------------------
This is the cpp file that holds all the member functions
that will handele the data for the queue

*/

#include "queue.h"
using namespace std;

//constructor
queue::queue(){

    head = nullptr;
    rear = nullptr;
    
}


//deconstructor
queue::~queue(){

    if(rear){
        rear->next = nullptr;
        queueNode *current = head;

        while(current){
            head = current->next;
            delete []current->data.groupName;
            delete []current->data.spclSeating;
            delete current;
            current = head;
        }
        head = nullptr;
        rear = nullptr;
    }

}


//calls the needed to functions to either build or add to the queue
bool queue::enqueue(temp_waiting waiting){

    if(!head)
        return build(waiting);
    else
        return add(waiting);
}
        

//removes the first person from the queue
bool queue::dequeue(){

    queueNode *temp;
    int pos = 0;

    //checks if queue is empty
    if(!rear)
        return false;
        
    //checks if party is last item in the queue
    else if(head->next == head){
        //queueNode *temp = head;
        temp = head;
        delete []temp->data.groupName;
        delete []temp->data.spclSeating;
        delete temp;
        head = nullptr;
        rear = nullptr;
        --size;

        return true;

    }

    //removes the first party from the queue
    else{
        queueNode *current = head;
        head = current->next;
        delete []current->data.groupName;
        delete []current->data.spclSeating;
        delete current;
        rear->next = head;
        --size;
        temp = head;
        do{
            ++pos;
            cout << endl << pos << endl;
            temp->data.position = pos;
            temp = temp->next;
        }while(temp != head);
        return true;

    }
}


//grabs the first party in the queue
bool queue::peek(){

    if(!rear)
        return false;
    else{
        cout << "\nGroup name: " << head->data.groupName << endl;
        cout << "number of people: " << head->data.numPeople << endl;
        cout << "Special seating requests: " << head->data.spclSeating << endl;
        cout << "Position in line: " <<head->data.position << endl;
        
        return true;
    }
}


//displays list and checks party positions
int queue::dsply(int choice, temp_waiting waiting){

    queueNode *current = head;

    if(!rear)
        return 0;
    if(choice == 1){
        while(strcmp(waiting.groupName, current->data.groupName) != 0){
            current = current->next;
            return current->data.position;
        }
    }
        
    if(choice == 3)
        return size;
    
    if(choice == 4){
        do{
            cout << "\nGroup name: " << current->data.groupName << endl;
            cout << "Number of people: " << current->data.numPeople << endl;
            cout << "Special seating requests: " << current->data.spclSeating << endl;
            cout << "Postion in line: " << current->data.position << endl;
            current = current->next;
        }while(current != head);
    }
}


//saves the waitlist for a table to an external file
bool queue::saveFile(){
    
    if(!rear)
        return false;
    ofstream outFile;
    outFile.open("queue.txt");
 
    if(outFile){
        queueNode *current = head;

        do
        {
            outFile << current->data.groupName << endl;
            outFile << current->data.numPeople << endl;
            outFile << current->data.spclSeating << endl;
            current = current->next;
        }while(current != head);
        outFile.close();
    }

}


//reads in a waitlist from an external file
bool queue::readFile(temp_waiting &waiting){

    //checks if queue already exists
    if(rear)
        return false;

    else{
        ifstream inFile;
        inFile.open("queue.txt");
 
        //checking to see if in file
        if(inFile){
            inFile.get(waiting.groupName, 100); inFile.ignore(100, '\n');
            
            //loop for reading in from file
            while(!inFile.eof()){
                if(inFile){
                    inFile >> waiting.numPeople; inFile.ignore(100, '\n');
                    inFile.get(waiting.spclSeating, 100); inFile.ignore(100, '\n');
                    if(!rear){
                        build(waiting);
                    }
                    else{
                        add(waiting);
                    }
                    inFile.get(waiting.groupName, 100); inFile.ignore(100, '\n');            
                }
            }
            inFile.close();
        }
        return true;
    }

}


//changes data for party in waitlist
bool queue::append(temp_waiting change, char temp_name[], int selection, int choice){


    //calls function to remove party from queue
    if(selection == 3){
        remove(change);
        return true;
    }

    queueNode *current = head;

    //choices for appending party
    while(current->next != head && strcmp(change.groupName, current->data.groupName) != 0)
        current = current->next;

    //changes group name
    if(choice == 1){
        delete []current->data.groupName;
        current->data.groupName = new char[strlen(temp_name) + 1];
        strcpy(current->data.groupName, temp_name);

        return true;

    }

    //changes number of poeple
    if(choice == 2){
        current->data.numPeople = change.numPeople;
        
        return true;
    }

    //changes seating requests
    if(choice == 3){
        delete []current->data.spclSeating;
        current->data.spclSeating = new char[strlen(change.spclSeating) + 1];
        strcpy(current->data.spclSeating, change.spclSeating);

        return true;

    }
    
}



//builds queue if empty
bool queue::build(temp_waiting waiting){

    queueNode *temp = head;

    if(!rear){
        temp = new queueNode;
        copy(waiting, temp);
        head = temp;
        rear = temp;
        rear->next = head;

        return true;
    }
    else 
        return false;

}


//copies data entered from client into queue
bool queue::copy(temp_waiting to_copy, queueNode *temp){

    ++size;
 
    temp->data.groupName = new char[strlen(to_copy.groupName) + 1];
    temp->data.spclSeating = new char[strlen(to_copy.spclSeating) + 1];

    strcpy(temp->data.groupName , to_copy.groupName );
    temp->data.numPeople = to_copy.numPeople;
    strcpy(temp->data.spclSeating , to_copy.spclSeating );
    temp->data.position = size;

    return true;
}
        

//adds partys to end of queue
bool queue::add(temp_waiting waiting){

    if(rear){
        
        queueNode *current = new queueNode;
        
        copy(waiting, current);

        rear->next = current;
        rear = current;
        rear->next = head;

        return true;
    }
    else 
        return false;

}
 

//fucntion for removing party from queue
bool queue::remove(temp_waiting change){

    queueNode *previous = nullptr;
    queueNode *current = head;
    queueNode *temp = head;
    int pos = 0;

    if(!rear)
        return false;

    //checks if party being removed is last item in queue
    else if(head->next == head){
        
        //queueNode *temp = head;
        delete []temp->data.groupName;
        delete []temp->data.spclSeating;
        delete temp;
        head = nullptr;
        rear = nullptr;
        --size;
        

        return true;
    }
        
    //checks if the party beinf removed is head
    else if(strcmp(change.groupName, head->data.groupName) == 0){

        current = head;
        head = current->next;
        delete []current->data.groupName;
        delete []current->data.spclSeating;
        delete current;
        rear->next = head;
        --size;

        do{
            ++pos;
            cout << endl << pos << endl;
            temp->data.position = pos;
            temp = temp->next;
        }while(temp != head);

        return true;
    }

    //checks if the party beinf removed is rear
    else if(strcmp(change.groupName, rear->data.groupName) == 0){

        while(current->next != head){
            previous = current;
            current = current->next;
        }

        cout << current->data.groupName << endl;
        rear = previous;
        delete []current->data.groupName;
        delete []current->data.spclSeating;
        delete current;
        rear->next = head;
        --size;

        return true;
        
    }

    //this removes partys in the middle of the queue
    else{

        while(current->next != head){
            if(strcmp(change.groupName, current->data.groupName) == 0){
                if(previous)
                    previous->next = current->next;
                previous->next = current->next;
                delete []current->data.groupName;
                delete []current->data.spclSeating;
                delete current;
                current = previous->next;
                --size;
            }
            else{
                previous = current;
                current = current->next;
            }
        }
        do{
            ++pos;
            cout << endl << pos << endl;
            temp->data.position = pos;
            temp = temp->next;
        }while(temp != head);
    }
   
    return true;
}

bool destroy(){

}

