/***********************************************************************
* Program:
*    Checkpoint 04b, More Classes
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
using namespace std;

class Date
{
private:
   int month;
   int day;
   int year;
 public:
   void set(int month, int day, int year)
   {
     this->month = month;
     this->day = day;
     this->year = year;
   }
   void displayAmerican()
   {
     cout << month << "/" << day << "/" << year << endl;
   }
   void displayEuropean()
   {
     cout << day << "/" << month << "/" << year << endl;
   }
   void displayISO()
   {
     cout << year << "/" << month << "/" << day << endl;
   }
};

/*****************************************************************************/
int main()
{
   Date date;

   cout << "Month: ";
   int month;
   cin >> month;
   cout << "Day: ";
   int day;
   cin >> day;
   cout << "Year: ";
   int year;
   cin >> year;

   cout << endl;

   date.set(month, day, year);
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
