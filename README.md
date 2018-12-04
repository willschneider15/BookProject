## BookProject
Objective: To have a setup library of books that the user can search for, sort by different details, and add/delete books.

# How:
  1. A Header File That Sets Up The Book Class
  2. A Class File That Holds All Of The Functions Of Book
  3. A Library File That Reads In All The Book Data, And Allows User To Sort Thru It
  4. Includes a make file to create all of the object files needed in the project
  
# Needs:
 A file that holds books in the format "title|year|author", hardcode the name of the file into library
  -Reccomend: Not using file over 15,000 books for efficency purposes 
  
# Options:
-a Search by author
-t Search by title
-y Search by year
-n Add new book to the library the book must be saved to the file.
-d Delete a book by title
-sa Display all books sorted by author
-st Display all books sorted by title
-sy Display all books sorted by year
No option search for any string in the title, year, or author.

# Examples:
./lib -a "aDaMs "
./lib -t "GALaXy "
./lib -y " 19"
./lib -n " Problem Solving with C++|2018|Walter Savitch "
./lib -d " Problem Solving with C++ "
./lib -sa
./lib -sy
./lib "C++"
