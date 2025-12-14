#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"
#include <iostream>

class Fighter : public Player {
  private:
    double defenseBonus;
    int strengthBonus;
    int stamina;
    int maxStamina;

  public:
    Fighter(std::string name, int health, int attackPower, int startingDefenseBonus = 5, 
      int startingStrengthBonus = 10, int baseStamina = 20) : 
      Player(name, health, attackPower), defenseBonus(startingDefenseBonus), strengthBonus(startingStrengthBonus), 
      stamina(baseStamina), maxStamina(baseStamina) {}
    
  int getFighterAttackPower() const {
    return Player::getAttackPower() + strengthBonus;
  }

  // Fighter Ability
  void specialUtility() override {
    std::cout << std::endl;
    std::cout << playerName << " activates DEFENSE STANCE!" << std::endl;
    stamina += 10;
    if(stamina > maxStamina) {
      stamina = maxStamina;
    }
  }

  void specialAttack(Enemy& target) override {
    if (stamina >= 10) {
      stamina -= 10;
      std::cout << "\n > "<< playerName << " charges with a SHIELD BASH!" << std::endl;
      // Uses the strength bonus included in getAttackPower() * 1.5
      int damage = getAttackPower() * 1.5; 
      target.takeDamage(damage);
      } else { 
      std::cout << "Not enough stamina for SHIELD BASH!" << std::endl;
    }
  }

  void ultimateAbility(Enemy& target) override {
    if (stamina >= 25) {
      std::cout << "\n > " << playerName << " SMITE's their enemy!" << std::endl;
      int damage = getAttackPower() * 3; 
      std::cout << "SMITE deals " << damage << " damage!" << std::endl;
      target.takeDamage(damage);
    } else { 
      std::cout << "Not enough stamina for SMITE!" << std::endl;
    }
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
  
  // Unique level up override for Fighter Class
  void levelUp() {
    Player::levelUp();
    maxStamina += 5;
    stamina = maxStamina;
    strengthBonus += 2;
    std::cout << "   (Fighter Bonus: Stamina +5, Strength +2)" << std::endl;
  }

  // Unique display status for fighter class "█"
  void displayStatus() const override {
    Player::displayStatus();
    std::cout << "*** Class: Fighter ***" << std::endl;
    std::cout << "Defense Bonus: " << (defenseBonus * 100) << "% Damage Reduction" << std::endl;
    std::cout << "Strength Bonus(+ Atk Power): " << getAttackPower() << std::endl;
    std::cout << "Stamina: " << stamina << "/" << maxStamina << "\n> |";

    int bars = (stamina * 10) / maxStamina;
    for (int i = 0; i < 10; ++i) {
      if (i < bars) {
        std::cout << "█";
      } else { 
        std::cout << " ";
      }
    }
    std::cout << "|" << std::endl;
  }
};

#endif // !FIGHTER_H
