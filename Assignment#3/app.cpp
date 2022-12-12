/*

*** Devin Smith *** Projects 3 Hash Table *** CS260 *** Professor Liang ***
This file holds the client wich the user will directly interact with
*/

#include "hashtable.h"
using namespace std;


int main(){

    int selection = 0;
    temp input;
    temp matches[100];
    int num_matches = 0;
    hash_table to_add;

    cout << "\nWelcome to the program!\n";

    to_add.read(input);

    do{

        cout << "\nPlease make a selection below! \n";
        cout << "---------------------------------\n";
        cout << "1: Add a website \n";
        cout << "2: Edit a website \n";
        cout << "3: Display websites \n";
        cout << "4: Display all \n";
        cout << "5: Remove website \n";
        cout << "6: Remove bad websites \n";
        cout << "7: Table preformance \n";
        cout << "8: Quit \n";
        cout << "Enter selection here: ";
        cin >> selection; cin.ignore(100, '\n');

        //calls fucntion to add a new website to the table
        if(selection == 1){
            cout << "\nEnter the topic of the website: ";
            cin.get(input.name, 100); cin.ignore(100, '\n');
            cout << "\nEnter sites address (url): ";
            cin.get(input.address, 100); cin.ignore(100, '\n');
            cout << "\nEnter a summary for the web page!\n->";
            cin.get(input.summary, 100); cin.ignore(100, '\n');
            cout <<"\nEnter a review for webpage!\n->";
            cin.get(input.review, 100); cin.ignore(100, '\n');
            cout << "\nEnter a rating for webpage (1-5): ";
            cin >> input.rating; cin.ignore(100, '\n');

            if(to_add.insert(input) == true){
                cout << "\nWebsite succesfully addded!\n";
            }
            else{

            }
        }
        //calls fucntion to alter data for a website in the table
        if(selection == 2){

            char temp_name[100];
            char temp_address[100];
            int choice = 0;

            while(choice < 6){
            
                cout << "\nWhat would you like to alter\n";
                cout << "--------------------------------\n";
                cout << "1: Topic\n"; 
                cout << "2: Address\n"; 
                cout << "3: Summary\n"; 
                cout << "4: Review\n";
                cout << "5: Rating\n"; 
                cout << "6: Quit\n";
                cout << "Enter choice: ";
                cin >> choice; cin.ignore(100, '\n');

                if(choice != 6){
                    cout << "\nEnter topic of website you'd like to alter: ";
                    cin.get(temp_name, 100); cin.ignore(100, '\n');
                    cout << "\nEnter the address (url, e.g. example.com) of the website you want to edit\n->";
                    cin.get(temp_address, 100); cin.ignore(100, '\n');
                }

                if(choice == 1){
                    cout << "\nEnter the new topic: "; 
                    cin.get(input.name, 100); cin.ignore(100, '\n');

                }
                if(choice == 2){
                    cout << "\nEnter the new address: "; 
                    cin.get(input.address, 100); cin.ignore(100, '\n');

                }
                if(choice == 3){
                    cout << "\nEnter the new summary: "; 
                    cin.get(input.summary, 100); cin.ignore(100, '\n');

                }   
                if(choice == 4){
                    cout << "\nEnter the new review: "; 
                    cin.get(input.review, 100); cin.ignore(100, '\n');

                }
                if(choice == 5){
                    cout << "\nEnter the new rating: "; 
                    cin >> input.rating; cin.ignore(100, '\n');

                }

                if(choice < 6){
                    if(to_add.edit(input, choice, temp_name, temp_address) == true){
                        cout << "\nWebsite was altered succusfully!\n";
                    }
                    else{
                        cout << "\nWebsite not in table or is empty!\n";
                    }
                }
            }

        }
        //calls fucntions to display all website topics searched for
        if(selection == 3){
            cout << "\nEnter topic of websites you'd like to see: ";
            cin.get(input.name, 100); cin.ignore(100, '\n');

            cout << "\nHere aer the websites with the topic you chose\n";
            cout << "--------------------------------------------------\n";

            if(to_add.search(input, matches, num_matches) == true){
                cout << "\nWebsites displayed succesfully!\n";

                cout << "\nThere were " << num_matches << " found!\n";
                cout << "\n--------------------------------------\n";
                for(int i = 0; i < num_matches; ++i){
                    cout << "\nTopic: " << matches[i].name;
                    cout << "\nAddress: " << matches[i].address;
                    cout << "\nSummary: " << matches[i].summary;
                    cout << "\nReview: " << matches[i].review;
                    cout << "\nRating: " << matches[i].rating;
                    cout << "\n--------------------------------\n";
               }
            }
            else{
                cout << "\nNo websites with this topic or table is empty!\n";
            }

        }
        //calls fucntion to display all websites
        if(selection == 4){
            cout << "\nHere are all websites!\n";
            cout << "----------------------------\n";

            if(to_add.display() == true){
                cout << "\nTable succesfully displayed!\n";
            }
            else{
                cout << "\nList is empty or does not exist!\n";
            }

        }
        //allows user to search for and remove a website
        if(selection == 5){
            cout << "Please enter the topic of the website you'd like to remove\n->";
            cin.get(input.name, 100); cin.ignore(100, '\n');
            cout << "\nEnter the address (url) of website you'd like to remove\n->";
            cin.get(input.address, 100); cin.ignore(100, '\n');

            if(to_add.remove(input) == true){
                cout << "\nWebsite succsefully removed!\n";
            }
            else{
                cout << "\nThe website didnt exist or table was empty\n";
            }

        }
        if(selection == 6){
            
            if(to_add.del_low(input) == true)
                cout << "\nAll websites with a rating of 1 or lower have been removed!\n";
            else
                cout << "\nEither table is empty or no sites have a low rating!\n";

        }
        if(selection == 7){
            if(to_add.performance() == true)
                cout << "\nTable performance succesfully displayed\n";
            else
                cout << "\nTable is empty or doesnt exist\n";
        }

    }while(selection != 8);


    cout << "\nGoodBye!\n";

    return 0;
}
