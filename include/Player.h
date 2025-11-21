#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Inventory.h"

class Player : public Character {
  private:
    Inventory inventory;
    int level;
    int experience;
    int expToNextLevel;

  protected:
    int currentHealth;
    int maxHealth;
    std::string playerName;

  public:

    ~Player();
    // Constructor
    Player(std::string name, int health, int attackPower);

    virtual int specialAbilityAttack();  // Will use this for speical attacks for each Class  

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
