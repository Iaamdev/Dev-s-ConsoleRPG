#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Inventory.h"
#include "Item.h"

class Enemy;

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
    
    // Abilities 
    virtual void specialUtility() = 0;  
    virtual void specialAttack(Enemy& target) = 0;
    virtual void ultimateAbility(Enemy& target) = 0;
    virtual void performHeal() = 0;

    // Getters for ability name pulls
    virtual std::string getSpecialUtilityName() const = 0;
    virtual std::string getSpecialAttackName() const = 0;
    virtual std::string getUltimateName() const = 0;
    virtual std::string getHealName() const = 0;
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
