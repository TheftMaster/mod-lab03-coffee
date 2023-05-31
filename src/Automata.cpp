// Copyright 2023 UNN

#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = WAIT;
    std::cout << "������� �������. ����� � ������." << std::endl;
}

void Automata::off() {
    state = OFF;
    std::cout << "������� ��������." << std::endl;
}

void Automata::coin(int money) {
    if (state == ACCEPT || state == WAIT) {
        cash += money;
        state = ACCEPT;
        std::cout << "������� " << money << " ������." << std::endl;
    }
    else {
        std::cout << "���������� ������� ������." << std::endl;
    }
}

void Automata::getMenu() {
    if (state == WAIT) {
        std::cout << "���� ��������:" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << i + 1 << "." << menu[i] << "-" << prices[i] << " �" << std::endl;
        }
    }
    else {
        std::cout << "���� �������� ������ � ��������� ��������." << std::endl;
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
                std::cout << "������������� �������..." << std::endl;
                cook();
            }
            else {
                std::cout << "������������ �������." << std::endl;
            }
        }
        else {
            std::cout << "������������ ����� �������." << std::endl;
        }
    }
    else {
        std::cout << "������� ������." << std::endl;
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
        std::cout << "����� ������������ �������." << std::endl;
    }
    else {
        std::cout << "������ �������� ����� ������������." << std::endl;
    }
}

void Automata::cook() {
    std::cout << "������� �����!" << std::endl;
    finish();
}

void Automata::finish() {
    cash = 0;
    state = WAIT;
    std::cout << "�������! ��������� ���!" << std::endl;
}
