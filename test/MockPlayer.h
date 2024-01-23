/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef MOCKPLAYER_H
#define MOCKPLAYER_H

#include <vector>
#include <string>
#include "gmock/gmock.h"
#include "Player.h"
#include "CI.h"
#include "Human.h"
#include "Hand.h"

class MockPlayer : public Player {
 public:
    explicit MockPlayer() {}
    virtual ~MockPlayer() {}

    MOCK_METHOD(Hand*, getHand, ());
    MOCK_METHOD(int, getScore, ());
    MOCK_METHOD(std::string, getName, ());
    MOCK_METHOD(void, setScore, (int));
    MOCK_METHOD(int, getPlayerNumber, ());
    MOCK_METHOD(void, setPlayerType, (bool));
    MOCK_METHOD(bool, isHumanPlayer, ());
};

class MockCI : public CI {
 public:
    explicit MockCI() {}
    virtual ~MockCI() {}

    MOCK_METHOD(void, setStrategy, (CIStrategy));
    MOCK_METHOD(CIStrategy, getStrategy, ());

    MOCK_METHOD(Hand*, getHand, ());
    MOCK_METHOD(int, getScore, ());
    MOCK_METHOD(std::string, getName, ());
    MOCK_METHOD(void, setScore, (int));
    MOCK_METHOD(int, getPlayerNumber, ());
    MOCK_METHOD(void, setPlayerType, (bool));
    MOCK_METHOD(bool, isHumanPlayer, ());
};

class MockHuman : public Human {
 public:
    explicit MockHuman() {}
    virtual ~MockHuman() {}

    MOCK_METHOD(Hand*, getHand, ());
    MOCK_METHOD(int, getScore, ());
    MOCK_METHOD(std::string, getName, ());
    MOCK_METHOD(void, setScore, (int));
    MOCK_METHOD(int, getPlayerNumber, ());
    MOCK_METHOD(void, setPlayerType, (bool));
    MOCK_METHOD(bool, isHumanPlayer, ());
};

#endif

