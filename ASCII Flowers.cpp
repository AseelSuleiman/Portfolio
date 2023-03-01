/**------------------------------------------
    Program 1: ASCII Flowers
    Prompt for the number of flower layers and display

    Course: CS 141, Fall 2023
    System: Linux_x86_64 and G++
    Author: Aseel Suleiman 
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // display the prompt to the user
    cout << "Program 1: ASCII Flowers\n"
         << "Choose from the following options:\n"
         << "   1. Display the HELLO graphic\n"
         << "   2. Display The Flower\n"
         << "   3. Exit the program\n"
         << "Your choice -> ";

    // read in the user's choice
    int menu_option;
    cin >> menu_option;

    // handle option to quit
    if (menu_option == 3) {
        exit(0);
    }

    // handle the HELLO graphic choice
    if (menu_option == 1) {
        char frame;
        cout << "Enter your frame character: ";
        cin >> frame;
        //top border
        cout << endl;
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << ' ' << endl;
        }
        //message
        cout << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << right;
        //bottom border
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << " " << endl;
        }
    }

    // handle the floral pattern TODO for students
    //this section creates the flower pattern based off the number of sections 
    if (menu_option == 2) {
        int sections;
        cout << "Enter number of sections: ";
        cin >> sections;
        cout << setw(sections + 3) << setfill(' ') << "---" << endl;
      
        for(int j = 0; j < sections; j++){
          int holder = 0;
          for(int k = 0; k < (2 * j) + 1; k++){
            cout << setw(sections - holder) << setfill(' ') << "{";

            if(k == j){
              cout << string(j + 1, ':');
              cout << "@";
              cout << string(j + 1, ':');
            }
            else{
              cout << string(holder + 2, ':');
              cout << ":";
              cout << string(holder, ':');
      
            }
              
              if(k < j){
                holder++;
              }
              else{
                holder--;
      
              }
          
          
            cout << "}";
            
            cout << endl;
          }
          
          
          cout << setw(sections + 3) << setfill(' ') << "---" << endl;
      
        
        }

        //this section creates the stem based off the number of sections 
        for(int i = 1; i <= sections; ++i){
          
          if ((i % 2) == 0){
            cout << setw(sections + 3) << setfill(' ') << "  \\| " << endl;
            cout << setw(sections + 3) << setfill(' ') << " | " << endl;
          }
          else{
            cout << setw(sections + 4) << setfill(' ') << "  |/ " << endl;
            cout << setw(sections + 3) << setfill(' ') << " | " << endl;
          }
        }
    return 0;
      }
    }  
    
