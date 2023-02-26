/**------------------------------------------
    Program 2: Great 13

    Course: CS 141, Fall 2022.
    System: Linux x86_64 and G++
    Author: Aseel Suleiman 
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <cstdlib>
#include <map>
#include <string>


using namespace std;

// Function that displays the instructions to the user

void display_instructions()
{
    cout << "Class: CS 141" << endl
         << "Program 2: Great 13" << endl << endl
         << "Make a series of jumps until there is a single piece left" << endl
         << "anywhere on board. On each move you must jump an adjacent" << endl
         << "piece   into   an  empty  square,  jumping  horizontally," << endl
         << "vertically, or diagonally." << endl << endl
         << "Input of 'R' resets the board back to the beginning, and " << endl
         << "'X' exits the game." << endl;
}


char board[13]{};



char get_element(char position)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to get element at position " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    return board[position - 'A'];
}

void set_element(char position, char value)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to set element at postion " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    board[position - 'A'] = value;
}


void display_board()
{
    cout << endl;
    cout << setw(7) << "Board" << setw(12) << "Position" << endl;
    cout << setw(5) << board[0] << setw(11) << 'A' << endl
         << setw(3) << board[1] << ' ' << board[2] << ' ' << board[3]
         << setw(11) << "B C D" << endl
         << board[4] << ' ' << board[5] << ' ' << board[6] << ' '
         << board[7] << ' ' << board[8] << ' '
         << " E F G H I" << endl
         << setw(3) << board[9] << ' ' << board[10] << ' ' << board[11]
         << setw(11) << "J K L" << endl
         << setw(5) << board[12] << setw(11) << 'M' << endl;
    cout << endl;
}

void make_move();
void initialize_board();
bool game_over();


int main()
{
    display_instructions();
    initialize_board();
    do {
      display_board();
      make_move();
    }
      while (!game_over() && !cin.eof());

    return 0;
}

void make_move()
{
    string position;
  //array of all valid moves 
    string validMoves[32] = {"ABE", "EBA", "ADI", "IDA","EJM", "MJE",       "ILM","MLI", "ACG", "GCA", "CGK", "KGC", "MKG", "GKM", "BCD", "DCB",       "EFG","GFE", "FGH", "HGF", "GHI", "IHG", "JKL",              "LKJ", "BFJ", "JFB", "DHL", "LHD", "BGL", "LGB", "DGJ",                  "JGD"};
    cout << "Enter positions from, jump, and to (e.g. EFG): ";
    cin >> position;
    transform(position.begin(), position.end(), position.begin(), ::toupper);
    bool valid;
    valid = false;
    for(int i = 0; i < 32; i++){
        if (position == validMoves[i]){
          valid = true;
          break;
        }
        
    }
  //checks all invalid moves/errors
    if (position == "R" || position == "r"){
      cout << "Restarting game." << endl;
      initialize_board();
      return;
    }
    else if (position == "X" || position == "x"){
      cout << "Exiting." << endl;
      exit(0);
      }
    else if (position.size() != 3 && position != "X" && position != "R"){
      cout << "*** Invalid sequence. Please retry." << endl;
      return;
    }
    else if ((position.at(0) < 'A') || (position.at(0) > 'M') ||(position.at(1) < 'A') || (position.at(1) > 'M') || (position.at(2) < 'A') || (position.at(2) > 'M')){
      cout << "*** Given move has positions not on the board! Please retry." << endl;
      return;
    }
    else if (get_element(position.at(1)) != '#' ){
      cout << "*** Must jump a piece. Please retry." << endl;
      return;
    }
    else if (get_element(position.at(0)) != '#' ){
      cout << "*** Source needs a piece. Please retry." << endl;
      return;
    }
    else if (get_element(position.at(2)) != '.' ){
      cout << "*** Destination must be empty. Please retry." << endl;
      return;
    }
    else if(valid == false){
      cout << "*** Move is invalid. Please retry." << endl;
      return;
    }

    else{
      char x = get_element(position.at(0));
      char y = get_element(position.at(1));
      char z = get_element(position.at(2));
      
      for (int i = 0; i < 32; i++){
        if (position == validMoves[i]){
          
            set_element(position.at(0), '.');
            set_element(position.at(1), '.');
            set_element(position.at(2), '#');
            
        }
      }
      }
}
//checks for pegs == 1, gameover when true 
bool game_over()
{
    int pegs;
    pegs = 13;
    for (int i = 0; i < 13; i++){
      if (get_element(i+'A') == '.'){
        pegs --;
      }
    } 
    if (pegs == 1){
      cout << "Congrats you win!" << endl;
      return true;
    }
    return false;
       
}

void initialize_board()
{
    for (char i = 'A'; i <= 'M'; ++i){
      if (i != 'G'){
        set_element(i, '#');
      }
      else{
        set_element(i, '.');
      }
      
    }
}