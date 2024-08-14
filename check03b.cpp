/***********************************************************************
* Program:
*    Checkpoint 03b, Exceptions
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/
#include <iostream>
#include <string>
using namespace std;

int prompt()
{
   int number;
   cout << "Enter a number: ";
   cin >> number;

   while(cin.fail())
   {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Invalid input.\n";
      cout << "Enter a number: ";
      cin >> number;
   }

   return number;
}

int main()
{
   int number = prompt();
   cout << "The number is " << number << ".\n";
   return 0;
}
