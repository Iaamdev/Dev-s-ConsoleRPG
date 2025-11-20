#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

// Enum for different item types
enum ItemType {
  CONSUMABLE,
  WEAPON,
  ARMOR,
  QUEST_ITEM
};

class Item {
  private:
    static int totalItems;
    std::string name;
    int value;
    ItemType type;
    int attackBonus;  // For weapons - bonus to attack power
  
public:
  // Constructor with item type support
  Item(std::string name = "Scrap", int value = 0,
     ItemType type = CONSUMABLE, int attackBonus = 0);

  // NEW GETTER METHODS (not in Lab 10):
  // Add these to your existing Item class from Lab 10
  std::string getName() const { return name; }
  int getValue() const { return value; }
  ItemType getType() const { return type; }
  int getAttackBonus() const { return attackBonus; }

  // Static method
  static int getTotalItems();

  // Friend function for output
  friend std::ostream& operator<<(std::ostream& out, const Item& item);

};
#endif
