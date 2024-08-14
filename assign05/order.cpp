// File: order.cpp

#include "order.h"
#include "product.h"
#include "address.h"
#include "customer.h"
#include <iostream>
#include <string>
using namespace std;

// Put your the method bodies for your order class here
Order :: Order(Product product, int quantity, Customer customer)
{
   setProduct(product);
   setQuantity(quantity);
   setCustomer(customer);
}

string Order :: getShippingZip() const
{
   Address tempAddress = customer.getAddress();
   return tempAddress.getZip();
}

float Order :: getTotalPrice() const
{
   float totalForOne = product.getTotalPrice();
   float total = totalForOne * quantity;
   return total;
}

void Order :: displayInformation() const
{
   cout << customer.getName() << endl;
   cout << product.getName() << endl;
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "Total Price: $" << getTotalPrice() << endl;
}
