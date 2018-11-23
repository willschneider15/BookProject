//* * * * * * * * * * * * * * * * * * * * * * * * * *
//
// program: book_main
//
// Name : William Schneider
// Email : ws828417@ohio.edu
//
// Description: The purpose is to test all of the functions within the book class.
//
// Date : Nov/22/2018
//
// * * * * * * * * * * * * * * * * * * * * * * * * * *

#include "book.h"
using namespace std;

void doChoice(int choice, Book &book); //used to clean the main function

int main(){
  Book book("The Hitchhiker's Guide to the Galaxy|1979|Douglas Adams");
  int choice;
  do{
    cout << endl; //displaying the menu options
    cout << "1. match title" << endl;
    cout << "2. match year" << endl;
    cout << "3. match name" << endl;
    cout << "4. match" << endl;
    cout << "5. change book(CANT USE SPACES WILL CAUSE ERROR)" << endl;
    cout << "6. output book" << endl;
    cout << "0. end program" << endl;
    cout << endl;
    cin >> choice;

    doChoice(choice, book);//when they have selected an option it calls it
                            //passing a refrenced book, so it can be changed with setter
  }while(choice != 0);
  return 0;
}

void doChoice(int choice, Book &book){
  string userInput, switchTitle, switchAuthor;
  int intPut;

  if(choice == 1){ //for all of the match functions just test if its true or false, with user input
    cout << "What is your input? " << endl;
    cin >> userInput;
    if(book.matchTitle(userInput)){
      cout << "Thats part of the title" << endl; //I than print the result of the function call
    }
    else{
      cout << "Thats not part of the title" << endl;
    }
  }
  else if(choice == 2){
    cout << "What is your input? " << endl;
    cin >> userInput;
    if(book.matchYear(userInput)){
      cout << "Thats part of the year" << endl;
    }
    else{
      cout << "Thats not part of the year" << endl;
    }
  }
  else if(choice == 3){
    cout << "What is your input? " << endl;
    cin >> userInput;
    if(book.matchAuthor(userInput)){
      cout << "Thats part of the author" << endl;
    }
    else{
      cout << "Thats not part of the author" << endl;
    }
  }
  else if(choice == 4){
    cout << "What is your input? " << endl;
    cin >> userInput;
    if(book.match(userInput)){
      cout << "Thats part of the book" << endl;
    }
    else{
      cout << "Thats not part of the book" << endl;
    }
  }
  else if(choice == 5){ //I wanted to test the set functions
    cout << "Title ?" << endl;  //although I run into an infinite loop if you add a space in the string
    cin >> switchTitle;         //I tried to figure out this problem, but still dont quite understand
    book.setTitle(switchTitle); //cin.clear() did not work

    cout << "Year ?" << endl; //I think its because there are multiple cin's
    cin >> intPut;            //causing an error flag but im not sure
    book.setYear(intPut);

    cout << "Author ?" << endl;
    cin >> switchAuthor;
    book.setAuthor(switchAuthor);
  }
  else if(choice == 6){
    book.outputBook(); //outputs all of the member variables
  }
  else if(choice == 0){
    exit (0); //ending the program
  }
  else{
    cout << "Not proper input" << endl; //didnt input a proper choice
  }
}
