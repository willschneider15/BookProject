//* * * * * * * * * * * * * * * * * * * * * * * * * *
//
// program: book
//
// Name : William Schneider
// Email : ws828417@ohio.edu
//
// Description: This holds all of the class functions of the book class, and functions
//              to aid the use of the functions.
//
// Date : Nov/22/2018
//
// * * * * * * * * * * * * * * * * * * * * * * * * * *

#include "book.h"
using namespace std;//cout and cin

string upperCase(string x); //used when comparing strings cleans up code

//constructors
Book::Book(){ //defualt constructor
  title = "***";
  year = 0;
  author = "***";
}

Book::Book(string newTitle, int newYear, string newAuthor){ //secondary constructor
  if(newYear > 0){
    year = newYear;
  }
  else{
    year = 0;
  }
  title = newTitle;
  author = newAuthor;
}

Book::Book(string allData){
     //needs to be able to tokenize the string
     //going thru the string adding to the default variables charater by charater
     // switching when the character = '|'
     // ending when = '\n'
  int switcher = 0; //used to switch between the member variables
  string yearHold;
  for(int i = 0; i < allData.size(); i++){ //going thru the string char by char
    if(allData[i] == '|'){
      switcher += 1; //switching between them when equals '|'
    }
    else if(allData[i] == '\n'){ //making sure it ends when its a new line
      break;
    }
    else if(switcher == 0){
      title += allData[i];
    }
    else if(switcher == 1){
      yearHold += allData[i]; //creating a string so I hold onto place values
    }
    else{
      author += allData[i];
    }
  }
  year = std::stoi(yearHold); //using string to int to set it to the member varibale
}

//setters
void Book::setTitle(string newTitle){
  title = newTitle;
}
void Book::setYear(int newYear){
  year = newYear;
}
void Book::setAuthor(string newAuthor){
  author = newAuthor;
}

//getters
string Book::getTitle(){
  return title;
}
int Book::getYear(){
  return year;
}
string Book::getAuthor(){
  return author;
}

//helper functions
bool Book::matchTitle(string targetTitle){
  string targetTitleU = upperCase(targetTitle); //comparing when they are upper case
  string titleU = upperCase(title);

  for(int i = 0; i <= title.size()-targetTitle.size(); i++){ //subtracting so we dont try to go outside of the string
    if(titleU.substr(i, targetTitle.size()) == targetTitleU){ //going thru trying to find the same string within another string
      return true;  //if the there is a string within it that equals the target returns true
    }
  }
  return false; //there is nothing that equals the target
}

bool Book::matchAuthor(string targetAuthor){
  string targetAuthorU = upperCase(targetAuthor); //comparing when they are uppercase
  string authorU = upperCase(author);

  for(int i = 0; i <= author.size()-targetAuthor.size(); i++){ //using the exact same logic stated in matchtitle
    if(authorU.substr(i, targetAuthor.size()) == targetAuthorU){
      return true;
    }
  }
  return false;
}

bool Book::matchYear(string targetYear){
  string yearS = std::to_string(year); //must be string to compare
                                      //dosent need to be uppercase cause they are numbers
  for(int i = 0; i <= yearS.size()-targetYear.size(); i++){ //same logic stated in matchtitle
    if(yearS.substr(i, targetYear.size()) == targetYear){
      return true;
    }
  }
  return false;
}

bool Book::match(string target){ //checking if its any of the individual match functions
  if(matchAuthor(target) || matchTitle(target) || matchYear(target)){
    return true;//if its found anywhere returns true
  }
  return false;
}

void Book::outputBook(){ //printing the book
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Author: " << author << endl;
}

//cleaner code function
string upperCase(string x){
  string y;
  for(int i = 0; i < x.size(); i++){ //going thru character by charater making it uppercase
    y += char(toupper(x[i])); //adding it to a new string
  }
  return y; //returning the result of the uppercase string
}
