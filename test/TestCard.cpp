/**
 * @author Crazy-8 groups
 * @date 2023-02
*/


#include "gtest/gtest.h"
#include "Card.h"

TEST(TestCard, TestConstructorAndGetters) {
  for (int rank = 1; rank < 14; rank++) {
    for (int suit = 0; suit < 4; suit++) {
      Card c{Rank(rank), Suit(suit)};
      EXPECT_EQ(Rank(rank), c.getRank());
      EXPECT_EQ(Suit(suit), c.getSuit());
    }
  }
}

TEST(TestCard, TestSetSuit) {
  Card c(Rank(1), Suit(0));
  EXPECT_EQ(Suit(0), c.getSuit());
  c.setSuit(Suit(1));
  EXPECT_EQ(Suit(1), c.getSuit());
  c.setSuit(Suit(2));
  EXPECT_EQ(Suit(2), c.getSuit());
  c.setSuit(Suit(3));
  EXPECT_EQ(Suit(3), c.getSuit());
}

TEST(TestCard, TestIsEight) {
  for (int suit = 0; suit < 4; suit++) {
    Card c(Rank(8), Suit(suit));
    EXPECT_TRUE(c.isEight());
    Card d(Rank(1), Suit(suit));
    EXPECT_FALSE(d.isEight());
  }
}
