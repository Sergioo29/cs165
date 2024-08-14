/***************************************************************
 * File: product.h
 * Author: Sergio Henrique
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

// put your class definition here
class Product
{
private:
    std::string name;
    std::string description;
    float basePrice;
    float weight;

public:
    void prompt();
    float getBasePrice() const { return basePrice; }
    float getSalesTax() const;
    float getShippingCost() const;
    float getTotalPrice() const;

    void displayAdvertising() const;
    void displayInventory() const;
    void displayReceipt() const;
};

#endif
