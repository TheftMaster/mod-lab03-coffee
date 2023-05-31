// Copyright 2023 UNN

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialState) {
    Automata machine;
    EXPECT_EQ(machine.getState(), OFF);
}

TEST(AutomataTest, InitialState1) {
    Automata machine;
    machine.on();
    EXPECT_EQ(machine.getState(), WAIT);
}

TEST(AutomataTest, TurnOnAndOff) {
    Automata machine;
    machine.on();
    EXPECT_EQ(machine.getState(), WAIT);

    machine.off();
    EXPECT_EQ(machine.getState(), OFF);
}
