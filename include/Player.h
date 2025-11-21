#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"

class Player {
  private:
    // Inventory inventory;
    int level;
    int experience;
    int expToNextLevel;

  protected:
    int currentHealth;
    int maxHealth;
    std::string playerName;

  public:

    virtual ~Player();
    // Constructor
    Player(std::string name, int health, int attackPower) : playerName(name),
      currentHealth(health), maxHealth(health), level(1), experience(0),
      expToNextLevel(100) {};

    virtual void specialAbilityAttack();  // Will use this for speical attacks for each Class  

    virtual int getAttackPower() const;

    void takeDamage(int damage);

    virtual void displayStatus() const;

    // Player-specific methods
    void gainExp(int exp);
    void levelUp();

    // Inventory access
    void showInventory() const;
    Player& operator+=(const Item& item);

    // Getters
    int getLevel() const { return level; }
    int getExp() const { return experience; }

};

#endif //!PLAYER_H
