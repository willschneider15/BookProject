//william schneider

#include "book.h"

using namespace std;

int main(){
  Book book;
  Book book2("wills book", 2018, "will schneider");
  Book book3("willsshiz|15|tarted");

  cout << "Defualt Book " << endl;
  book.outputBook();
  cout << "New Book " << "\n";
  book2.outputBook();
  cout << endl;
  cout << "token test:" << endl;
  book3.outputBook();
}
