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

// Method bodies
Product :: Product()
{
   name = "none";
   description = "";
   weight = 0;
   basePrice = 0;
}


Product :: Product(string name, string description, float basePrice, float weight)
{
  setName(name);
  setDescription(description);
  setBasePrice(basePrice);
  setWeight(weight);
}


float Product :: getSalesTax() const
{
   return (basePrice * 0.06);
}


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


float Product :: getTotalPrice() const
{
   float total = basePrice + getSalesTax() + getShippingCost();
   return total;
}


void Product :: displayAdvertising() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << name << " - $" << basePrice << endl;
   cout << "(" << description << ")" << endl;
}


void Product :: displayInventory() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "$" << basePrice << " - " << name << " - ";
   cout.precision(1);
   cout << weight << " lbs\n";
}


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
