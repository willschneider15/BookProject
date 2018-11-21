#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Book{
  private:
    string title;
    int year;
    string author;
  public:
    //constructors
    Book();
    Book(string newTitle, int newYear, string newAuthor);
    Book(string allData);

    //setters
    void setTitle(string newTitle);
    void setYear(int newYear);
    void setAuthor(string newAuthor);

    //getters
    string getTitle();
    int getYear();
    string getAuthor();

    //helper functions
    bool matchTitle(string targetTitle);
    bool matchAuthor(string targetAuthor);
    bool matchYear(string targetYear);
    bool match(string target);
    void outputBook();
};
