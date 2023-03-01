
/**------------------------------------------
    Program 3: Typing Tutor

    Course: CS 141, Spring 2023.
    Author: Aseel Suleiman 
 ---------------------------------------------**/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
#include <iomanip>
using namespace std;

const int NMISP = 5;
const int RNG_RANGE = 100;

void
display_header(const int ndict, const int nmiss)
{
  
  cout << "*** Typing Tutor" << endl;
  cout << "There are " << ndict << " words in the dictionary." << endl;
  cout << "There are " << nmiss << " commonly misspelled words." << endl;
}

void
display_menu_options()
{

    cout << endl << "*** Select a menu option:" << endl
         << "1. Spell commonly misspelled words" << endl
         << "2. Type random words from the full dictionary" << endl
         << "3. Display some words from one of the lists" << endl
         << "4. Use binary search to lookup a word in the dictionary" << endl
         << "5. Exit the program." << endl
         << "Your choice: ";
}


vector<int>
randn(const int n, const int max)
{
  vector<int> spellMiss;
  for(int i = 0; i < n; i++){
    spellMiss.push_back(rand() % (max +1));
  }
  //spellMiss has n random numbers from 0 to max
    return spellMiss;
}


ifstream
open(const string& src_file)
{
    ifstream src{src_file};
    if (!src.is_open()) {
        cout << "Could not find file " << src_file << "." << endl;
        exit(1);
    }
    return src;
}

void
extract_dict(vector<string>& dst, const string& src_file)
{
  ifstream file = open(src_file);
  string temp;
  while (file >> temp){
    dst.push_back(temp);
    }
  //stores each line of the file is dst vector
  
}

void
extract_misspelled(vector<string>& misspelled, vector<string>& correct,
                    const string& src_file)
{
  ifstream infile(src_file);
    string misspelled_word, correct_word;

    while (infile >> misspelled_word >> correct_word) {
        misspelled.push_back(misspelled_word);
        correct.push_back(correct_word);
    }
  //first word from line stored in misspelled vector, second word from line stored in correct vector
}

void
display_elems(const vector<string>& src, const vector<int>& positions)
{
  
  vector<string> misspelled;
  for(int i = 0; i < positions.size(); i++){
    int position = positions.at(i);
  if (position >= 0 && position < src.size()){
    cout << src.at(position);
    if (i < positions.size()-1){
      cout << " ";
    }
  }
    }
  //displays 5 random words from file 
  }


void
extract_spelling_answers(vector<string>& dst, const vector<string>& correct,
                            const vector<int> positions)
{
  int num_words = dst.size();
  vector<string> mistakes;
  for (int i = 0; i < dst.size(); i++){
    mistakes.push_back(dst.at(i));
  }
  for (int i = 0; i < positions.size(); i++){
    dst.push_back(correct.at(positions.at(i)));
  }
   //extracts the corresponding correct answers at given indices 
}

void
extract_spelling_mistakes(vector<string>& dst, const string& to_grade,
                const vector<string>& correct)
{

  string word;
  vector<string> user_words;


    for (char x : to_grade) {
        if (isspace(x)) {
            if (!word.empty()) { // adds the previous word to user_words
                user_words.push_back(word);
                word.clear(); //resets for next word
            }
        }
        else { // add the character to the current word
            word.push_back(x);
        }
    }


    if (!word.empty()) {
        user_words.push_back(word);
    }

  for (int i = 0; i < user_words.size() && i < correct.size(); i++){
    if (user_words.at(i) != correct.at(i)){
      string error = user_words.at(i) + " -> " + correct.at(i);
      dst.push_back(error);
    }
  }
}

void
report_misspell_mistakes(const vector<string>& mistakes,
                            const int num_words)
{
  int numIncorrect = mistakes.size();
  int numCorrect = NMISP - numIncorrect;
  int score = (numCorrect * 3) - (numIncorrect * 6);

  if (numIncorrect == 0){
    cout << "No misspelled words!" << endl << numCorrect * 3 << " points: " << numCorrect << " spelled correctly x 3 points for each." << endl << "0 point penalty: 0 spelled incorrectly x -6 points for each. " << endl << "Score: " << score << endl;
  }
  else{
    cout << "Misspelled words:" << endl;
    for (int i = 0; i < mistakes.size(); i++){
      cout  << "    " << mistakes.at(i) << endl;
    }
    cout << numCorrect * 3 << " points: " << numCorrect << " spelled correctly x 3 points for each." << endl << numIncorrect *  6 << " point penalty: " << numIncorrect << " spelled incorrectly x -6 points for each." << endl << "Score: " << score << endl;
  }
  //reports scores/mistakes 
}

void
evaluate_user_misspells(const vector<string>& src, const vector<int>& positions)
{
  string input;
  getline(cin, input);
  vector<string>correct;
  vector<string>mistakes;
  extract_spelling_answers(correct, src, positions);
  extract_spelling_mistakes(mistakes, input, correct);
  report_misspell_mistakes(mistakes, correct.size());
  //reads in users input and reports performance 
}

void
misspelled(const vector<string>& mspelled, const vector<string>& correct)
{
  cout <<  endl << "*** Using commonly misspelled words." << endl;
  vector<int> spellMiss = randn(NMISP, mspelled.size()-1);
  ifstream Nfile;
  Nfile.open("misspelled_words.txt");
  vector<int> positions;
    for(int i = 0; i < spellMiss.size(); i++){
      positions.push_back(spellMiss.at(i));
    }
  Nfile.close();
  vector<string> misspelled;
  display_elems(mspelled, positions);
  cout << endl;
  cout << "Type the words above with the correct spelling:" << endl;
  vector<string> dst;
  evaluate_user_misspells(correct, positions);
  //drives procedure for menu option 1 
}

void
full_dict(const vector<string>& dict)
{
  cout <<  endl << "*** Using full dictionary." << endl;
  vector<int> spellMiss = randn(NMISP, dict.size()-1);
  ifstream Nfile;
  Nfile.open("dictionary.txt");
  vector<int> positions;
    for(int i = 0; i < spellMiss.size(); i++){
      positions.push_back(spellMiss.at(i));
    }
  Nfile.close();
  display_elems(dict, positions);
  cout << endl;
  cout << "Correctly type the words above:" << endl;
  vector<string> dst;
  evaluate_user_misspells(dict, positions);
  //drives procedure for option 2
}

void
display_words_prompt()
{
    // This displays the data set choices for menu option 3
    cout << endl << "*** Displaying word list entries." << endl
         << "Which words do you want to display?" << endl
         << "A. Dictionary of all words" << endl
         << "B. Commonly misspelled words (wrongly spelled)" << endl
         << "C. Commonly misspelled words (correctly spelled)" << endl
         << "Your choice: ";
}

void
print_range(const vector<string>& data)
{
  int num1;
  int num2;
  cin >> num1 >> num2;
  if ((num1 > num2) || (num1 > data.size()) || (num2 > data.size())){
    cout << "The end index must come after the start, and the indices must be in range." << endl;
  }
  for (int i = num1; i <= num2; i++ ){
    cout << i << ". " << data.at(i) << endl;
  }
  //takes in range from the user 
}

void
display_in_range(const vector<string>& dict, const vector<string>& mspelled,
                const vector<string>& correct)
{
  display_words_prompt();
  unsigned char choice;
  cin >> choice;
  switch (choice){
    case 'a':
    case 'A':
      cout << "*** Enter the start and end indices between 0 and 263532: ";
      print_range(dict);
    break;
    case 'b':
    case 'B':
      cout << "*** Enter the start and end indices between 0 and 113: ";
      print_range(mspelled);
    break;
    case 'c':
    case 'C':
      cout << "*** Enter the start and end indices between 0 and 113: ";
      print_range(correct);
    break;
  }
  //reads in users option using print_range()

}

void
bsearch(const vector<string>& data)
{
  int start = 0;
  int mid;
  int num = 1;
  string elem;
  string searchWord;
  bool wordFound = false;
  cout << "*** Enter word to search: ";
  cin >> searchWord;
  int size = data.size();
  do{
    mid = (start + size) / 2;
    elem = data.at(mid);
    cout << setw(5);
      cout << num << ". Comparing to: " << elem << endl;
    if(elem < searchWord)
      start = mid + 1;
    else if (elem > searchWord)
      size = mid;
    else{
      cout << searchWord << " was found." << endl;
      wordFound = true;
      break;
      }
    num +=1;
  } while (start < size);
  if (!wordFound){
    cout << searchWord << " was NOT found." << endl;
    }
  //runs binary search algorith with search word from user

}

void
extract_all_data(vector<string>& dict, vector<string>& mspelled,
                    vector<string>& correct)
{
    extract_dict(dict, "dictionary.txt");
    extract_misspelled(mspelled, correct, "misspelled_words.txt");
}

int
main()
{
    srand(1);
    vector<string> dict, mspelled, correct;
    extract_all_data(dict, mspelled, correct);
    display_header(dict.size(), correct.size());
    unsigned int choice;
    do {
        display_menu_options();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            misspelled(mspelled, correct);
            break;
        case 2:
            full_dict(dict);
            break;
        case 3:
            display_in_range(dict, mspelled, correct);
            break;
        case 4:
            bsearch(dict);
            break;
        case 5:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "No menu option " << choice << ". "
                 << "Please try again." << endl;
        }
    } while ((choice != 5) && !cin.eof());

    return 0;
}
