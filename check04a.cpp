/***********************************************************************
* Program:
*    Checkpoint 04a, Classes
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
   string title;
   string author;
 public:
   void prompt()
   {
     cout << "Title: ";
     getline(cin, this->title);
     cout << "Author: ";
     getline(cin, this->author);
   }
   void display()
   {
     cout << "\"" << title << "\" by " << author << endl;
   }
};

/*****************************************************************************/
int main()
{
   Book book;
   book.prompt();
   book.display();
   return 0;
}
