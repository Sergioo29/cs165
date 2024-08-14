/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
  vector <int> vecInt;
  int value;
  do
  {
       cout << "Enter int: ";
       cin >> value;
       vecInt.push_back(value);
  } while (value != 0);

  cout << "Your list is:\n";
  for (int i = 0; i < vecInt.size(); i++)
    if (vecInt[i] != 0)
       cout << vecInt[i] << endl;

cout << endl;
cin.ignore();

       vector <string> vecStr;
       string word;
       do
       {
            cout << "Enter string: ";
            cin >> word;
            vecStr.push_back(word);
       } while (word != "quit");

       cout << "Your list is:\n";
       for (int i = 0; i < vecStr.size(); i++)
         if (vecStr[i] != "quit")
            cout << vecStr[i] << endl;

   return 0;
}
