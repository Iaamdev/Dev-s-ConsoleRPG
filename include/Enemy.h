#ifndef ENEMY_H
#define ENEMY_H
#include "../include/Character.h"

class Enemy : public Character {
  protected:
    int expReward;
    char symbol;  // How enemy appears on map

  public:
    // Constructor
    Enemy(std::string name, int health, int attackPower, int expReward, char symbol);

    // MUST override pure virtual function from Character
    virtual int getAttackPower() const override;
    void takeDamage(int damage) override;
    virtual void displayStatus() const override;

    // Getters
    int getExpReward() const { return expReward; }
    char getSymbol() const { return symbol; }

};

#endif // !ENEMY_H
