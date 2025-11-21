#ifndef CHARACTER_H
#define CHARACTER_H
    
#include <string>

class Character {
  protected:
    std::string name;
    int attackPower;

  public:
    virtual ~Character() = default; 
    
    virtual int getAttackPower() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual void displayerStatus() const = 0;
};

#endif // !CHARACTER_H
