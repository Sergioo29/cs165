// File: customer.cpp

#include "customer.h"
#include "address.h"
#include <string>
#include <iostream>
using namespace std;

// Put the method bodies for your customer class here
Customer :: Customer(string name, Address address)
{
   setName(name);
   setAddress(address);
}

void Customer :: display() const
{
   cout << name << endl;
   address.display();
}
