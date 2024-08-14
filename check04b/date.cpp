/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include "date.h"
#include <iostream>
using namespace std;

// Put your method bodies here...
void Date :: set(int month, int day, int year)
{
  this->month = month;
  this->day = day;
  this->year = year;
}
void Date :: displayAmerican()
{
  cout << month << "/" << day << "/" << year << endl;
}
void Date :: displayEuropean()
{
  cout << day << "/" << month << "/" << year << endl;
}
void Date :: displayISO()
{
  cout << year << "-" << month << "-" << day << endl;
}
