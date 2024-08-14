/*********************
 * phone.cpp
 *********************/
#include "phone.h"
#include <iostream>
using namespace std;

// TODO: Put your phone class methods here...
void Phone :: promptNumber()
{
  cout << "Area Code: ";
  cin >> areaCode;
  cin.ignore();
  cout << "Prefix: ";
  cin >> prefix;
  cin.ignore();
  cout << "Suffix: ";
  cin >> suffix;
  cin.ignore();
}

void Phone :: display()
{
  cout << "(" << areaCode << ")" << prefix << "-" << suffix << endl;
}
