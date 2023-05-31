// Copyright 2023 UNN

#pragma once

#ifndef INCLUDE_AUTOMATAH
#define INCLUDE_AUTOMATAH

#include <string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(int money);
    void getMenu();
    STATES getState();
    void choice(int option);
    bool check();
    void cancel();
    void cook();
    void finish();

private:
    int cash;
    std::string menu[3];
    int prices[3];
    STATES state;
};

#endif // INCLUDE_AUTOMATAH
