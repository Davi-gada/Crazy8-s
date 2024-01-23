/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef MOCKHAND_H
#define MOCKHAND_H

#include <vector>
#include <string>
#include "gmock/gmock.h"
#include "Hand.h"

class MockHand : public Hand {
 public:
    explicit MockHand() {}
    virtual ~MockHand() {}

    MOCK_METHOD(std::vector<Card*>, getCards, ());
    MOCK_METHOD(void, addToHand, (Card*));
    MOCK_METHOD(Card*, removeFromHand, (int));
    MOCK_METHOD(void, sortHand, ());
    MOCK_METHOD(bool, isEmpty, ());
    MOCK_METHOD(int, getHandSize, ());
    MOCK_METHOD(int, findCard, (Rank));
    MOCK_METHOD(int, findCard, (Suit));
    MOCK_METHOD(Card*, getFromHand, (int));
};

#endif
