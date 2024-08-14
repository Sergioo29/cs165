/***************************************************************
 * File: product.cpp
 * Author: Sergio Henrique
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/***************************************************************
prompt
 ***************************************************************/
void Product :: prompt()
{
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter description: ";
    getline(cin, description);

    bool isBadWeight;
    do {
      isBadWeight = false;
      cout << "Enter weight: ";
      cin >> weight;
      if (cin.fail() || weight < 0) // No zero gravity
      {
        isBadWeight = true;
        cin.clear();
        cin.ignore(256, '\n');
      }
    } while (isBadWeight == true);

    bool isBadPrice;
    do {
      isBadPrice = false;
      cout << "Enter price: ";
      cin >> basePrice;
      if (cin.fail() || basePrice < 0)
      {
        isBadPrice = true;
        cin.clear();
        cin.ignore(256, '\n');
      }
    } while (isBadPrice == true);
}

/***************************************************************
getSalesTax
 ***************************************************************/
float Product :: getSalesTax() const
{
   return (basePrice * 0.06);
}

/***************************************************************
getShippingCost
 ***************************************************************/
float Product :: getShippingCost() const
{
   if (weight <= 5) // lbs
      return 2.00;
   else
   // add $0.10 per pound over 5 lbs
   {
      float tax;
      for (int overload = 6; overload <= weight; overload++)
         tax += 0.10;
      return (2.00 + tax);
    }
}

/***************************************************************
getTotalPrice
 ***************************************************************/
float Product :: getTotalPrice() const
{
   float total = basePrice + getSalesTax() + getShippingCost();
   return total;
}

/***************************************************************
displayAdvertising
 ***************************************************************/
void Product :: displayAdvertising() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << name << " - $" << basePrice << endl;
   cout << "(" << description << ")" << endl;
}

/***************************************************************
displayAdvertising
 ***************************************************************/
void Product :: displayInventory() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "$" << basePrice << " - " << name << " - ";
   cout.precision(1);
   cout << weight << " lbs\n";
}

/***************************************************************
displayReceipt
 ***************************************************************/
void Product :: displayReceipt() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << name << endl;
   cout << "  Price:         $" << setw(8) << basePrice << endl;
   cout << "  Sales tax:     $" << setw(8) << getSalesTax() << endl;
   cout << "  Shipping cost: $" << setw(8) << getShippingCost() << endl;
   cout << "  Total:         $" << setw(8) << getTotalPrice() << endl;
}
