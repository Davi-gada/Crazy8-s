/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include "gtest/gtest.h"
#include "CI.h"

TEST(TestCI, SetCIStrategyTest) {
    std::vector<Card*> cards;
    Hand hand(cards);
    Player* player = new CI("ci", 1, &hand);;
    CI* ci = dynamic_cast<CI*>(player);

    ci->setStrategy(CIStrategy::PlaySameRank);
    EXPECT_EQ(ci->getStrategy(), CIStrategy::PlaySameRank);

    ci->setStrategy(CIStrategy::PlaySameSuit);
    EXPECT_NE(ci->getStrategy(), CIStrategy::PlaySameRank);

    delete ci;
}
