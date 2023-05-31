// Copyright 2023 UNN

#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = WAIT;
    std::cout << "Автомат включен. Готов к работе." << std::endl;
}

void Automata::off() {
    state = OFF;
    std::cout << "Автомат выключен." << std::endl;
}

void Automata::coin(int money) {
    if (state == ACCEPT || state == WAIT) {
        cash += money;
        state = ACCEPT;
        std::cout << "Внесено " << money << " рублей." << std::endl;
    }
    else {
        std::cout << "Невозможно принять деньги." << std::endl;
    }
}

void Automata::getMenu() {
    if (state == WAIT) {
        std::cout << "Меню напитков:" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << "." << menu[i] << "-" << prices[i] << " р" << std::endl;
        }
    }
    else {
        std::cout << "Меню доступно только в состоянии ожидания." << std::endl;
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
                std::cout << "Приготовление напитка..." << std::endl;
                cook();
            }
            else {
                std::cout << "Недостаточно средств." << std::endl;
            }
        }
        else {
            std::cout << "Некорректный выбор напитка." << std::endl;
        }
    }
    else {
        std::cout << "Внесите денеги." << std::endl;
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
        std::cout << "Сеанс обслуживания отменен." << std::endl;
    }
    else {
        std::cout << "Нельзя отменить сеанс обслуживания." << std::endl;
    }
}

void Automata::cook() {
    std::cout << "Напиток готов!" << std::endl;
    finish();
}

void Automata::finish() {
    cash = 0;
    state = WAIT;
    std::cout << "Спасибо! Приходите еще!" << std::endl;
}
