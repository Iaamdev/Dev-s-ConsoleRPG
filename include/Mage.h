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

    void specialUtility() override {
      mana += 10;
      std::cout << playerName << " used MANA SPARK!" << std::endl;
      if (mana > maxMana) {
        mana = maxMana;
      }  
    }

    void specialAttack(Enemy& target) override {
      if (mana >= 10) {
        mana -= 10;
        std::cout << playerName << " casts VORTEX BLAST!" << std::endl;
        int damage = getAttackPower() + spellPower;
        target.takeDamage(damage);
        // std::cout << playerName << " hit " << target << " for " << damage << " damage!"
      } else {
        std::cout << "You don't have enough mana for VORTEX BLAST!" << std::endl;
        // May add the below code if I have issues with the loop
        // std::cout << "You don't have enough mana! You used a regular attack!" << std::endl;
        // target.takeDamage(getAttackPower())
      }
    }

    void ultimateAbility(Enemy& target) override {
      if (mana >= 20) {
        mana -= 20;
        std::cout << playerName << " casts METEORA!" << std::endl;
        int damage = (getAttackPower() + spellPower) * 2;
        target.takeDamage(damage);
      } else {
        std::cout << "You don't have enough mana for METEORA!" << std::endl;
      }
    }
    
    void performHeal() override {
      if (mana >= 15) {
        mana -= 15;
        int healAmount = 50;
        currentHealth += healAmount;
        if (currentHealth > maxHealth) {
          currentHealth = maxHealth;
          std::cout << playerName << " casts CURAGA!" << std::endl;
          std::cout << playerName << " healed for " << healAmount << " HP!";
        } else {
          std::cout << "You don't have enough mana for CURAGA!" << std::endl;
        }
      } 
    }

    std::string getSpecialUtilityName() const override { return "MANA SPARK"; }
    std::string getSpecialAttackName() const override { return "VORTEX BLAST"; }
    std::string getUltimateName() const override { return "METEORA"; }
    std::string getHealName() const override { return "CURAGA"; }
    

    void displayStatus() const override {
      Player::displayStatus();
      std::cout << "*** Class: Mage ***" << std::endl;
      std::cout << "Mana: " << mana << "/" << maxMana << std::endl;
      std::cout << "Spell Power: " << spellPower << std::endl;
      std::cout << "Mana: " << mana << "/" << maxMana << "\n> |";
      int bars = (mana * 10) / maxMana; 
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

#endif // !MAGE_H
