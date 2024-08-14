/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const
{
   cout << "$" << dollars << ".";
   cout << setfill('0') << setw(2) << cents;
}

bool operator==(const Money & lhs, const Money & rhs)
{
  return lhs.getDollars() == rhs.getDollars() && lhs.getCents() == rhs.getCents();
}

bool operator!=(const Money & lhs, const Money & rhs)
{
  return lhs.getDollars() != rhs.getDollars() || lhs.getCents() != rhs.getCents();
}

std::ostream& operator<<(std::ostream& out, const Money & money)
{
  out << "$" << money.getDollars() << ".";
  out << setfill('0') << setw(2) << money.getCents();
  return out;
}
