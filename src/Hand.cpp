/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include <vector>
#include "Hand.h"

Hand::Hand() {}

Hand::Hand(std::vector<Card*> cards) {
    cardsInHand = cards;
}

Hand::~Hand() {
    if (cardsInHand.size() != 0) {
        for (auto card : cardsInHand) {
            delete card;
            card = nullptr;
        }
        cardsInHand.clear();
    }
}

std::vector<Card*> Hand::getCards() {
  return cardsInHand;
}

void Hand::addToHand(Card* card) {
    cardsInHand.push_back(card);
}

Card* Hand::removeFromHand(int cardIndex) {
    Card* card = cardsInHand[cardIndex];
    cardsInHand.erase(cardsInHand.begin()+cardIndex);
    return card;
}

void Hand::sortHand() {
    int n = cardsInHand.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            Card* a = cardsInHand[i];
            Card* b = cardsInHand[j];
             if (a->getSuit() > b->getSuit() ||
                (a->getSuit() == b->getSuit() && a->getRank() > b->getRank())) {
                cardsInHand[i] = b;
                cardsInHand[j] = a;
            }
        }
    }
}

bool Hand::isEmpty() {
    if (cardsInHand.size() == 0)
        return true;
    else
        return false;
}

int Hand::getHandSize() {
    handSize = cardsInHand.size();
    return handSize;
}

int Hand::findCard(Rank rank) {
    if (cardsInHand.size() == 0)
        return -1;

    for (int i = 0; i < cardsInHand.size(); i++) {
        if (cardsInHand[i]->getRank() == rank)
            return i;
    }
    return -1;
}

int Hand::findCard(Suit suit) {
    if (cardsInHand.size() == 0)
        return -1;

    for (int i = 0; i < cardsInHand.size(); i++) {
        if (cardsInHand[i]->getSuit() == suit)
            return i;
    }
    return -1;
}

Card* Hand::getFromHand(int cardIndex) {
    return cardsInHand.at(cardIndex);
}
