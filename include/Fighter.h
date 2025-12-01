#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"
#include <iostream>

class Fighter : public Player {
  private:
    double defenseBonus;
    int strengthBonus;

  public:
    Fighter(std::string name, int health, int attackPower, double startingDefenseBonus = 0.15, 
      int startingStrengthBonus = 10) : 
      Player(name, health, attackPower), defenseBonus(startingDefenseBonus), strengthBonus(startingStrengthBonus) {}
    
  // Virtual Function from Player
  virtual void fighterAbility() {
    std::cout << "Defensive stance activated!" << std::endl;
  }

  int getAttackPower() const override {
    return Player::getAttackPower() + strengthBonus;
  }

  // Ability attacks
  void performSpecialUtility() const {
    std::cout << playerName << " activates Defensive Stance!" << std::endl;
  }

  void performSpecialAttack() const {
    std::cout << playerName << " charges with a SHIELD BASH!" << std::endl;
    // Uses the strength bonus included in getAttackPower() * 1.5
    int damage = getAttackPower() * 1.5; 
    target.takeDamage(damage);
  }

  void performUltimateAbility() const {
    std::cout << playerName << " SMITE's their enemy!" << std::endl;
    int damage = getAttackPower() * 3; 
    std::cout << "SMITE deals " << damage << " damage!" << std::endl;
    target.takeDamage(damage);
  }

  void performHealAbility() const {
    int healAmount = maxHealth * 0.4; // Recover 40% HP
    currentHealth += healAmount;
    if (currentHealth > maxHealth) {
      currentHealth = maxHealth; 
    }
    std::cout << playerName << " uses Second Wind and recovers " << healAmount << " HP!" << std::endl;
  }

  // Getters for class
  std::string getSpecialName() const override { return "Defensive Stance"; }
  std::string getSpeicalAttackName() const override { return "Shield Bash"; }
  std::string getUltimateName() const override { return "Smite"; }
  std::string getHealName() const override { return "Second Wind"; }

  // Unique display status for fighter class
  void displayStatus() const override {
    Player::displayStatus();
    std::cout << "*** Class: Fighter ***" << std::endl;
    std::cout << "Defense Bonus: " << (defenseBonus * 100) << "% Damage Reduction" << std::endl;
    std::cout << "Strength Bonus(+ Atk Power): " << getAttackPower() << std::endl;
  }

};

#endif // !FIGHTER_H
