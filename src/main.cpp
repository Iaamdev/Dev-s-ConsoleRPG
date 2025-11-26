#include "../include/Fighter.h"
#include "../include/Mage.h"
#include "../include/Thief.h"
#include "../include/ascii.h" // ASCII Art
#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;



std::unique_ptr<Player> createPlayer(const string& name) {

  // Choosing player class
  cout << "\nChoose your Class:\n";
  cout << "------------------------------------" << endl;
  knghtAscii();
  cout << "1. Fighter -> High Defense + High Strength" << endl;
  mageAscii();
  cout << "2. Mage -> Spell Damage + Magic" << endl;
  thiefAscii();
  cout << "3. Thief -> Evasion + Criticals" << endl;
  cout << "------------------------------------" << endl;

  int choice = 0;
  cout << "Choice (Input 1, 2, or 3): ";

  // Input validation
  while (!(cin >> choice) || choice < 1 || choice > 3) {
    cin.clear();
    cout << "Invalid input (Input 1, 2, 3): "; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  // Base stats
  const int baseHealth = 100;
  const int baseAttack = 15;

  switch (choice) {
    case 1:
      return make_unique<Fighter>(name, baseHealth + 20, baseAttack, 0.20);
    case 2:
      return make_unique<Mage>(name, baseHealth - 10, baseAttack, 60, 25);
    case 3:
      return make_unique<Thief>(name, baseHealth, baseAttack + 5, 0.35);
    default:
      return nullptr;
  }
}

int main() {
  
  string playerName;
  cout << "\nWelcome to Dev's Console RPG!" << endl;
  cout << "Name: ";
  cin >> playerName;

  unique_ptr<Player> hero = createPlayer(playerName);
  
  if (hero) {
    cout << "\nYour character has been created successfully!\n" << endl;
    hero->displayStatus();
  } else {
    cout << "Error: Failed to create character...";
  }

  return 0;
}
