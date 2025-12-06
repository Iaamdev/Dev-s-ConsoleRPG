#include "../include/Battle.h"
#include <ios>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <thread>

using namespace std;

void pace() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void checkGameOver(const Player& hero) {
  if (hero.isDead()) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "           Y O U   D I E D              " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Your journey ends here, adventurer..." << std::endl;
    // Stops the entire program immediately
    exit(0); 
  }
}

void Battle(Player& player, Enemy& enemy) {
  cout << "\n--- Battle Start! ---" << endl;
  cout << endl;
  player.displayStatus();
  cout << "--------------------------" << endl;
  enemy.displayStatus();
  cout << "--------------------------" << endl;

  while (enemy.isAlive()) {

    // Action available based on level
    int currentLevel = player.getLevel();
    int maxChoice = 2;

    cout << "\n*******************" << endl;
    cout << "What will you do?:" << endl;
    cout << "1. Attack" << endl;
    cout << "2. " << player.getSpecialUtilityName() << endl;

    if (currentLevel >= 3) {
      cout << "3. " << player.getSpecialAttackName() << endl;
      maxChoice = 3;
    }

    if (currentLevel >= 6) {
      cout << "4. " << player.getUltimateName() << endl;
      maxChoice = 4;
    }

    if (currentLevel >= 9) {
      cout << "5. " << player.getHealName() << endl;
      maxChoice = 5;
    }

    cout << "-> ";

    int choice;
    while (!(cin >> choice) || choice < 1 || choice > maxChoice){
      cout << "Invalid choice. Enter 1-" << maxChoice << ": ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice == 1) {
      int damage = player.getAttackPower();
      cout << "*******************" << endl;
      cout << "\n > You attacked " << enemy.getName() << " for " << damage << " damage!" << endl;
      pace();
      enemy.takeDamage(damage);

    } else if (choice == 2) {
      player.specialUtility();

    } else if (choice == 3) {
      player.specialAttack(enemy);

    } else if (choice == 4) {
      player.ultimateAbility(enemy); 

    } else if (choice == 5) {
      player.performHeal();

    }

    pace();

    if (!enemy.isAlive()) {
      cout << endl;
      cout << "You defeated " << enemy.getName() << "!" << endl;
      player.gainExp(enemy.getExpReward());
      player.displayStatus();
      return;
    }

    cout << "\n > " << enemy.getName() << " attacked you!" << endl;
    pace();
    player.takeDamage(enemy.getAttackPower());

    checkGameOver(player);
  }
}
