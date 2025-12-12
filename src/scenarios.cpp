#include "../include/scenarios.h"
#include "../include/Enemy.h"
#include "../include/Battle.h"
#include "../include/ascii.h"
#include <iostream>
#include <thread> 
#include <chrono>
#include <cstdlib>
#include <vector>
#include <limits>

using namespace std;

//NOTE: I want to add medium difficulty scenarios and make the Hard one more difficult
//(maybe nerf player attack damage)

void wait() {
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void explore(Player& hero) {
  cout << "\n----------------------------------------" << endl;
  cout << "You stand at a fork in the road...\n" << endl;
    
  vector<string> safePaths = {
    "A well-lit path through a sunny meadow.",
    "A quiet road leading to a nearby village.",
    "A shallow stream with clear water.",
    "A dusty trade route used by merchants."
  };

  vector<string> dangerPaths = {
    "A dark, jagged cave entrance emitting a foul smell.",
    "A narrow mountain pass covered in fog.",
    "A heavy iron gate leading into a fortress.",
    "A spooky graveyard with ancient tombstones."
  };

  string safeDesc = safePaths[rand() % safePaths.size()];
  string dangerDesc = dangerPaths[rand() % dangerPaths.size()];

  cout << "1. " << safeDesc << " (Low Risk)" << endl;
  cout << "2. " << dangerDesc << " (High Risk)" << endl;
  cout << "> ";

  int choice;
  while (!(cin >> choice) || choice < 1 || choice > 2) {
    cout << "Invalid choice. Enter 1 or 2: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int scenarioID = 0;

  if (choice == 1) {
    cout << "\nYou choose the safer route...\n" << endl;
    scenarioID = (rand() % 5) + 1; 
  } else {
    cout << "\nYou steel your nerves and brave the dark path...\n" << endl;
    scenarioID = (rand() % 5) + 6;
  }

  wait();
  runScenario(hero, scenarioID);
}

void runScenario(Player& hero, int scenarioID) {
  cout << "\n========================================" << endl;
  cout << "           SCENARIO " << scenarioID << "            " << endl;
  cout << "========================================" << endl;

  switch (scenarioID) {
    case 1: {
      cout << "You start your journey in the local tavern basement." << endl;
      cout << "The innkeeper asked you to clear out some pests...\n" << endl;
      wait();
      ratAscii();
      Enemy rat("Giant Rat", 30, 3, 20); 
      Battle(hero, rat);
      break;
    }
    case 2: {
      cout << "Leaving the town, you travel through the Whispering Woods." << endl;
      cout << "Suddenly, a green figure jumps from the bushes!\n" << endl;
      wait();
      goblinAscii();
      Enemy goblin("Goblin Scout", 50, 6, 40);
      Battle(hero, goblin);
      break;
    }
    case 3: {
      cout << "Night falls upon your camp. You hear howling nearby." << endl;
      cout << "A pair of glowing yellow eyes stares at you from the darkness.\n" << endl;
      wait();
      direWolfAscii();
      Enemy wolf("Dire Wolf", 70, 9, 60);
      Battle(hero, wolf);
      break;
    }
    case 4: {
      cout << "You reach the Old Stone Bridge." << endl;
      cout << "A ruffian blocks your path. 'Your money or your life!' he shouts.\n" << endl;
      wait();
      banditAscii();
      Enemy bandit("Roadside Bandit", 90, 11, 80); 
      Battle(hero, bandit);
      break;
    }
    case 5: {
      cout << "Seeking treasure, you enter the Ancient Crypts." << endl;
      cout << "The bones in the corner begin to rattle and assemble...\n" << endl;
      wait();
      skeletonAscii();
      Enemy skeleton("Skeleton Warrior", 110, 13, 100);
      Battle(hero, skeleton);
      break;
    }
    //TODO: Buff the Hard scenarios significantly making them much more challenging
    case 6: {
      cout << "You find an abandoned outpost occupied by a warband." << endl;
      cout << "A massive greenskin brute charges at you!\n" << endl;
      wait();
      orcAscii();
      Enemy orc("Orc Berserker", 200, 26, 130);
      Battle(hero, orc);
      break;
    }
    case 7: {
      cout << "You enter the swamp. The smell is terrible." << endl;
      cout << "A large, regenerating creature emerges from the muck.\n" << endl;
      wait();
      trollAscii();
      Enemy troll("Swamp Troll", 250, 28, 160); 
      Battle(hero, troll);
      break;
    }
    case 8: {
      cout << "You approach the Dark Tower." << endl;
      cout << "A hooded figure chants an incantation, summoning dark energy.\n" << endl;
      wait();
      sorcererAscii(); 
      Enemy cultist("Dark Sorcerer", 300, 30, 200); 
      Battle(hero, cultist);
      break;
    }
    case 9: {
      cout << "Guarding the throne room is the King's fallen champion." << endl;
      cout << "His armor is black as night, and he speaks no words.\n" << endl;
      wait();
      deathKnightAscii();
      Enemy knight("Death Knight", 350, 32, 350); 
      Battle(hero, knight);
      break;
    }
    case 10: {
      // cout << "THE FINAL BATTLE." << endl;
      cout << "You stand before the ancient evil that plagues the land." << endl;
      cout << "The Dragon roars, shaking the very foundations of the earth!\n" << endl;
      wait();
      dragonAscii();
      Enemy dragon("Red Dragon", 500, 40, 1000); 
      Battle(hero, dragon);
      break;
    }
    default:
      cout << "The path is quiet. Nothing happens.\n" << endl;
      break;
    }
}
