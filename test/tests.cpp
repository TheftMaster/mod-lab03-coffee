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

TEST(AutomataTest, CoinAndCheck) {
    Automata machine;
    machine.on();

    machine.coin(50);
    EXPECT_EQ(machine.getState(), ACCEPT);

    machine.coin(100);
    EXPECT_EQ(machine.getState(), ACCEPT);
}

TEST(AutomataTest, CookAndFinish) {
    Automata machine;
    machine.on();

    machine.coin(100);
    EXPECT_EQ(machine.getState(), ACCEPT);

    machine.choice(1);
    EXPECT_EQ(machine.getState(), COOK);

    testing::internal::CaptureStdout();
    machine.cook();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(machine.getState(), WAIT);

    machine.finish();
    EXPECT_EQ(machine.getState(), WAIT);
    EXPECT_EQ(machine.check(), false);

    machine.off();
    EXPECT_EQ(machine.getState(), OFF);
}
