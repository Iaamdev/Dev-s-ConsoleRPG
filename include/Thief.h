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

    void specialUtility() override {
      std::cout << playerName << " Shadow Stance Activated! (Evasion boost activated)" << std::endl;
    }
    
    void specialAttack(Enemy& target) override {
      std::cout << playerName << " used DOUBLE STRIKE!" << std::endl;
      int strike = getAttackPower() * 0.6;
      target.takeDamage(strike);
      if(target.isAlive()) {
        std::cout << "And Another!" << std::endl;
        target.takeDamage(strike);
      }
    }
    
    void ultimateAbility(Enemy& target) override {
      std::cout << playerName << " appears behind enemy" << std::endl;
      int multiplier = (rand() % 2 == 0) ? 4 : 2; // 50:50 chance of hitting a 4x critical
      int strike = getAttackPower() * multiplier;
      // Assassinate turns into Throat slit if the 4x crit is proc'd
      if(multiplier == 4){
        std::cout << " THROAT SLIT! A crit was hit!" << std::endl;
      }
        std::cout << " used ASSASSINATE!" << std::endl;
        target.takeDamage(strike);
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
    
    std::string getSpecialUtilityName() const override { return "SHADOW STANCE"; }
    std::string getSpecialAttackName() const override { return "DOUBLE STRIKE"; }
    std::string getUltimateName() const override { return "ASSASSINATE"; }
    std::string getHealName() const override { return "POTION"; }

    void displayStatus() const override {
      Player::displayStatus();
      std::cout << "*** Class: Thief ***" << std::endl;
      std::cout << "Evasion Chance: " << (evasionChance * 100) << "%" << std::endl;
    }
};

#endif // !THIEF_H
