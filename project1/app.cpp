/*
Devin Smith *** Project 1 *** CS260 *** Professor Liang
this is the client for prject one. This is where all the data structures will be tested
*/

#include "list.h"
//#include "songs.h"
using namespace std;


int main(){
 
    user input;
    int select = 0;
    songs to_add;
    list insert;
    
    //loads song info from external text file
    if(insert.loadfile(input, insert) == true)
        cout << "\nSongs succesfully read in!\n";
    else
        cout << "\nfile failed tp open!\n";

    //menu loop for testing list
    do{
        cout << "\n1: Add a song" << endl;
        cout << "2: Append song likes" << endl;
        cout << "3: Display all songs" << endl;
        cout << "4: Search for artists" << endl;
        cout << "5: Remove Songs" << endl;
        cout << "6: Quit" << endl;

        cout << "Enter selection (e.g : 2) ->: ";
        cin >> select; cin.ignore(100, '\n');

        //reads in song info for the client
        if(select == 1 ){
            cout << "\nEnter name of Artist (e.g. Pink Floyd): "; 
            cin.get(input.artist, 100); cin.ignore(100, '\n');
            
            cout << "\nEnter name of Song (e.g. Time): "; 
            cin.get(input.title, 100); cin.ignore(100, '\n');
            
            cout << "\nLength of Song (e.g. 3.45); "; 
            cin >> input.length; cin.ignore(100, '\n');
            
            cout << "\nNumber of Likes (e.g. 420000); "; 
            cin >> input.likes; cin.ignore(100, '\n');

            if(to_add.add_new(input, insert) == true)
                cout << "\nSong succesfully added to list\n";
            else
                cout << "\nSong failed to add or already exists!\n";
        }
        //appends the likes for a song
        if(select == 2){
            cout << "\nEnter name of song to append (e.g. Time): ";
            cin.get(input.title, 100); cin.ignore(100, '\n');

            cout << "\nWhat is the new number of like: ";
            cin >> input.likes; cin.ignore(100, '\n');
            cout << endl;

            cout << "\nHeres the updated song\n";
            cout << "------------------------\n";
            to_add.append(input, insert);

        }
        //displays all songs in  the list
        if(select == 3){

            //reads out message weather list was displayed or not
            if(insert.display(insert) == true)
                cout << "\nSongs succesfully displayed!\n";
            else
                cout << "\nFailed to display list\n";
        }
        //displays all songs by searched artist
        if(select == 4){
            
            cout << "\nEnter the name of the Artist (e.g. Queen): ";
            cin.get(input.artist, 100); cin.ignore(100, '\n');
            
            //reads out message weather artist was found or not
            if(insert.search(input) == true)
                cout << "\nArtist found!\n";
            else
                cout << "\nArtist not found!\n";
        }
        //deletes all songs under the number of likes entered by user
        if(select == 5){
            cout << "Enter minumum number of Likes (e.g. 250000): ";
            cin >> input.likes; cin.ignore(100, '\n');

            //reads out message weather songs were deleted
            if(insert.del(input) == true)
                cout << "\nSongs deleted succesfull\n";
            else
                cout << "\nFailed to delete song or list empty!\n";

        }
    }while(select >= 0 && select < 6);
    
    if(insert.savefile(input, insert) == true)
        cout << "\nSongs succesfully saved to file\n";
    else
        cout << "\nSongs were not saved to file\n";

    cout << "\nGoodbye\n";

    return 0;
}
