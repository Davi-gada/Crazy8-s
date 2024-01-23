/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include <algorithm>
#include <random>
#include <vector>
#include "Deck.h"

Deck::Deck() {
}

Deck::Deck(std::vector<Card*> cards): deckCards{cards} {}

Deck::~Deck() {
  if (deckCards.size() != 0) {
        for (auto card : deckCards) {
            delete card;
            card = nullptr;
        }
        deckCards.clear();
    }
}

Card* Deck::getTopCard() {
  return deckCards.back();
}

void Deck::shuffleCards() {
  auto rd = std::random_device {}();
  auto rng = std::default_random_engine { rd};
  std::shuffle(std::begin(deckCards), std::end(deckCards), rng);
}

void Deck::addToDeck(Card* card) {
  deckCards.push_back(card);
}

Card* Deck::removeTopCard() {
  if (deckCards.size() == 0) {
    return nullptr;
  }
  Card* card = deckCards.back();
  deckCards.pop_back();
  return card;
}

int Deck::getSize() {
  return deckCards.size();
}

void Deck::createPlayingDeck() {
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 13; j++) {
      Card* c = new Card((Rank)j, (Suit)i);
      deckCards.push_back(c);
    }
  }
}
