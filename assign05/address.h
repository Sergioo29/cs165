// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

// Put your Address class here
class Address
{
private:
   std::string street;
   std::string city;
   std::string state;
   std::string zip;

public:
   Address();
   Address(std::string street, std::string city, std::string state, std::string zip);
   std::string getStreet() const { return street; }
   std::string getCity() const { return city; }
   std::string getState() const { return state; }
   std::string getZip() const { return zip; }
   void setStreet(std::string street) { this->street = street; }
   void setCity(std::string city) { this->city = city; }
   void setState(std::string state) { this->state = state; }
   void setZip(std::string zip) { this->zip = zip; }
   void display() const;
};




#endif
