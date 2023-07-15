#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "library.h"


int main() {
  //please type input.dat to start the program.
 const unsigned CAP = 30;
 Stats players[CAP]; 
 unsigned num_of_players = 0; 
 Stats s;
 string answer; 
 ifstream input;
 string file_name; 
 do{
  
   cout << "Enter a file which you would like to process (enter 'input.dat'):"; 
   cin >> file_name; 
}while(file_name!= "input.dat");
  ifstream fin; 
  fin.open(file_name);
  getline(fin, s.url);
  fin.ignore();
  cout << "This Program Takes the average stats for NBA Veterans according to " << s.url << endl;
  
 collect_all(players,num_of_players);
 display_all(players, num_of_players);
 cout << endl; 
 char sort_input; 
 char user_input; 

  do{
   cout << setw(55) << " ";
   cout << "would you like to..." << endl; 
   cout << setw(55)<< " ";
   cout << "[1] Sort"<< endl;
   cout << setw(55)<< " ";
   cout << "[2] Remove a Player" << endl;
   cout << setw(55)<< " ";
   cout << "[3] Display Players" << endl;
   cout << setw(55)<< " ";
   cout << "[4] Display Chart" << endl;
   cout << setw(55)<< " ";
   cout << "[5] End Program" << endl;
   cout << setw(55)<< " ";
   cin >> user_input; 
   cin.ignore();
    if(user_input == '1'){
    system("clear");
    cout << setw(55) << " ";
    cout << "Which would you like to sort by?" << endl; 
    cout << setw(55)<< " ";
    cout << "[1] AVERAGES" << endl;
    cout << setw(55)<< " ";
    cout << "[2] Name"<< endl; 
    cout << setw(55)<< " ";
    cout << "[3] Highest" << endl;
    cout << setw(55)<< " ";
    cout << "[4] Jersey #" << endl;
    cout << setw(55)<< " ";
    cout << "[5] Team Name" << endl;
    cout << setw(55)<< " ";
    cin >> sort_input; 
    if(sort_input == '1'){
     system("clear");
      sort_by_avg(players,num_of_players);
      cout << "After sorting by the total season averages, the new chart would look like: " << endl; 
      cout << endl; 
      display_all(players, num_of_players);
      cout << endl;
    }
    if(sort_input == '2'){
      system("clear");
      sort_by_player(players,num_of_players);
      cout << "After sorting by the player name, the new chart would look like: " << endl; 
      cout << endl;
      display_all(players, num_of_players);
      cout << endl;
    }
    if(sort_input == '3'){
      system("clear");
      sort_by_highest(players,num_of_players);
      cout << "After sorting by the player highest, the new chart would look like: " << endl; 
      cout << endl;
      display_all(players, num_of_players);
      cout << endl;
    }
    if(sort_input == '4'){
      system("clear");
      sort_by_jersey(players,num_of_players);
      cout << "After sorting by the jersey number, the new chart would look like: " << endl; 
      cout << endl; 
      display_all(players, num_of_players);
      cout << endl;
    }
      if(sort_input == '5'){
      system("clear");
      sort_by_team(players,num_of_players);
      cout << "After sorting by the Team Name, the new chart would look like: " << endl; 
      cout << endl; 
      display_all(players, num_of_players);
      cout << endl;
    }
  }
    
    //remove function
  if(user_input == '2'){
    bool check1 ;
    string player_name;
    cout << "Which player would you like to remove:" << endl; 
    getline(cin, player_name); 
    check(players,num_of_players,player_name,check1);
    if(check1 == false){
    system("clear");
    remove_a_player(players,num_of_players,player_name);
    cout << "After Removing " << player_name << " The new chart would look like this:\t" << endl; 
      cout << endl;
    display_all(players, num_of_players);
    cout << endl; 
      }
    if(check1 == true){
      system("clear");
      cout << "Sorry this Name was not recognized within the database:(" << endl;
      cout << "Here is the list of players again...." << endl;
      cout << endl;
     display_all(players, num_of_players);
    }
  }
  //lookup single player function 
  if(user_input == '3'){
    bool check2;
    string singledis;
    int index;
    cout << "Which player would you like to look into?" << endl;
    getline(cin, singledis);
    check(players,num_of_players,singledis,check2);
    if(check2 == false){
    system("clear");
    cout << "Here are " << singledis << "'s Stats:" <<endl; 
    cout << endl;
    index = lookup_one(players, num_of_players, singledis);
    display_lookup_one(players[index]);
    cout << endl;
    cout << "If you would like, here is the chart of other players you could look at..." << endl;
      cout << endl; 
      display_all(players, num_of_players);
      cout << endl; 
      }
    if (check2 == true){
      system("clear");
      cout << "Sorry, It seems like this player is not in the database at the moment:(" << endl;
      cout << "Here is the chart with the current players inside the database" << endl;
      cout << endl;
        display_all(players, num_of_players);
    }
    }
    if(user_input == '4'){
      system("clear"); 
      cout << "Here is a display of the chart of players.";
      cout << endl; 
       display_all(players, num_of_players);
    }
  if(user_input == '5'){
    break;
  }
  }while(user_input != '5'); 
//end of do while loop. 
system("clear");
cout << "Thank you for using the program, the final chart is:" << endl; 
display_all(players, num_of_players);
  
  }