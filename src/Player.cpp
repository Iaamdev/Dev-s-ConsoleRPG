#include "../include/Player.h"
#include "../include/Inventory.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name, int health, int attackPower) : playerName(name),
  currentHealth(health), maxHealth(health), level(1), experience(0),
  expToNextLevel(100) {
    this->name = name;
    this->attackPower = attackPower;
}

Player::~Player() {}

int Player::specialAbilityAttack() {
  int specialAttackPower = attackPower + 10;
  return specialAttackPower;
}

int Player::getAttackPower() const {
  return attackPower + (level * 5);
}

void Player::takeDamage(int damage) {
  currentHealth -= damage;
  if (currentHealth < 0) {
    currentHealth = 0;
  } else {
    cout << " > " << playerName << " has taken " << damage << " damage!" << endl;
    cout << "\n-------------------------" << endl;
    cout << playerName << endl;
    cout << "HP: " << currentHealth << " / " << maxHealth << endl;
    cout << "-------------------------" << endl;
  }
}

void Player::displayStatus() const {
  cout << "--- " << playerName << " ---" << endl;
  cout << "Level: " << level << " | Exp to next: " << experience << " / " << expToNextLevel << endl;
  cout << "HP: " << currentHealth << " / " << maxHealth << endl;
  cout << "Attack Power: " << getAttackPower() << endl;
}

void Player::gainExp(int exp) {
  experience += exp;
  cout << playerName << " has gained " << exp << " experience points!\n" << endl;
  while (experience >= expToNextLevel) {
    levelUp();
  }
}

void Player::levelUp() {
  level++;
  experience -= expToNextLevel;
  expToNextLevel = static_cast<int>(expToNextLevel * 1.5);
  maxHealth += 10;
  currentHealth = maxHealth;
  attackPower += 2;
  cout << "***Level Up!!***"<< endl;
}

void Player::heal(int amount) {
  int oldHealth = currentHealth;
  currentHealth += amount;
    
  if (currentHealth > maxHealth) {
    currentHealth = maxHealth;
  }
    
  std::cout << playerName << " recovers " << (currentHealth - oldHealth) << " HP. (Health: " << currentHealth << "/" << maxHealth << ")" << std::endl;
}

void Player::showInventory() const {
  inventory.display();
}

Player& Player::operator+=(const Item& item) {
  inventory.addItem(item);
  cout << "Picked up: " << item.getName() << endl;
  return *this;
}
