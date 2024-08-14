/***********************************************************************
* Program:
*    Checkpoint 01a, review
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   cout << "Hello CS 165 World!" << endl;

   char name[256];
   cout << "Please enter your first name: ";
   cin >> name;

   int age;
   cout << "Please enter your age: ";
   cin >> age;

   cout << endl;
   cout << "Hello " << name << ", you are " << age << " years old.\n";
   return 0;
}
