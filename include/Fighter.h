#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"
#include <iostream>

class Fighter : public Player {
  private:
    double defenseBonus;
    int strengthBonus;

  public:
    Fighter(std::string name, int health, int attackPower, int startingDefenseBonus = 5, 
      int startingStrengthBonus = 10) : 
      Player(name, health, attackPower), defenseBonus(startingDefenseBonus), strengthBonus(startingStrengthBonus) {}
    
  int getFighterAttackPower() const {
    return Player::getAttackPower() + strengthBonus;
  }

  // Ability attacks
  void specialUtility() override {
    std::cout << playerName << " activates DEFENSE STANCE!" << std::endl;
  }

  void specialAttack(Enemy& target) override {
    std::cout << "\n > "<< playerName << " charges with a SHIELD BASH!" << std::endl;
    // Uses the strength bonus included in getAttackPower() * 1.5
    int damage = getAttackPower() * 1.5; 
    target.takeDamage(damage);
  }

  void ultimateAbility(Enemy& target) override {
    std::cout << "\n > " << playerName << " SMITE's their enemy!" << std::endl;
    int damage = getAttackPower() * 3; 
    std::cout << "SMITE deals " << damage << " damage!" << std::endl;
    target.takeDamage(damage);
  }

  void performHeal() override {
    int healAmount = maxHealth * 0.4; // Recover 40% HP
    currentHealth += healAmount;
    if (currentHealth > maxHealth) {
      currentHealth = maxHealth; 
    }
    std::cout << "\n > "<< playerName << " uses SECOND WIND and recovers " << healAmount << " HP!" << std::endl;
  }

  // Getters for class
  std::string getSpecialUtilityName() const override { return "DEFENSIVE STANCE"; }
  std::string getSpecialAttackName() const override { return "SHIELD BASH"; }
  std::string getUltimateName() const override { return "SMITE"; }
  std::string getHealName() const override { return "SECOND WIND"; }

  // Unique display status for fighter class
  void displayStatus() const override {
    Player::displayStatus();
    std::cout << "*** Class: Fighter ***" << std::endl;
    std::cout << "Defense Bonus: " << (defenseBonus * 100) << "% Damage Reduction" << std::endl;
    std::cout << "Strength Bonus(+ Atk Power): " << getAttackPower() << std::endl;
  }

};

#endif // !FIGHTER_H
