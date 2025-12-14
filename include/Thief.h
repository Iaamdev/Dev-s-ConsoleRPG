#ifndef THIEF_H
#define THIEF_H

#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>

class Thief : public Player {
  private:
    double evasionChance;
    int stamina;
    int maxStamina;

  public:
    Thief(std::string name, int health, int attackpower, double startEvasionChance = 0.25, int baseStamina = 20) :
      Player(name, health, attackpower), evasionChance(startEvasionChance), stamina(baseStamina), 
      maxStamina(baseStamina) {}

    void specialUtility() override {
      std::cout << playerName << " Shadow Stance Activated! (Evasion boost activated)" << std::endl;
      stamina += 10;
      if (stamina > maxStamina) {
        stamina = maxStamina;
      }
    }
    
    void specialAttack(Enemy& target) override {
      if (stamina > 10) {
        std::cout << playerName << " used DOUBLE STRIKE!" << std::endl;
        int strike = getAttackPower() * 0.6;
        target.takeDamage(strike);
        if(target.isAlive()) {
          std::cout << "And Another!" << std::endl;
          target.takeDamage(strike);
        }
      } else {
        std::cout << "Not enought stamina!" << std::endl;
      }
    }
    
    void ultimateAbility(Enemy& target) override {
      if (stamina > 20) {
        stamina -= 20;
        std::cout << playerName << " appears behind enemy" << std::endl;
        int multiplier = (rand() % 2 == 0) ? 4 : 2; // 50:50 chance of hitting a 4x critical
        int strike = getAttackPower() * 1.5;
        int critStrike = getAttackPower() * multiplier;
        // Assassinate turns into Throat slit if the 4x crit is proc'd
        if(multiplier == 4){
          std::cout << " THROAT SLIT! A crit was hit!" << std::endl;
          target.takeDamage(critStrike);
        } else {
          std::cout << " used ASSASSINATE!" << std::endl;
          target.takeDamage(strike);
        }
      }
    }

    void performHeal() override {
      std::cout << playerName << " drinks a Potion." << std::endl;
      int healAmount = 30;
      currentHealth += healAmount;
      if (currentHealth > maxHealth) { 
        currentHealth = maxHealth; 
      }
      std::cout << "Recovered " << healAmount << " HP." << std::endl;
    }

    void damageEvasion(int damage) {
      if (std::rand() / (RAND_MAX + 1.0) < evasionChance) {
        std::cout << playerName << " dodged the attack completely!" << std::endl;
      } else {
        Player::takeDamage(damage);
      }
    }

    void levelUp() {
      Player::levelUp();
      maxStamina += 5;
      stamina = maxStamina;
      evasionChance += 0.02;
      std::cout << "   (Thief Bonus: Stamina +5, Evasion +2%)" << std::endl;
    }
    
    std::string getSpecialUtilityName() const override { return "SHADOW STANCE"; }
    std::string getSpecialAttackName() const override { return "DOUBLE STRIKE"; }
    std::string getUltimateName() const override { return "ASSASSINATE"; }
    std::string getHealName() const override { return "POTION"; }

    void displayStatus() const override {
      Player::displayStatus();
      std::cout << "*** Class: Thief ***" << std::endl;
      std::cout << "Evasion Chance: " << (evasionChance * 100) << "%" << std::endl;
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

#endif // !THIEF_H
