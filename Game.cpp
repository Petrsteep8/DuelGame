#include "Game.h"
#include <iostream>
#include <string>

Game::Game() : hero(20), enemy(24), potions(2) {
}

void Game::printState() const {
    std::cout << "STATE " << hero.hp() << " " << enemy.hp() << " " << potions << "\n";
}

void Game::run() {
    std::string command;

    while (std::getline(std::cin, command)) {

        if (!command.empty() && command.back() == '\r') {
            command.pop_back();
        }

        if (command == "ATTACK") {
            enemy.takeDamage(6);

            if (!enemy.alive()) {
                std::cout << "WIN\n";
                break;
            }

            hero.takeDamage(5);
            if (!hero.alive()) {
                std::cout << "LOSE\n";
                break;
            }
            printState();

        }
        else if (command == "HEAL") {
            if (potions == 0) {
                std::cout << "NO POTIONS\n";
            }
            else {
                potions--;
                hero.heal(8);

                hero.takeDamage(5);
                if (!hero.alive()) {
                    std::cout << "LOSE\n";
                    break;
                }
                printState();
            }

        }
        else if (command == "STATUS") {
            printState();

        }
        else if (command == "QUIT") {
            std::cout << "BYE\n";
            break;

        }
        else {
            std::cout << "ERROR\n";
        }
    }
}