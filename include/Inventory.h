#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <iostream>

class Inventory {
  private:
    std::vector <Item> items;

  public:
    void addItem(const Item& item) { items.push_back(item); }
    
    void display() const {
      std::cout << "--- Inventory ---" << std::endl;
      for (const auto& item : items) {
        std::cout << "- " << item.getName() << std::endl;
      }
    }
};


#endif // !INVENTORY_H
