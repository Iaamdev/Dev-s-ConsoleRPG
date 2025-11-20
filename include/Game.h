#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Item.h"
#include <vector>

class Game {
  private:
    Player player;
    bool isRunning;
    int enemiesDefeated;           // NEW: Track victory condition

    // Helper methods
    void processInput();            // Modified from Lab 11

  public:
    Game();
    ~Game();
    void run();

};

#endif //!GAME_H
