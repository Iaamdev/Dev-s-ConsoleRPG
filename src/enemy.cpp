#include "../include/Enemy.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Constructor for the enemies used
Enemy::Enemy(string name, int health, int attackPower, int expReward, char symbol) : 
  Character(name, health, attackPower), expReward(expReward), symbol(symbol) {
  cout << "Enemy " << name << " has appeared!" << endl;
}

int Enemy::getAttackPower() const {
  return attackPower;
}

void Enemy::takeDamage(int damage) {
  if (rand() % 100 < 10) {
    damage = damage / 2;
    cout << name << " blocks some of the damage!\n";
  }
  Character::takeDamage(damage);
}

void Enemy::displayStatus() const {
  cout << "Enemy: " << name << endl;
  cout << "HP: " << health << " | Atk: " << attackPower << endl;
  cout << "EXP Gain: " << expReward << endl;
}

