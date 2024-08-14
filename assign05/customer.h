// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "address.h"
#include <string>

// put your Customer class here
class Customer
{
private:
   std::string name;
   Address address;

public:
   Customer() { name = "unspecified"; }
   Customer(std::string name, Address address);
   std::string getName() const { return name; }
   Address getAddress() const { return address; }
   void setName(std::string name) {this->name = name; }
   void setAddress(Address address) {this->address = address; }
   void display() const;

};

#endif
