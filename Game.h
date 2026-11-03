#ifndef GAME_H
#define GAME_H

#include "Fighter.h"
#include <string>

class Game {
private:
    Fighter hero;
    Fighter enemy;
    int potions;

    void printState() const;

public:
    Game();
    void run();
};

#endif // GAME_H