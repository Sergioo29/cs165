/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   // prompt for month, day, year
   cout << "Month: ";
   int month;
   cin >> month;
   cout << "Day: ";
   int day;
   cin >> day;
   cout << "Year: ";
   int year;
   cin >> year;

   // create a Date object
   Date date;

   // set its values
   cout << endl;
   date.set(month, day, year);

   // call each display function
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
