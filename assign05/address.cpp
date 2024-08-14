// File: address.cpp

#include "address.h"
#include <iostream>
#include <string>
using namespace std;

// Put your method bodies for the address class here
Address :: Address()
{
   street = "unknown";
   zip = "00000";
   city = "";
   state = "";
}

Address :: Address(string street, string city, string state, string zip)
{
   setStreet(street);
   setCity(city);
   setState(state);
   setZip(zip);
}

void Address :: display() const
{
   cout << street << endl;
   cout << city << ", " << state << " " << zip << endl;
}
