// Copyright 2023 UNN

#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = WAIT;
}

void Automata::off() {
    state = OFF;
}

void Automata::coin(int money) {
    if (state == ACCEPT || state == WAIT) {
        cash += money;
        state = ACCEPT;
        std::cout << " " << money << " " << std::endl;
    }
}

void Automata::getMenu() {
    if (state == WAIT) {
        for (int i = 0; i < 3; i++) {
            std::cout << i+1 << "." << menu[i] << prices[i] << std::endl;
        }
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int option) {
    if (state == ACCEPT) {
        if (option >= 1 && option <= 3) {
            if (check()) {
                state = COOK;
                cook();
            }
        }
    }
}

bool Automata::check() {
    for (int i = 0; i < 3; i++) {
        if (cash >= prices[i]) {
            return true;
        }
    }
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT) {
        cash = 0;
        state = WAIT;
    }
}

void Automata::cook() {
    finish();
}

void Automata::finish() {
    cash = 0;
    state = WAIT;
}
