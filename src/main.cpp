// Copyright 2023 UNN

#include "Automata.h"

int main() {
    Automata machine;
    machine.on();

    machine.coin(50);
    machine.coin(100);
    machine.getMenu();
    machine.choice(2);

    machine.off();
    return 0;
}
