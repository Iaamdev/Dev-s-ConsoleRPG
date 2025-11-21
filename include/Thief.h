#ifndef THIEF_H
#define THIEF_H

#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>

class Thief : public Player {
  private:
    double evasionChance;

  public:
    Thief(std::string name, int health, int attackpower, double startEvasionChance = 0.25) :
      Player(name, health, attackpower), evasionChance(startEvasionChance) {}

    virtual void thiefAbilitiy() {
      std::cout << playerName << " Shadow Stance Activated! (Evasion boost activated)" << std::endl;
    }
  
    void damageEvasion(int damage) {
      if (std::rand() / (RAND_MAX + 1.0) < evasionChance) {
        std::cout << playerName << " dodged the attack completely!" << std::endl;
      } else {
        Player::takeDamage(damage);
      }
    }
    void displayStatus() const override {
      Player::displayStatus();
      std::cout << "*** Class: Thief ***" << std::endl;
      std::cout << "Evasion Chance: " << (evasionChance * 100) << "%" << std::endl;
    }
};

#endif // !THIEF_H
