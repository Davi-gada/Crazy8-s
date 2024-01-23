/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef MOCKCARD_H
#define MOCKCARD_H

#include <vector>
#include <string>
#include "gmock/gmock.h"
#include "Card.h"

class MockCard : public Card {
 public:
    explicit MockCard() {}
    explicit MockCard(Rank, Suit) {}
    virtual ~MockCard() {}

    MOCK_METHOD(Rank, getRank, ());
    MOCK_METHOD(Suit, getSuit, ());
    MOCK_METHOD(void, setSuit, (Suit));
    MOCK_METHOD(bool, isEight, ());
    MOCK_METHOD(int, getScore, (Rank));
};

#endif
