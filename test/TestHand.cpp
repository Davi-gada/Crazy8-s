/**
 * @author Crazy-8 groups
 * @date 2023-02
*/


#include <vector>
#include "gtest/gtest.h"
#include "Hand.h"
#include "Card.h"

TEST(TestHand, TestConstructorAndGetter) {
  std::vector<Card*> cards;
  Card* c = new Card(Rank(1), Suit(0));
  cards.push_back(c);
  Hand h(cards);
  std::vector<Card*> hand;
  hand = h.getCards();
  EXPECT_EQ(cards.size(), hand.size());
}

TEST(TestHand, TestAddCard) {
  std::vector<Card*> cards;
  Card* c = new Card(Rank(1), Suit(0));
  Hand h(cards);
  h.addToHand(c);
  std::vector<Card*> hand;
  hand = h.getCards();
  EXPECT_EQ(hand.size(), 1);
  EXPECT_EQ(hand[0], c);
}

TEST(TestHand, TestRemoveCard) {
  std::vector<Card*> cards;
  Card* c = new Card(Rank(1), Suit(0));
  cards.push_back(c);
  Hand h(cards);
  Card* d = h.removeFromHand(0);
  EXPECT_EQ(d, c); //Should point to the same object

  delete d;
}

TEST(TestHand, TestSortHand) {
  std::vector<Card*> cards;
  Card* c = new Card(Rank(2), Suit(0));
  Card* d = new Card(Rank(5), Suit(1));
  Card* e = new Card(Rank(1), Suit(0));
  cards.push_back(c);
  cards.push_back(d);
  cards.push_back(e);
  Hand h(cards);
  h.sortHand();
  std::vector<Card*> hand;
  hand = h.getCards();
  EXPECT_EQ(hand.size(), 3);
  EXPECT_EQ(hand[0], e);
  EXPECT_EQ(hand[1], c);
  EXPECT_EQ(hand[2], d);
}


TEST(TestHand, TestFindCard) {
    std::vector<Card*> cards;
    Card* c = new Card(Rank::Eight, Suit::Diamond);
    Card* d = new Card(Rank::Four, Suit::Diamond);
    Card* e = new Card(Rank::Two, Suit::Spade);
    Card* f = new Card(Rank::Four, Suit::Heart);

    cards.push_back(c);
    cards.push_back(d);
    cards.push_back(e);
    cards.push_back(f);

    Hand hand(cards);

    int cardIndex = hand.findCard(Suit::Diamond);
    EXPECT_EQ(cardIndex, 0);

    cardIndex = hand.findCard(Rank::Four);
    EXPECT_EQ(cardIndex, 1);

    cardIndex = hand.findCard(Rank::Two);
    EXPECT_EQ(cardIndex, 2);

    cardIndex = hand.findCard(Rank::Seven);
    EXPECT_EQ(cardIndex, -1);

    c = hand.removeFromHand(2);

    cardIndex = hand.findCard(Suit::Heart);
    EXPECT_EQ(cardIndex, 2);

    delete c;
}

TEST(TestHand, TestGetFromHand) {
    std::vector<Card*> cards;
    cards.push_back(new Card(Rank::Eight, Suit::Diamond));
    cards.push_back(new Card(Rank::Two, Suit::Spade));
    cards.push_back(new Card(Rank::Four, Suit::Heart));

    Hand hand(cards);

    Card* card = hand.getFromHand(1);
    EXPECT_EQ(card->getRank(), Rank::Two);

    card = hand.getFromHand(2);
    EXPECT_NE(card->getRank(), Rank::Two);
    EXPECT_EQ(card->getSuit(), Suit::Heart);
}
