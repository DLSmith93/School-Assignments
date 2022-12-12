
/*
    Program #4
    ----------
    Devin Smith *** CS260 *** Professor Laing
    -----------------------------------------
    This is the main client for testing the Binary search tree

*/

#include "bst.h"
using namespace std;

int main(){

    tree to_add;
    temp input;
    temp found[100];
    int select = 0;
    int numFound = 0;

    to_add.read(input);
    cout << "\nWelcome to the program!\n";
    cout << "\n------------------------";

    do{
        cout << "\n\n1: Insert";
        cout << "\n2: Search";
        cout << "\n3: Remove";
        cout << "\n4: Romove topic";
        cout << "\n5: Display all";
        cout << "\n6: Dsiplay topic";
        cout << "\n7: Tree height";
        cout << "\n8: Quit";
        cout << "\nPlease enter selection -> ";
        cin >> select; cin.ignore(100, '\n');

        //menu option for adding an item into the tree
        if(select == 1){
            cout << "\nPlease enter the name of the topic (e.g. Socail Media)\n";
            cout << "-> ";
            cin.get(input.topic, 100); cin.ignore(100, '\n');

            cout << "\nPlease enter the addres or url (e.g. youtube.com\n";
            cout << "-> ";
            cin.get(input.address, 100); cin.ignore(100, '\n');

            cout << "\nPlease enter a summary for the webpage\n";
            cout << "-> ";
            cin.get(input.summary, 100); cin.ignore(100, '\n');

            cout << "\nPlease enter a review for the website\n";
            cout << "-> ";
            cin.get(input.review, 100); cin.ignore(100, '\n');

            cout << "\nPlease enter a rating from 1-5 -> ";
            cin >> input.rating; cin.ignore(100, '\n');

            input.key = to_add.keyGen(input);

            //input.key = (tolower(input.topic[0]) + tolower(input.address[0]));

            if(to_add.insert(input) == true)
                cout << "\nWebsite successfuly added!\n";
            else
                cout << "\nTask failed!\n";

        }
        //menu option for searching for a topic
        if(select == 2){
            cout << "\nPlease enter the topic of the website youd like to search for\n";
            cout << "-> ";
            cin.get(input.topic, 100); cin.ignore(100, '\n');

            cout << "\nPlease enter the address for the website you'd like to search for\n";
            cout << "-> ";
            cin.get(input.address, 100); cin.ignore(100, '\n');

            if(to_add.search(input) == true)
                cout << "\nMatch found!\n";
            else
                cout << "\nNo match or tree is empty!\n";

        }
        //menu option for removing a website
        if(select == 3){
            cout << "\nPlease enter the topic of the website youd like to remove\n";
            cout << "-> ";
            cin.get(input.topic, 100); cin.ignore(100, '\n');

            cout << "\nPlease enter the address for the website you'd like to remove\n";
            cout << "-> ";
            cin.get(input.address, 100); cin.ignore(100, '\n');
            
            if(to_add.delHelper(input) == true)
                cout << "\nWebsite was successfuly removed!\n";
            else
                cout << "\nWebsite not found or tree is empty!\n";

        }
        //menu option for removing all websites of a specific topic
        if(select == 4){
            cout << "\nPlease enter the topic that youd like to remove\n";
            cout << "-> ";            
            cin.get(input.topic, 100); cin.ignore(100, '\n');

            bool error = to_add.remove_topic(input);
            if(error == true)
                cout << "\nAll websites of the topic have been removed!\n";
            else
                cout << "\nTopic dosnt exist or tree is empty!\n";
        }
        //menu option for displaying the entire tree
        if(select == 5){
            if(to_add.display() == true)
                cout << "\nA tree exists!!\n";
            else
                cout << "\nThere is no tree!!\n";
        }
        //menu option for displaying a specific topic
        if(select == 6){
            cout << "\nPlease enter the topic of websites you'd like to see\n";
            cout << "-> ";
            cin.get(input.topic, 100); cin.ignore(100, '\n');

            if(to_add.retrieve(input, found, numFound) == true)
                cout << "\nTopic found!\n";
            else
                cout << "\nTopc not found or tree is empty!\n";
        
            cout << numFound << " matches were found!\n";

            for(int i = 0; i < numFound; ++i){
                cout << "\n=============================";
                cout << "\nTopic: " << found[i].topic;
                cout << "\nAddress: " << found[i].address;
                cout << "\nSummary: " << found[i].summary;
                cout << "\nReview: " << found[i].review;
                cout << "\nRating: " << found[i].rating;
                cout << "\nkey; " << found[i].key;
            }
        }
        //menu option for displaying the heigth of the tree
        if(select == 7){
            int height = to_add.height();

            if(height > 0)
                cout << "\nThe tree has a current height of " << height << " !\n";
            else
                cout << "\nThe tree is currently empty!\n";

        }


    }while(select < 8);

    cout << "\nGoodBye!\n";

    return 0;

}
