#include "Item.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int Item::totalItems = 0; 

Item::Item(string name, int value, ItemType type, int attackBonus) : name(name), value(value),
  type(type), attackBonus(attackBonus) {
  ++totalItems;
  // if (ItemType::WEAPON) {
  //   cout << "Weapon created: " << name << " (+" << attackBonus << " ATK)" << endl;
  // } else {
  //   cout << "An item was created: " << this->name << endl;
  // }
}

int Item::getTotalItems() {
  return totalItems;
}

ostream& operator<<(ostream& out, const Item& item) {
  cout << item.name << " (Value: " << item.value << ")";
  return out;
}
