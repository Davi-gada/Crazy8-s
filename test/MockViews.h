/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef MOCKVIEWS_H
#define MOCKVIEWS_H

#include <vector>
#include <string>
#include "gmock/gmock.h"
#include "Player.h"
#include "CI.h"
#include "Human.h"
#include "Hand.h"
#include "UI.h"
#include "EndGameUI.h"
#include "StartGameUI.h"
#include "TurnUI.h"

class MockUI : public UI {
 public:
    explicit MockUI() {}
    virtual ~MockUI() {}

    MOCK_METHOD(void, display, ());
    MOCK_METHOD(void, displayHelp, ());
};

class MockStartGameUI : public StartGameUI {
 public:
    explicit MockStartGameUI() {}
    virtual ~MockStartGameUI() {}

    MOCK_METHOD(void, display, ());
    MOCK_METHOD(int, getNumCIPlayers, ());
    MOCK_METHOD(int, getNumHumanPlayers, ());
};

class MockEndGameUI  : public EndGameUI {
 public:
    explicit MockEndGameUI() {}
    virtual ~MockEndGameUI() {}

    MOCK_METHOD(void, display, ());
    MOCK_METHOD(void, displayScores, (std::vector<Player*>));
    MOCK_METHOD(void, displayWinner, (Player*));
};

class MockTurnUI  : public TurnUI {
 public:
    explicit MockTurnUI() {}
    virtual ~MockTurnUI() {}

    MOCK_METHOD(void, display, ());
    MOCK_METHOD(Action, getPlayerAction, ());
    MOCK_METHOD(void, invalidInput, (std::string));
    MOCK_METHOD(Suit, setCardSuitPrompt, ());
    MOCK_METHOD(int, getPlayedCardIndex, ());
    MOCK_METHOD(void, displayQuit, ());
    MOCK_METHOD(void, displayDrawCard, ());
    MOCK_METHOD(void, displaySwapDecks, ());
    MOCK_METHOD(void, displaySortHand, ());
    MOCK_METHOD(void, displayHand, ());
};

#endif
