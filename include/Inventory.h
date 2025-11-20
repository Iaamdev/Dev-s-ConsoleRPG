#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <iostream>


class Inventory {
  private:
    Item* items;
    int capacity;
    int ItemCount;

  public:
    Inventory(int capacity);
    ~Inventory();

    Inventory(const Inventory& other);
    
    bool addItem(const Item& item);
    
    void display() const;

    int getTotalAttackBonus() const;
};


#endif // !INVENTORY_H
