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
    Product();
    Product(std::string name, std::string description, float basePrice, float weight);
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    float getBasePrice() const { return basePrice; }
    float getWeight() const { return weight; }
    float getSalesTax() const;
    float getShippingCost() const;
    float getTotalPrice() const;

    void setName(std::string name) { this->name = name; }
    void setDescription(std::string description) { this->description = description; }
    void setBasePrice(float basePrice) {this->basePrice = basePrice; }
    void setWeight(float weight) { this->weight = weight; }

    void displayAdvertising() const;
    void displayInventory() const;
    void displayReceipt() const;
};

#endif
