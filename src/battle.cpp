#include "../include/Battle.h"
#include <ios>
#include <iostream>
#include <limits>

using namespace std;

void Battle(Player& player, Enemy& enemy) {
  cout << "\nA " << enemy.getName() << " has shown up!" << endl;
  cout << "--- Battle Start! ---" << endl;

  while (enemy.isAlive()) {
    player.displayStatus();
    cout << "--------------------------" << endl;
    enemy.displayStatus();

    // Action available based on level
    int currentLevel = player.getLevel();
    int maxChoice = 2;

    cout << "\nWhat will you do?:" << endl;
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

    cout << "> ";

    int choice;
    while (!(cin >> choice) || choice < 1 || choice > maxChoice){
      cout << "Invalid choice. Enter 1-" << maxChoice << ": ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice == 1) {
      int damage = player.getAttackPower();
      cout << "You attacked " << enemy.getName() << " for " << damage << " damage!" << endl;
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

    if (!enemy.isAlive()) {
      cout << "\n******************" << endl;
      cout << "You defeated " << enemy.getName() << "!" << endl;
      player.gainExp(enemy.getExpReward());
      return;
    }

    cout << "\n" << enemy.getName() << " attack you!" << endl;
    player.takeDamage(enemy.getAttackPower());
  }
}
