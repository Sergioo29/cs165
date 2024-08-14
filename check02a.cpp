/***********************************************************************
* Program:
*    Checkpoint 02a, Struct
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main()
{
    string first;
    cout << "Please enter your first name: ";
    cin >> first;

    string last;
    cout << "Please enter your last name: ";
    cin >> last;

    string id;
    cout << "Please enter your id number: ";
    cin >> id;
    cout << endl;

    cout << "Your information:\n";
    cout << id << " - " << first << " " << last;
    cout << endl;
   return 0;
}
