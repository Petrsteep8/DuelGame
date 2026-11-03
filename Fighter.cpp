#include "Fighter.h"

Fighter::Fighter(int maxHp) {
    this->maxHp = maxHp;
    this->currentHp = maxHp;
}

void Fighter::takeDamage(int amount) {
    if (amount <= 0) return;

    currentHp -= amount;
    if (currentHp < 0) {
        currentHp = 0;
    }
}

void Fighter::heal(int amount) {
    if (amount <= 0) return;

    currentHp += amount;
    if (currentHp > maxHp) {
        currentHp = maxHp;
    }
}

int Fighter::hp() const {
    return currentHp;
}

bool Fighter::alive() const {
    return currentHp > 0;
}