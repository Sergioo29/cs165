/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Put your SmartPhone methods here
void SmartPhone :: prompt()
{
  promptNumber();
  cout << "Email: ";
  getline (cin , email);
}

void SmartPhone :: display()
{
  Phone::display();
  cout << email << endl;
}
