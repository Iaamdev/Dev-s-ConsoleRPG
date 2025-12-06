#include "../include/Enemy.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Constructor for the enemies used
Enemy::Enemy(string name, int health, int attackPower, int expReward) : 
  currentHealth(health), maxHealth(health), expReward(expReward) {
  this->name = name;
  this->attackPower = attackPower;
  cout << endl;
  cout << " > Enemy " << name << " has appeared!" << endl;
}

int Enemy::getAttackPower() const {
  return attackPower;
}

void Enemy::takeDamage(int damage) {
  if (rand() % 100 < 10) {
    damage = damage / 2;
    cout << " > " << name << " blocks some of the damage!\n";
  } 

  currentHealth -= damage;

  if (currentHealth < 0) {
    currentHealth = 0;
  }
  cout << " > " << name << " took " << damage << " damage! " << endl;
  cout << "\n-------------------------" << endl;
  cout << name << endl;
  cout << "HP: " << currentHealth << "/" << maxHealth << endl;
  cout << "-------------------------" << endl;
}

void Enemy::displayStatus() const {
  cout << "Enemy: " << name << endl;
  cout << "HP: " << currentHealth << " / " << maxHealth << endl;
  cout << "EXP Gain: " << expReward << endl;
}

bool Enemy::isAlive() const {
  return currentHealth > 0;
}
