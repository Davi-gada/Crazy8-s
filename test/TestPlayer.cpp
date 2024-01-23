/**
 * @author Crazy-8 groups
 * @date 2023-02
*/


#include "gtest/gtest.h"
#include "Player.h"

TEST(TestPlayer, TestConstructorAndGetters) {
  for (int i = 0; i < 4; i++) {
    Player p("Player " + std::to_string(i), i, nullptr);
    EXPECT_EQ("Player " + std::to_string(i), p.getName());
    EXPECT_EQ(i, p.getPlayerNumber());
  }
}

TEST(TestPlayer, TestGetHand) {
    std::vector<Card*> cards;
    cards.push_back(new Card(Rank::Eight, Suit::Diamond));
    cards.push_back(new Card(Rank::Four, Suit::Diamond));
    cards.push_back(new Card(Rank::Three, Suit::Heart));
    cards.push_back(new Card(Rank::Two, Suit::Spade));
    cards.push_back(new Card(Rank::Ace, Suit::Club));

    Hand hand(cards);
    Player p("Player 1", 1, &hand);

    Hand* pHand = p.getHand();
    int handSize = pHand->getHandSize();
    EXPECT_EQ(handSize, 5);
}

TEST(TestPlayer, TestGetScore) {
  Player p("Player 1", 1, nullptr);
  EXPECT_EQ(0, p.getScore());
}

TEST(TestPlayer, TestGetName) {
  Player p("Player 1", 1, nullptr);
  EXPECT_EQ("Player 1", p.getName());

  Player q("Player q", 2, nullptr);
  EXPECT_EQ(q.getName(), "Player q");
}

TEST(TestPlayer, TestSetScore) {
  Player p("Player 1", 1, nullptr);
  EXPECT_EQ(0, p.getScore());
  p.setScore(5);
  EXPECT_EQ(5, p.getScore());
  p.setScore(3);
  EXPECT_EQ(3, p.getScore());
}

TEST(TestPlayer, TestGetPlayerNumber) {
  Player p("Player 1", 1, nullptr);
  EXPECT_EQ(1, p.getPlayerNumber());
}

TEST(TestPlayer, TestSetPlayerType) {
  Player p("Player 1", 1, nullptr);
  p.setPlayerType(true);
  EXPECT_TRUE(p.isHumanPlayer());

  p.setPlayerType(false);
  EXPECT_FALSE(p.isHumanPlayer());
}
