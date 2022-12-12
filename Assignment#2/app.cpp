/*
Devin Smith *** Project #2 *** CS260 *** Professor Liang
--------------------------------------------------------
This is the client. This is what the user will be interacting with.
All data will be read in from here. The user will not interact
directly with the member functions and the data of the data structures.

*/

#include "queue.h"
#include "stack.h"
using namespace std;

int main(){
    int CAP = 0;

    cout << "\nWelcome to the test client!" << endl;
    cout << "---------------------------\n" << endl;
    cout << "\nEnter capacity for the promotions stack: ";
    cin >> CAP;
    cout << endl;

    temp_contact contact;
    temp_waiting waiting;
    queue waitlist;
    stackList promotions(CAP);
    int selection = 0;
    int choice = 0;
    char temp_name[100];

    if(waitlist.readFile(waiting) == true)
        cout << "\nWaitlist read in from file\n";
    if(promotions.readFile(contact) == true)
        cout << "\nContact list read in\n";

    do{


        cout << "\nPlease make a menu selection" << endl;
        cout << "-----------------------------" << endl;
        cout << "1: Add party to waitlist" << endl;
        cout << "2: Append party" << endl;
        cout << "3: Remove party" << endl;
        cout << "4: Check waitlist" << endl;
        cout << "5: Seat Party" << endl;
        cout << "6: Add patrons to promotions" << endl;
        cout << "7: Check patrons" << endl;
        cout << "8: Contact most recent" << endl;
        cout << "9: Quit" << endl;
        cout << "Enter here: ";
        cin >> selection; cin.ignore(100, '\n');

        //adding party to waitlist
        if(selection == 1){

            char answer;

            cout << "\nPlease enter the name of the party: ";
            cin.get(waiting.groupName, 100); cin.ignore(100, '\n');

            cout << "How many people are in  the party: ";
            cin >> waiting.numPeople; cin.ignore(100, '\n');

            cout << "Does anyone require special seating: ";
            cin.get(waiting.spclSeating, 100); cin.ignore(100, '\n');

            cout << "Do you want to recieve special promotions? y/n: ";
            cin >> answer; cin.ignore(100, '\n');

            if(waitlist.enqueue(waiting) == true)
                cout << "\nParty added to List\n";
            else
                cout << "\nParty did not add to queue\n";

            //add to conact list if yes
            if(answer == 'y'){

                cout << "What is the pary leaders name: ";
                cin.get(contact.name, 100); cin.ignore(100, '\n');

                cout << "What is the party leaders email: ";
                cin.get(contact.email, 100); cin.ignore(100, '\n');

                promotions.push(contact);
            }

        }

        //changes info for specific party
        if(selection == 2){
            cout << "\nWhat party do you want to change: ";
            cin.get(waiting.groupName, 100); cin.ignore(100, '\n');
            selection = 0;

            while(choice != 4){
                cout << "\nWhat do you want to change?\n";
                cout << "1: Party name?\n";
                cout << "2: Number of people?\n";
                cout << "3: Seating requests?\n";
                cout << "4: Done\n";
                cout << "Enter here: ";
                cin >> choice; cin.ignore(100, '\n');

                if(choice == 1){
                    cout << "\nEnter new name for party: ";
                    cin.get(temp_name, 100); cin.ignore(100, '\n');
                    if(waitlist.append(waiting, temp_name, selection, choice) == true)
                        cout << "\nName for party changed\n";
                    else
                        cout << "Party does not exist or queue empty\n";
                }
                if(choice == 2){
                    cout << "\nEnter new number of people: ";
                    cin >> waiting.numPeople; cin.ignore(100, '\n');
                    if(waitlist.append(waiting, temp_name, selection, choice) == true)
                        cout << "\nNumber of people changed\n";
                    else
                        cout << "Party does not exist or queue empty\n";
                }
                if(choice == 3){
                    cout << "\nEnter new seating requests: ";
                    cin.get(waiting.spclSeating, 100); cin.ignore(100, '\n');
                    if(waitlist.append(waiting, temp_name, selection, choice) == true)
                        cout << "\nSeating request changed\n";
                    else
                        cout << "Party does not exist or queue empty\n";
                }
            }
        }

        //removes secific party from waitlist
        if(selection == 3){
            cout << "\nWhat party do you want to remove?";
            cin.get(waiting.groupName, 100); cin.ignore(100, '\n');

            //using this as a wrapper function because remove is private
            if(waitlist.append(waiting, temp_name, selection, choice) == true)
                cout << "\nParty was removed from queue\n";
            else
                cout << "\nParty does not exist or queue empty\n";
            
        }

        //different options for viewing waitlist
        if(selection == 4){

            choice = 0;

            while(choice != 5){
                cout << "\nWhat would you like to do?\n";
                cout << "----------------------------\n";
                cout << "1: Check position in list?\n";
                cout << "2: Next in line?\n";
                cout << "3: Number of people in line\n";
                cout << "4: View waitlist?\n";
                cout << "5: Done?\n";
                cout << "Enter here: ";
                cin >> choice; cin.ignore(100, '\n');
            
                if(choice == 1){
                    cout << "\nWhat is the name of the party: ";
                    cin.get(waiting.groupName, 100); cin.ignore(100, '\n');

                    cout << "\nYour Party is currently number " << waitlist.dsply(choice, waiting) <<
                    " in line for a table\n";
                }
                if(choice == 2){
                    if(waitlist.peek() == true)
                        cout << "\nSuccess\n";
                    else
                        cout << "\nQueue empty\n";
                }
                if(choice == 3){
                    int size = waitlist.dsply(choice, waiting);
                    if(size > 0)
                        cout << "\nThere are currently " << size << " party/s waiting for a table!\n";
                    else
                        cout << "\nQueue is empty\n";
                }
                if(choice == 4){
                   
                    cout << "\nHere is the waiting list for a table!\n";
                    cout << "---------------------------------------\n";
                    waitlist.dsply(choice, waiting);
                }
            }
            choice = 0;


        }

        //seats the first party in queue
        if(selection == 5){
            cout << "\nThe first party in line will be removed from the queue!\n";
            if(waitlist.dequeue() == true)
                cout << "\nFirst party succesfully removed\n";
            else
                cout << "\nQueue empty\n"; 
        }

        //adds contact info to promotions stack
        if(selection == 6){
            cout << "\nPlease enter first and last name (e.g. John Smith): ";
            cin.get(contact.name, 100); cin.ignore(100, '\n');    
            cout << "\nPlease enter email address (e.g. test@ex.com): ";
            cin.get(contact.email, 100); cin.ignore(100, '\n');    

            if(promotions.push(contact) == true)
                cout <<"\n contact suffesfully added\n";
        }

        //different options for viewing contact stack
        if(selection == 7){
            choice = 0;

            cout << "\nWhat would you like to do?\n";
            cout << "1: Display contact list?\n";
            cout << "2: Check most recent?\n";
            cout << "3: Number of contacts?\n";
            cout << "enter here: ";
            cin >> choice; cin.ignore(100, '\n');
            if(choice == 1)
                promotions.display();    
            if(choice == 2){
                cout << "\nHere is the most recent contact\n";
                if(promotions.peek(choice) == true)
                    cout << "\nSuccess\n";
                else
                    cout << "\nStack is empty\n";
            }
            if(choice == 3){
                int num_people = promotions.peek(choice);
                if(num_people > 0){
                    cout << "There are " << num_people << " person/people in the contact list\n";
                    cout << endl;
                }
                else
                    cout << "\nStack is empty\n";
            }
            choice = 0;
        }

        //contacts most recent person in stack
        if(selection == 8){
            cout << "\nHere is the most recent person to contact!\n";
            if(promotions.pop(choice, contact) == true)
                cout << "\nContact succesffuly removed\n";
            else
                cout << "\nStack is empty\n";
        }
    }while(selection != 9);

    cout << "\nGoodbye!\n";

    waitlist.saveFile();

    return 0;
}

