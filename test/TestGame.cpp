/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef TESTGAME_H
#define TESTGAME_H

#include <vector>
#include <string>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Game.h"
#include "MockCard.h"
#include "MockDeck.h"
#include "MockHand.h"
#include "MockPlayer.h"
#include "MockViews.h"

using ::testing::Return;
using ::testing::_;
using ::testing::Expectation;
using ::testing::Sequence;

TEST(TestGame, DISABLED_TestPlayGame) {
    MockDeck discardDeck;
    MockDeck playingDeck;
    MockHand humanHand;
    MockHand ciHand;
    MockHuman human;
    MockCI ci;
    MockCard discardTop;
    MockCard playingTop;
    MockCard playerCard;
    MockCard ciCard;
    MockTurnUI turnUI;
    Sequence seq_ci_turn;

    // Call dealcards
    Expectation shuffle = EXPECT_CALL(playingDeck, shuffleCards())
    .Times(1);

    EXPECT_CALL(human, getHand())
    .Times(13)
    .WillRepeatedly(Return(&humanHand));

    EXPECT_CALL(humanHand, addToHand(_))
    .Times(7);

    EXPECT_CALL(ci, getHand())
    .Times(10)
    .WillRepeatedly(Return(&ciHand));

    EXPECT_CALL(playingDeck, getSize())
    .Times(14)
    .After(shuffle)
    .WillRepeatedly(Return(14));

    EXPECT_CALL(ciHand, addToHand(_))
    .Times(7);


    Expectation remove_top = EXPECT_CALL(playingDeck, removeTopCard())
    .Times(15)
    .WillRepeatedly(Return(new Card(Rank::Five, Suit::Diamond)));


    EXPECT_CALL(discardDeck, addToDeck(_))
    .Times(1)
    .After(remove_top)
    .WillOnce(::testing::DeleteArg<0>());

    // End Deal Cards

    EXPECT_CALL(human, isHumanPlayer())
    .Times(2)
    .WillRepeatedly(Return(true));


    // Player Turn
    EXPECT_CALL(turnUI, getPlayerAction())
    .Times(2)
    .WillOnce(Return(Action::PlayCard))
    .WillOnce(Return(Action::PlayCard));

    EXPECT_CALL(playerCard, getRank())
    .Times(1)
    .WillOnce(Return(Rank::Seven));

    EXPECT_CALL(turnUI, getPlayedCardIndex())
    .Times(2)
    .WillRepeatedly(Return(2));

    EXPECT_CALL(humanHand, removeFromHand(2))
    .Times(2)
    .WillRepeatedly(Return(&playerCard));

    EXPECT_CALL(playerCard, isEight())
    .Times(4)
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillRepeatedly(Return(true));

    EXPECT_CALL(discardDeck, addToDeck(&playerCard))
    .Times(2);

    EXPECT_CALL(turnUI, setCardSuitPrompt())
    .Times(1)
    .WillRepeatedly(Return(Suit::Heart));

    EXPECT_CALL(playerCard, setSuit(Suit::Heart))
    .Times(1);


    // CI and Player turns
    EXPECT_CALL(discardDeck, getTopCard())
    .Times(3)
    .WillRepeatedly(Return(&discardTop));

    EXPECT_CALL(discardDeck, addToDeck(&ciCard))
    .Times(1);

    EXPECT_CALL(discardTop, getRank())
    .Times(2)
    .WillOnce(Return(Rank::Seven))
    .WillOnce(Return(Rank::Four));

    // CI Turn
    EXPECT_CALL(ci, isHumanPlayer())
    .Times(1)
    .WillRepeatedly(Return(false));

    EXPECT_CALL(ciHand, removeFromHand(_))
    .Times(1)
    .WillOnce(Return(&ciCard));

    EXPECT_CALL(ci, getStrategy())
    .Times(1)
    .WillOnce(Return(CIStrategy::PlaySameRank));

    EXPECT_CALL(ciHand, findCard(Rank::Four))
    .Times(1)
    .InSequence(seq_ci_turn)
    .WillOnce(Return(-1));

    EXPECT_CALL(playingDeck, getSize())
    .Times(1)
    .InSequence(seq_ci_turn)
    .WillOnce(Return(20));

    EXPECT_CALL(playingDeck, removeTopCard())
    .Times(1)
    .InSequence(seq_ci_turn)
    .WillOnce(Return(&playingTop));

    EXPECT_CALL(ciHand, addToHand(&playingTop))
    .Times(1)
    .InSequence(seq_ci_turn);

    EXPECT_CALL(playingTop, getRank())
    .Times(1)
    .InSequence(seq_ci_turn)
    .WillOnce(Return(Rank::Four));

    EXPECT_CALL(ciHand, findCard(Rank::Four))
    .Times(1)
    .InSequence(seq_ci_turn)
    .WillOnce(Return(1));


    // DetermineWinner
    EXPECT_CALL(humanHand, isEmpty())
    .Times(4)
    .WillOnce(Return(false))
    .WillOnce(Return(false))
    .WillOnce(Return(true))
    .WillOnce(Return(true));

    EXPECT_CALL(ciHand, isEmpty())
    .Times(2)
    .WillRepeatedly(Return(false));


    std::vector<Player*> players = {&human, &ci};
    Game* game = new Game(players, &playingDeck, &discardDeck);
    game->setUI(&turnUI);
    Player* winningPlayer = game->playGame();
    EXPECT_EQ(winningPlayer, &human);
    delete game;
}

TEST(TestGame, DISABLED_TestEndGame) {
    MockDeck discard;
    MockDeck playing;
    MockHand hand1;
    MockHand hand2;
    MockPlayer player1;
    MockPlayer player2;
    MockCard card1;
    MockCard card2;
    MockEndGameUI endGameUI;

    std::vector<Player*> players = {&player1, &player2};

    Expectation display = EXPECT_CALL(endGameUI, display())
    .Times(1);

    // Call to calculate scores
    EXPECT_CALL(player1, getPlayerNumber())
    .Times(3)
    .WillRepeatedly(Return(0));

    EXPECT_CALL(player2, getPlayerNumber())
    .Times(1)
    .WillRepeatedly(Return(1));


    // Player 2's setup
    EXPECT_CALL(player2, getHand())
    .Times(1)
    .WillOnce(Return(&hand2));

    EXPECT_CALL(hand2, getCards())
    .Times(1)
    .WillOnce(Return(std::vector<Card*>{ &card1, &card1, &card1}));

    EXPECT_CALL(card1, getScore(_))
    .Times(3)
    .WillOnce(Return(5))
    .WillOnce(Return(4))
    .WillOnce(Return(1));


    EXPECT_CALL(player1, setScore(_))
    .Times(1);

    Expectation display_scores = EXPECT_CALL(endGameUI, displayScores(players))
    .Times(1)
    .After(display);

    EXPECT_CALL(endGameUI, displayWinner(&player1))
    .Times(1)
    .After(display_scores);


    Game* game = new Game(players, &playing, &discard);
    game->setUI(&endGameUI);
    game->endGame(&player1);
    delete game;
}

TEST(TestGame, TestMatchCardsEight) {
    MockDeck discard;
    MockDeck playing;
    MockPlayer player1;
    MockPlayer player2;
    MockCard mockCard;


    Expectation get_discard_top = EXPECT_CALL(discard, getTopCard())
    .Times(1)
    .WillOnce(Return(&mockCard));

    EXPECT_CALL(mockCard, isEight())
    .Times(1)
    .After(get_discard_top)
    .WillOnce(Return(true));


    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    bool match = game->matchCards(&mockCard);
    EXPECT_TRUE(match);

    delete game;
}

TEST(TestGame, TestMatchCardsRank) {
    MockDeck discard;
    MockDeck playing;
    MockPlayer player1;
    MockPlayer player2;
    MockCard discardCard;
    MockCard playerCard;

    Expectation get_discard_top = EXPECT_CALL(discard, getTopCard())
    .Times(1)
    .WillOnce(Return(&discardCard));

    Expectation eight = EXPECT_CALL(playerCard, isEight())
    .Times(1)
    .After(get_discard_top)
    .WillOnce(Return(false));

    EXPECT_CALL(playerCard, getRank())
    .Times(1)
    .After(eight)
    .WillOnce(Return(Rank::Five));

    EXPECT_CALL(discardCard, getRank())
    .Times(1)
    .WillOnce(Return(Rank::Five));

    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    bool match = game->matchCards(&playerCard);
    EXPECT_TRUE(match);

    delete game;
}

TEST(TestGame, TestMatchCardsSuit) {
    MockDeck discard;
    MockDeck playing;
    MockPlayer player1;
    MockPlayer player2;
    MockCard discardCard;
    MockCard playerCard;

    Expectation get_discard_top = EXPECT_CALL(discard, getTopCard())
    .Times(1)
    .WillOnce(Return(&discardCard));

    Expectation eight = EXPECT_CALL(playerCard, isEight())
    .Times(1)
    .After(get_discard_top)
    .WillOnce(Return(false));

    Expectation rank = EXPECT_CALL(playerCard, getRank())
    .Times(1)
    .After(eight)
    .WillOnce(Return(Rank::Four));

    EXPECT_CALL(discardCard, getRank())
    .Times(1)
    .WillOnce(Return(Rank::Five));

    EXPECT_CALL(playerCard, getSuit())
    .Times(1)
    .After(rank)
    .WillOnce(Return(Suit::Diamond));

    EXPECT_CALL(discardCard, getSuit())
    .Times(1)
    .WillOnce(Return(Suit::Diamond));


    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    bool match = game->matchCards(&playerCard);
    EXPECT_TRUE(match);

    delete game;
}

TEST(TestGame, TestMatchCardsNoMatch) {
    MockDeck discard;
    MockDeck playing;
    MockPlayer player1;
    MockPlayer player2;
    MockCard discardCard;
    MockCard playerCard;


    EXPECT_CALL(discard, getTopCard())
    .Times(1)
    .WillOnce(Return(&discardCard));

    EXPECT_CALL(playerCard, isEight())
    .Times(1)
    .WillOnce(Return(false));

    EXPECT_CALL(playerCard, getRank())
    .Times(1)
    .WillOnce(Return(Rank::Four));

    EXPECT_CALL(discardCard, getRank())
    .Times(1)
    .WillOnce(Return(Rank::Five));

    EXPECT_CALL(playerCard, getSuit())
    .Times(1)
    .WillOnce(Return(Suit::Diamond));

    EXPECT_CALL(discardCard, getSuit())
    .Times(1)
    .WillOnce(Return(Suit::Club));


    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    bool match = game->matchCards(&playerCard);
    EXPECT_FALSE(match);

    delete game;
}

TEST(TestGame, TestSwapDecks) {
    MockDeck discard;
    MockDeck playing;
    MockPlayer player1;
    MockPlayer player2;
    MockCard card;
    MockCard card2;
    Sequence seq_discard_removeTop;
    Sequence seq_discard_getSize;

    Expectation playing_size = EXPECT_CALL(playing, getSize())
    .Times(1)
    .WillOnce(Return(0));

    EXPECT_CALL(discard, getSize())
    .Times(1)
    .InSequence(seq_discard_getSize)
    .WillOnce(Return(26));

    Expectation remove_discard_top = EXPECT_CALL(discard, removeTopCard())
    .Times(1)
    .InSequence(seq_discard_removeTop)
    .After(playing_size)
    .WillOnce(Return(&card));

    EXPECT_CALL(discard, getSize())
    .Times(1)
    .InSequence(seq_discard_getSize)
    .WillOnce(Return(25));


    EXPECT_CALL(discard, removeTopCard())
    .Times(25)
    .InSequence(seq_discard_removeTop)
    .WillRepeatedly(Return(&card2));


    EXPECT_CALL(playing, addToDeck(_))
    .Times(25);

    EXPECT_CALL(discard, addToDeck(_))
    .Times(1)
    .After(remove_discard_top);


    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    game->swapDecks();
    delete game;
}

TEST(TestGame, TestUnableToSwapDecks) {
    MockDeck discard;
    MockDeck playing;
    MockPlayer player1;
    MockPlayer player2;

    Expectation playing_size = EXPECT_CALL(playing, getSize())
    .Times(1)
    .WillOnce(Return(0));

    EXPECT_CALL(discard, getSize())
    .Times(1)
    .After(playing_size)
    .WillOnce(Return(1));

    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    game->swapDecks();
    delete game;
}

TEST(TestGame, TestDetermineWinner) {
    MockDeck discard;
    MockDeck playing;
    MockHand hand1;
    MockHand hand2;
    MockPlayer player1;
    MockPlayer player2;
    MockCard card1;
    MockCard card2;

    EXPECT_CALL(player1, getHand())
    .Times(1)
    .WillOnce(Return(&hand1));

    EXPECT_CALL(hand1, isEmpty())
    .Times(1)
    .WillOnce(Return(false));

    EXPECT_CALL(player2, getHand())
    .Times(1)
    .WillOnce(Return(&hand2));

    EXPECT_CALL(hand2, isEmpty())
    .Times(1)
    .WillOnce(Return(true));


    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    Player* winner = game->determineWinner();
    EXPECT_NE(winner, nullptr);
    delete game;
}

TEST(TestGame, TestDetermineWinnerNoWinner) {
    MockDeck discard;
    MockDeck playing;
    MockHand hand1;
    MockHand hand2;
    MockPlayer player1;
    MockPlayer player2;
    MockCard card1;
    MockCard card2;

    EXPECT_CALL(player1, getHand())
    .Times(1)
    .WillOnce(Return(&hand1));

    EXPECT_CALL(hand1, isEmpty())
    .Times(1)
    .WillOnce(Return(false));

    EXPECT_CALL(player2, getHand())
    .Times(1)
    .WillOnce(Return(&hand2));

    EXPECT_CALL(hand2, isEmpty())
    .Times(1)
    .WillOnce(Return(false));


    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    Player* winner = game->determineWinner();
    EXPECT_EQ(winner, nullptr);
    delete game;
}

TEST(TestGame, TestDealCardsTwoPlayers) {
    MockDeck discard;
    MockDeck playing;
    MockHand hand1;
    MockHand hand2;
    MockPlayer player1;
    MockPlayer player2;

    Expectation shuffle = EXPECT_CALL(playing, shuffleCards())
    .Times(1);

    EXPECT_CALL(player1, getHand())
    .Times(7)
    .WillRepeatedly(Return(&hand1));

    EXPECT_CALL(hand1, addToHand(_))
    .Times(7);

    EXPECT_CALL(player2, getHand())
    .Times(7)
    .WillRepeatedly(Return(&hand2));

    EXPECT_CALL(playing, getSize())
    .Times(14)
    .After(shuffle)
    .WillRepeatedly(Return(14));

    EXPECT_CALL(hand2, addToHand(_))
    .Times(7);


    Expectation remove_top = EXPECT_CALL(playing, removeTopCard())
    .Times(15)
    .WillRepeatedly(Return(new Card(Rank::Five, Suit::Diamond)));


    EXPECT_CALL(discard, addToDeck(_))
    .Times(1)
    .After(remove_top)
    .WillOnce(::testing::DeleteArg<0>());


    std::vector<Player*> players = {&player1, &player2};
    Game* game = new Game(players, &playing, &discard);

    game->dealCards();
    delete game;
}

TEST(TestGame, TestDealCardsThreePlayers) {
    MockDeck discard;
    MockDeck playing;
    MockHand hand1;
    MockHand hand2;
    MockHand hand3;
    MockPlayer player1;
    MockPlayer player2;
    MockPlayer player3;

    Expectation shuffle = EXPECT_CALL(playing, shuffleCards())
    .Times(1);

    EXPECT_CALL(playing, getSize())
    .Times(15)
    .After(shuffle)
    .WillRepeatedly(Return(15));

    EXPECT_CALL(player1, getHand())
    .Times(5)
    .WillRepeatedly(Return(&hand1));

    EXPECT_CALL(player2, getHand())
    .Times(5)
    .WillRepeatedly(Return(&hand2));

    EXPECT_CALL(player3, getHand())
    .Times(5)
    .WillRepeatedly(Return(&hand3));

    EXPECT_CALL(hand1, addToHand(_))
    .Times(5);

    EXPECT_CALL(hand2, addToHand(_))
    .Times(5);

    EXPECT_CALL(hand3, addToHand(_))
    .Times(5);



    Expectation remove_top = EXPECT_CALL(playing, removeTopCard())
    .Times(16)
    .WillRepeatedly(Return(new Card(Rank::Five, Suit::Diamond)));


    EXPECT_CALL(discard, addToDeck(_))
    .Times(1)
    .After(remove_top)
    .WillOnce(::testing::DeleteArg<0>());


    std::vector<Player*> players = {&player1, &player2, &player3};
    Game* game = new Game(players, &playing, &discard);

    game->dealCards();
    delete game;
}

TEST(TestGame, TestCalculatePlayerScoreThreePlayers) {
    MockDeck discard;
    MockDeck playing;
    MockHand hand1;
    MockHand hand2;
    MockHand hand3;
    MockPlayer player1;
    MockPlayer player2;
    MockPlayer player3;
    MockCard card1;
    MockCard card2;


    EXPECT_CALL(player1, getPlayerNumber())
    .Times(4)
    .WillRepeatedly(Return(0));

    EXPECT_CALL(player2, getPlayerNumber())
    .Times(1)
    .WillRepeatedly(Return(1));

    EXPECT_CALL(player3, getPlayerNumber())
    .Times(1)
    .WillRepeatedly(Return(2));


    // Player 2's setup
    EXPECT_CALL(player2, getHand())
    .Times(1)
    .WillOnce(Return(&hand2));

    EXPECT_CALL(hand2, getCards())
    .Times(1)
    .WillOnce(Return(std::vector<Card*>{ &card1, &card1, &card1}));

    EXPECT_CALL(card1, getScore(_))
    .Times(3)
    .WillOnce(Return(5))
    .WillOnce(Return(4))
    .WillOnce(Return(1));


    // Player 3's setup
    EXPECT_CALL(player3, getHand())
    .Times(1)
    .WillOnce(Return(&hand3));

    EXPECT_CALL(hand3, getCards())
    .Times(1)
    .WillOnce(Return(std::vector<Card*> { &card2, &card2, &card2, &card2}));

    EXPECT_CALL(card2, getScore(_))
    .Times(4)
    .WillOnce(Return(50))
    .WillRepeatedly(Return(10));


    EXPECT_CALL(player1, setScore(_))
    .Times(1);


    std::vector<Player*> players = {&player1, &player2, &player3};
    Game* game = new Game(players, &playing, &discard);

    game->calculatePlayerScore(&player1);


    delete game;
}

#endif // TESTGAME_H
