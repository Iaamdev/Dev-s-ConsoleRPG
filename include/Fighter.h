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
    return Player::getAttackPower();
  }

  void displayStatus() const override {
    Player::displayStatus();
    std::cout << "*** Class: Fighter ***" << std::endl;
    std::cout << "Defense Bonus: " << (defenseBonus * 100) << "% Damage Reduction" << std::endl;
    std::cout << "Strength Bonus(+ Atk Power): " << getAttackPower() + strengthBonus << std::endl;
  }

};

#endif // !FIGHTER_H
