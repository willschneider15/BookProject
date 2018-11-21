
#include "book.h"

//constructors
Book::Book(){ //defualt constructor
  title = "***";
  year = 0;
  author = "***";
}
Book::Book(string newTitle, int newYear, string newAuthor){
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
     //go thru adding to the default variables charater by charater
     // switching when the character = '|'
     // ending when = '\n'
  int switcher = 0;
  string yearHold;
  for(int i = 0; i < allData.size(); i++){
    if(allData[i] == '|'){
      switcher += 1;
    }
    else if(allData[i] == '\n'){
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
  year = std::stoi(yearHold); //using string to int
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
void Book::outputBook(){
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Author: " << author << endl;
}
