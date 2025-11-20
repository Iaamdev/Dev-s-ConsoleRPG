#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
#include <iostream>
#include <string>

class Mage : public Player {
  private:
    int mana;
    int maxMana;
    int spellPower;

  public:
    Mage(std::string name, int health, int attackPower, int baseMana = 10, int baseSpellPower = 10) :
      Player(name, health, attackPower), mana(baseMana), maxMana(baseMana), spellPower(baseSpellPower) {}

    virtual void mageAbility() {
      if (mana >= 10) {
        mana -= 10;
        std::cout << playerName << " used a spell!" << std::endl;
      } else {
        std::cout << playerName << " cannot use a spell right now (out of mana)..." << std::endl;
      }
    }
};

#endif // !MAGE_H
