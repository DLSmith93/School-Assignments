/*
Devin Smith *** Project #2 *** CS260 *** Professor Liang
--------------------------------------------------------
This is the cpp file that holds all the member fucntions 
that manages the stack.

*/

#include "queue.h"
using namespace std;

//constructor
stackList::stackList(int CAP){

    MAX_CAP = CAP;
    top = 0;

    //head->patrons = nullptr;
    head = nullptr;
}


//deconstructor
stackList::~stackList(){
    stackNode *current = head;

    if(head)
        destroy(current);

    head = nullptr;    
}


//push fucntion
bool stackList::push(temp_contact to_add){

    //checks if head is nullptr
    if(!head){
         build(to_add);
    }
    else{
         add(to_add);
    }
}



bool stackList::pop(int choice, temp_contact to_remove){
    //saveFile();
    stackNode *current = head;

    //checks if head is nullptr
    if(!head)
        return false;

    else{
        //pops the top entry until 0
        if(top >= 0 && head != nullptr){
            //if(top > 0)
                --top;
            if(top >= 0){
                cout << "\nName: " << current->patrons[top].name << endl;
                cout << "Email: " << current->patrons[top].email << endl;
            }
            if(top >= 0){
                delete []current->patrons[top].name;
                delete []current->patrons[top].email;
            }

            return true;
        }
        //deletes head then sets top to max
        else{
            if(head->next == nullptr){
                top = MAX_CAP;
                delete []current->patrons;
                delete current;
                head = nullptr;
            }
            else{
                top = MAX_CAP;
                head = head->next;
                delete []current->patrons;
                delete current;
                //top = MAX_CAP - 1;
            }
            
            return true;
        }      

    }

}


//fucntion for counting entries and peeking the most recent
int stackList::peek(int choice){

    if(choice == 2){
        cout << "\nName: " << head->patrons[top - 1].name << endl;
        cout << "Email: " << head->patrons[top - 1].email << endl;
    }
    else if(choice == 3){
        stackNode *current = head;
        int count = 0;
        int temp_top = top - 1;
        while(current){
            for(int i = temp_top; i >= 0; --i){
                ++count;
            }
            temp_top = MAX_CAP - 1;
            current = current->next;
        }
        return count;
    }
    else{
        if(head){
            cout << "\nName: " << head->patrons[top - 1].name << endl;
            cout << "Email: " << head->patrons[top - 1].email << endl;
        }

    }
        
}


//displays the entire stack
bool stackList::display(){
    stackNode *current = head;
    int temp_top = top - 1;

    if(!head)
        return false;

    while(current){
        for(int i = temp_top; i >= 0; --i){
            cout << "\nName: " << current->patrons[i].name << endl; 
            cout << "Email: " << current->patrons[i].email << endl;
        }
        temp_top = MAX_CAP - 1;
        current = current->next;
    }
    
    return true;
}


//reads entries from an external file into stack
bool stackList::readFile(temp_contact &to_add){
    ifstream inFile;
    inFile.open("stack.txt");

    //checks if file was opened succesfully
    if(!inFile)
        return false;

    //checks if head is nullptr
    if(!head){
        if(inFile){
            inFile.get(to_add.name, 100, '\n'); inFile.ignore(100, '\n');
            while(!inFile.eof()){
                inFile.get(to_add.email, 100, '\n'); inFile.ignore(100, '\n');
                push(to_add);
                inFile.get(to_add.name, 100, '\n'); inFile.ignore(100, '\n');
            }
            inFile.close();
        }
        return true;
    }


}


//saves entries from stack into external file
bool stackList::saveFile(){
    ofstream outFile;
    outFile.open("stack.txt");

    stackNode *current = head;
    int temp_top = top - 1;

    //checks if file was opened
    if(!outFile)
        return false;

    if(outFile){
        while(current){
            for(int i = temp_top; i >= 0; --i){
                outFile << current->patrons[i].name << endl;
                outFile << current->patrons[i].email << endl;

            }
            temp_top = MAX_CAP - 1;
            current = current->next;
        }
        outFile.close();

    }

    return true;

}


//builds list and enters first entry into stack
bool stackList::build(temp_contact to_add){
    if(!head){
        stackNode *temp = head;
        temp = new stackNode;
        temp->patrons = new contact[MAX_CAP];
        copy(to_add, temp);
        head = temp;
        ++top;

        return true;
    }

}


//adds entries into stack
bool stackList::add(temp_contact to_add){
    stackNode *temp = head;
 
    if(!head)
        return false;
    //adds entries until top = MAX_CAP
    if(top < MAX_CAP){
        copy(to_add, temp);
        ++top;

        return true;
    }

    //adds a new node tp front of list then resets top
    else{
        top = 0;
        temp = new stackNode;        
        temp->patrons = new contact[MAX_CAP];
        copy(to_add, temp);
        temp->next = head;
        head = temp;
        ++top;

        return true;
    }


}


//copies data from client into stack
bool stackList::copy(temp_contact to_add, stackNode *temp){

    if(!temp)
        return false;
        
    temp->patrons[top].name = new char[strlen(to_add.name)];
    temp->patrons[top].email = new char[strlen(to_add.email)];

    strcpy(temp->patrons[top].name, to_add.name);
    strcpy(temp->patrons[top].email, to_add.email);
    

    return true;
}


//destroys the stack
bool stackList::destroy(stackNode *current){

    //checks if head is nullptr    
    if(!head)
        return false;
    else{
        int temp_top = top - 1;
        while(current){
            head = current->next;
            for(int i = temp_top; i >= 0; --i){
                delete []current->patrons[i].name;
                delete []current->patrons[i].email;
            }
            delete []current->patrons;
            delete current;
            current = head;
            temp_top = MAX_CAP -1;
        }

    }

    return true;
}

