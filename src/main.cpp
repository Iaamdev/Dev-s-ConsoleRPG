#include "../include/Fighter.h"
#include "../include/Mage.h"
#include "../include/Thief.h"
#include "../include/ascii.h" // ASCII Art
#include "../include/Enemy.h"
#include "../include/Battle.h"
#include "../include/scenarios.h"

#include <iostream>
#include <memory>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <cstdlib>


std::unique_ptr<Player> createPlayer(const std::string& name) {

  // Choosing player class
  std::cout << "\nChoose your Class:\n";
  std::cout << "------------------------------------" << std::endl;
  knghtAscii();
  std::cout << "1. Fighter -> High Defense + High Strength" << std::endl;
  mageAscii();
  std::cout << "2. Mage -> Spell Damage + Magic" << std::endl;
  thiefAscii();
  std::cout << "3. Thief -> Evasion + Criticals" << std::endl;
  std::cout << "------------------------------------" << std::endl;

  int choice = 0;
  std::cout << "Choice (Input 1, 2, or 3): ";

  // Input validation
  while (!(std::cin >> choice) || choice < 1 || choice > 3) {
    std::cin.clear();
    std::cout << "Invalid input (Input 1, 2, 3): "; 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
  
  std::string playerName;
  std::cout << "\nWelcome to Dev's Console RPG!" << std::endl;
  std::cout << "Name: ";
  std::cin >> playerName;

  std::unique_ptr<Player> hero = createPlayer(playerName);
  
  if (hero) {
    std::cout << "\nYour character has been created successfully!\n" << std::endl;
    hero->displayStatus();

    bool gameRunning = true;
    
    while (gameRunning) {
      // Scenario Test
      explore(*hero);

      std::cout << "\nScenario complete!" << std::endl;
      std::cout << "Do you want to continue your adventure? (y/n): ";
      char userChoice;
      std::cin >> userChoice;
        
      if (userChoice == 'n' || userChoice == 'N') {
        gameRunning = false;
        std::cout << "You retire from adventuring. Thanks for playing!" << std::endl;
      } else {
        std::cout << "\nYou rest briefly by a campfire..." << std::endl;
        hero->heal(30);
      }
    }
  } else {
    std::cout << "Error: Failed to create character...";
  }
  
  return 0;
}
