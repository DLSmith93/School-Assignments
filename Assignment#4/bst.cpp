
/*
    Program #4
    ----------
    Devin Smith *** CS260 *** Professor Liang
    -----------------------------------------
    This is the cpp file that holods all the code that manipulates the tree

*/

#include "bst.h"
using namespace std;

///    Public Functions    \\\

tree::tree(){
    root = nullptr;
}


tree::~tree(){
    if(root)
        destroy(root);

}

//helper function for insertinfg a node into the tree
bool tree::insert(temp input){

    //branch *temp_leaf = root;
 
    return add(root, input);
}


//fucntion for creating the key of each node
int tree::keyGen(temp input){

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < strlen(input.topic); ++i)
        sum1 += tolower(input.topic[i]);
    for(int n = 0; n < strlen(input.address); ++n)
        sum2 += tolower(input.address[n]);

    cout << endl << sum1 + sum2 << endl;

    return (sum1 + sum2);
}


//helper function for prive search fucntion
bool tree::search(temp input){
    //int search_key = (tolower(input.topic[0]) + tolower(input.address[0]));
    int search_key = keyGen(input);


    if(!root)
        return false;
    else
        return match(root, search_key);
}


//helper fucntion for calling recursive display
bool tree::display(){

    bool error = false;

    if(!root)
        return error;
    else
        ordered(root, error);
        return error;
}


//helper fucntion that calls private member for retrieving topic
bool tree::retrieve(temp input, temp found[], int &numFound){
    if(!root)
        return false;
    else{
        numFound = 0;
        return retrieveR(root, input, found, numFound);
    }
}


//helper function that calls the private members needed to remove
bool tree::delHelper(temp input){

    return del(root, input);
}


//reads in data from an external file
bool tree::read(temp &input){

    //checks to see if the tree already exists
    if(root)
        return false;
    else{
        ifstream inFile;
        inFile.open("bst.txt");

        if(inFile){
            inFile.get(input.topic, 100); inFile.ignore(100, '\n');

            while(!inFile.eof()){
                inFile.get(input.address, 100); inFile.ignore(100, '\n');
                inFile.get(input.summary, 100); inFile.ignore(100, '\n');
                inFile.get(input.review, 100); inFile.ignore(100, '\n');
                inFile >> input.rating; inFile.ignore(100, '\n');
                //input.key = (tolower(input.topic[0]) + tolower(input.address[0]));
                input.key = 0;
                input.key = keyGen(input);

                insert(input);

                inFile.get(input.topic, 100); inFile.ignore(100, '\n');

            }                
            inFile.close();
        }

        return true;

    }
}


//calls functions that calcualties the height of the tree
int tree::height(){

    return heightR(root);
}


//calls the recursive function that deletes all sites of a specific topic
bool tree::remove_topic(temp search){

    bool error = false;

    if(!root)
        return false;
    else{
        topicR(root, search, error);
        return error;
    }
}



///    Private Fucntions    \\\

//adds a new node to the tree
bool tree::add(branch *& temp_leaf, temp &input){

    if(!temp_leaf){
        temp_leaf = new branch;
        copy(temp_leaf, input);
        temp_leaf->left = nullptr;
        temp_leaf->right = nullptr;
    }
    else if(input.key < temp_leaf->data.key)
       add(temp_leaf->left, input);
    else 
       add(temp_leaf->right, input);

    return true;
}


//recursively displays the tree in order
bool tree::ordered(branch *&temp_leaf, bool &error){

    if(!temp_leaf)
        return error;
    else{
        ordered(temp_leaf->left, error);
        cout << "\n==========================\n";
        cout << "Topic: " << temp_leaf->data.topic << endl;
        cout << "Adress: " << temp_leaf->data.address << endl;
        cout << "Summary: " << temp_leaf->data.summary << endl;
        cout << "Review: " << temp_leaf->data.review << endl;
        cout << "Rating: " << temp_leaf->data.rating << endl;
        cout << "Key: " << temp_leaf->data.key << endl;
        ordered(temp_leaf->right, error);

        error = true;
    }

    
}


//universal fucntion for copying data into a node
bool tree::copy(branch *&temp_leaf, temp input){

    if(!temp_leaf)
        return false;
    else{
        temp_leaf->data.topic = new char[strlen(input.topic) + 1];
        temp_leaf->data.address = new char[strlen(input.address) + 1];
        temp_leaf->data.summary = new char[strlen(input.summary) + 1];
        temp_leaf->data.review = new char[strlen(input.review) + 1];
        
        strcpy(temp_leaf->data.topic, input.topic);
        strcpy(temp_leaf->data.address, input.address);
        strcpy(temp_leaf->data.summary, input.summary);
        strcpy(temp_leaf->data.review, input.review);
        temp_leaf->data.rating = input.rating;
        temp_leaf->data.key = input.key;

        return true;
    }
}


//recursive fucntion called by search fucntion
bool tree::match(branch *&temp_leaf, int search_key){

    if(temp_leaf->data.key == search_key){
        cout << "Topic: " << temp_leaf->data.topic << endl;
        cout << "Adress: " << temp_leaf->data.address << endl;
        cout << "Summary: " << temp_leaf->data.summary << endl;
        cout << "Review: " << temp_leaf->data.review << endl;
        cout << "Rating: " << temp_leaf->data.rating << endl;
        cout << "Key: " << temp_leaf->data.key << endl;
        
        return true;
    }
    else if(search_key < temp_leaf->data.key)
         return match(temp_leaf->left, search_key);
    else if(search_key > temp_leaf->data.key)
        return match(temp_leaf->right, search_key);
}


//recursive function for retrieving all nodes of a topic
bool tree::retrieveR(branch *temp_leaf, temp search, temp found[], int &numFound){

    if(!temp_leaf)
        return true;
    else{
        retrieveR(temp_leaf->left,search, found, numFound);
        //if topic matches it is copied into an array to be displayed in the client
        if(strcmp(search.topic, temp_leaf->data.topic) == 0){
            strcpy(found[numFound].topic, temp_leaf->data.topic);    
            strcpy(found[numFound].address, temp_leaf->data.address);    
            strcpy(found[numFound].summary, temp_leaf->data.summary);    
            strcpy(found[numFound].review, temp_leaf->data.review);
            found[numFound].rating = temp_leaf->data.rating;
            found[numFound].key = temp_leaf->data.key;    
            ++numFound;
        }
        retrieveR(temp_leaf->right,search, found, numFound);
    }
    return true;
}


//calculates the height of the tree
int tree::heightR(branch *current){

    if(!current){
        return 0;
    }

    int height1 = heightR(current->left);
    int height2 = heightR(current->right);

    if(height1 > height2)
        return (height1 + 1);
    else
        return (height2 +1);
}


//recursive function for deleting all sites of a specific topic
bool tree::topicR(branch *&current, temp search, bool &error){

    if(!current)
        return error;

    //travells left then right
    topicR(current->left, search, error);
    topicR(current->right, search, error);

    //if a match website is deleted
    if(strcmp(search.topic, current->data.topic) == 0){
            remove(current, search);
            error = true;
    }
}



//recursive function that finds node to be deleted
bool tree::del(branch *&current, temp find){
    
    if(!current)
        return false;
    //int key = (tolower(find.topic[0]) + tolower(find.address[0]));
    int search_key = keyGen(find);
    //checks if node matches one to be deleted
    if(search_key == current->data.key){
        remove(current, find);
        return true;
    }
    else if(search_key < current->data.key)
        return del(current->left, find);
    else
        return del(current->right, find);

}



//fucntion to delete a node from the tree
bool tree::remove(branch *&current, temp &find){
    
    //current node has no children
    if(!current->left && !current->right){
        wipe(current);
        current = nullptr;
    }
    //curren node has only a left child
    else if(!current->right){
        branch *temp = current;
        current = current->left;
        wipe(temp);
    }
    //current nope has only a rigth child
    else if(!current->left){
        branch *temp = current;
        current = current->right;
        wipe(temp);
    }
    //current node has two children
    else
    {
        //find the inorder successor of current node     
        branch * prev = nullptr;
        branch *curr = current->right;
        if(!curr->left)              
            current->right = curr->right;
        else{
            while(curr->left){
                prev = curr;
                curr = curr->left;    
            }
            prev->left = curr->right;
        }

        //deletes data in node to be replaced
        delete []current->data.topic;
        delete []current->data.address;
        delete []current->data.summary;
        delete []current->data.review;

        //copies data from node to be placed in new node
        strcpy(find.topic, curr->data.topic);
        strcpy(find.address, curr->data.address);
        strcpy(find.summary, curr->data.summary);
        strcpy(find.review, curr->data.review);
        find.rating = curr->data.rating;
        find.key = curr->data.key;
        copy(current, find);

        wipe(curr);

        return true;
    }

}



//universal function for deleting a node and its data
void tree::wipe(branch *&temp){

    delete []temp->data.topic;
    delete []temp->data.address;
    delete []temp->data.summary;
    delete []temp->data.review;
    delete temp;

}

//recursive destruction function called by the deconstructor
bool tree::destroy(branch *&current){
    
    if(current)
        {
            destroy(current->left);
            destroy(current->right);
            wipe(current);
            current = nullptr;
        }

}
