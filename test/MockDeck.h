/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef MOCKDECK_H
#define MOCKDECK_H

#include <vector>
#include <string>
#include "gmock/gmock.h"
#include "Deck.h"

class MockDeck : public Deck {
 public:
    explicit MockDeck() {}
    virtual ~MockDeck() {}

    MOCK_METHOD(Card*, getTopCard, ());
    MOCK_METHOD(void, shuffleCards, ());
    MOCK_METHOD(void, addToDeck, (Card*));
    MOCK_METHOD(Card*, removeTopCard, ());
    MOCK_METHOD(int, getSize, ());
    MOCK_METHOD(void, createPlayingDeck, ());
};

#endif
