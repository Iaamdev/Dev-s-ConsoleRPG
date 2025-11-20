#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"
#include <iostream>
#include <string>

class Fighter : public Player {
  private:
    double defenseBonus;

  public:
    Fighter(std::string name, int health, int attackPower, double startingDefenseBonus = 0.15) : 
      Player(name, health, attackPower), defenseBonus(startingDefenseBonus) {}
    
  // Virtual Function from Player
  virtual void fighterAbility() {
    std::cout << "Defensive stance activated!" << std::endl;
  }

}
#endif // !FIGHTER_H
