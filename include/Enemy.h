#ifndef ENEMY_H
#define ENEMY_H

#include "../include/Character.h"
#include <string>

class Enemy : public Character {
  protected:
    int expReward;
    int currentHealth;
    int maxHealth; 
    
  public:
    // Constructor
    Enemy(std::string name, int health, int attackPower, int expReward);

    // Override functions
    int getAttackPower() const override;
    void takeDamage(int damage) override;
    void displayStatus() const override;

    // Getters/Helpers
    bool isAlive() const;
    int getExpReward() const { return expReward; }
    std::string getName() const { return name; }

};

#endif // !ENEMY_H
