/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions
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
   try
   {
      if (number < 0)
         throw string("The number cannot be negative.\n");
      if (number >= 100)
         throw string("The number cannot be greater than 100.\n");
      if ((number % 2) != 0)
         throw string("The number cannot be odd.\n");
  }
  catch (string message)
  {
     cout << "Error: " << message;
     return -1;
  }
   cout << "The number is " << number << ".\n";
   return number;
}

int main()
{
   int number = prompt();
   return 0;
}
