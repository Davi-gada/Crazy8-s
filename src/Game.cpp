/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include "Game.h"
#include "Player.h"
#include "CI.h"
#include "EndGameUI.h"
#include "StartGameUI.h"
#include "TurnUI.h"

const int CARDS_TWO_PLAYERS = 7;
const int CARDS_THREE_OR_MORE_PLAYERS = 5;

Game::Game(std::vector<Player*> players, Deck* playing, Deck* discard) :
gamePlayers{players}, playingDeck{playing}, discardDeck{discard} { }

Game::~Game() {}


void Game::setUI(UI* ui) {
    currentUI = ui;
}

Player* Game::playGame() {
    dealCards();
    bool gameOver = false, playerDone = false;
    while (!gameOver && !playerDone) {
        for (std::vector<Player*>::iterator player = gamePlayers.begin();
        player != gamePlayers.end(); ++player) {
            currentPlayer = (*player); // set the current player
            bool human = (*player)->isHumanPlayer(); // check status of player
            if (human) {
                playerDone = playHumanTurn();
            } else {
                playCITurn();
            }

            gameOver = isGameOver();
            if (gameOver) {
                Player* winningPlayer = determineWinner();
                return winningPlayer;
            }
            }
        }


    Player* winningPlayer = determineWinner();
    return winningPlayer;
}

void Game::endGame(Player* winningPlayer) {
    EndGameUI* endGameUI = static_cast<EndGameUI*>(currentUI);
    endGameUI->display();
    calculatePlayerScore(winningPlayer);
    endGameUI->displayScores(gamePlayers);
    endGameUI->displayWinner(winningPlayer);
}

bool Game::playHumanTurn() {
    Hand* playerHand = currentPlayer->getHand();
    TurnUI* turnUI = static_cast<TurnUI*>(currentUI);

    bool cardPlayed = false, quit = false;
    while (!cardPlayed && !quit) {
        if (playerHand->isEmpty()) {
            quit = true;
            cardPlayed = true;
        }
        Action playerAction = turnUI->getPlayerAction();
        switch (playerAction) {
            case Action::PlayCard: {
                int cardIndex = turnUI->getPlayedCardIndex();
                Card* playerCard = playerHand->removeFromHand(cardIndex);


                if (playerCard == nullptr) {
                    turnUI->invalidInput("Card not in hand. Try again");
                    playerHand->addToHand(playerCard);
                    break;
                }
                if (matchCards(playerCard) == false) {
                    turnUI->invalidInput("Not a match. Try again");

                    playerHand->addToHand(playerCard);
                    break;
                }
                    discardDeck->addToDeck(playerCard);

                 if (playerCard->isEight()) {
                    Suit newSuit = turnUI->setCardSuitPrompt();
                    playerCard->setSuit(newSuit);
                }
                cardPlayed = true;
                break;
            }

            case Action::DrawCard: {
                turnUI->displayDrawCard();
                if (playingDeck->getSize() == 0) {
                    turnUI->displaySwapDecks();
                    swapDecks();
                }
                Card* drawnCard = playingDeck->removeTopCard();
                playerHand->addToHand(drawnCard);

                turnUI->displayHand();
                break;
            }
            case Action::SortHand: {
                turnUI->displaySortHand();
                playerHand->sortHand();
                turnUI->displayHand();
                break;
            }
            case Action::GetHelp: {
                turnUI->displayHelp();
                break;
            }
            case Action::QuitGame: {
                turnUI->displayQuit();
                quit = true;
                break;
            }
        }
    }
    return quit;
}

void Game::playCITurn() {
    CIStrategy strategy = static_cast<CI*>(currentPlayer)->getStrategy();
    TurnUI* turnUI = static_cast<TurnUI*>(currentUI);

    Hand* hand = currentPlayer->getHand();
    Card* topDiscardPileCard = discardDeck->getTopCard();
    int cardToPlayIndex;

    if (strategy == CIStrategy::PlaySameRank) {
        Rank topDiscardCardRank = topDiscardPileCard->getRank();
        cardToPlayIndex = hand->findCard(topDiscardCardRank);

        if (cardToPlayIndex < 0) {
            bool foundAfterDraw;
            do {
                if (playingDeck->getSize() == 0) {
                    turnUI->displaySwapDecks();
                    swapDecks();
                }
                Card* drawnCard = playingDeck->removeTopCard();
                hand->addToHand(drawnCard);

                if (drawnCard->getRank() == topDiscardCardRank) {
                    foundAfterDraw = true;
                    cardToPlayIndex = hand->findCard(topDiscardCardRank);
                }
            } while (!foundAfterDraw);
        }
    } else {
        Suit topDiscardCardSuit = topDiscardPileCard->getSuit();
        cardToPlayIndex = hand->findCard(topDiscardCardSuit);

        if (cardToPlayIndex < 0) {
            bool foundAfterDraw;
            do {
                if (playingDeck->getSize() == 0) {
                    turnUI->displaySwapDecks();
                    swapDecks();
                }
                Card* drawnCard = playingDeck->removeTopCard();
                hand->addToHand(drawnCard);

                if (drawnCard->getSuit() == topDiscardCardSuit) {
                    foundAfterDraw = true;
                    cardToPlayIndex = hand->findCard(topDiscardCardSuit);
                }
            } while (!foundAfterDraw);
        }
    }
    Card* cardToPlay = hand->removeFromHand(cardToPlayIndex);
    discardDeck->addToDeck(cardToPlay);
}

bool Game::matchCards(Card* playerCard) {
    Card* discardPileTopCard = discardDeck->getTopCard();
    if (playerCard->isEight()) {
        return true;
    } else if (playerCard->getRank() == discardPileTopCard->getRank()) {
        return true;
    } else if (playerCard->getSuit() == discardPileTopCard->getSuit()) {
        return true;
    } else {
        return false;
    }
}

void Game::swapDecks() {
    if (playingDeck->getSize() == 0 &&
        discardDeck->getSize() > 1) {
        Card* previousTopCard = discardDeck->removeTopCard();
        int numCards = discardDeck->getSize();
        for (int i = 0; i < numCards; i++) {
            Card* card = discardDeck->removeTopCard();
            playingDeck->addToDeck(card);
        }
        discardDeck->addToDeck(previousTopCard);
    }
}

bool Game::isGameOver() {
    Player* winningPlayer = determineWinner();
    if (winningPlayer == nullptr) {
        return false;
    }
    return true;
}

Player* Game::determineWinner() {
    for (std::vector<Player*>::iterator player = gamePlayers.begin();
        player != gamePlayers.end(); ++player) {
        Hand* playerHand = (*player)->getHand();
        if (playerHand->isEmpty()) {
            return (*player);
        }
    }
    return nullptr;
}

void Game::dealCards() {
    int numPlayers = gamePlayers.size();
    int cardsPerPlayer = numPlayers == 2 ?
    CARDS_TWO_PLAYERS : CARDS_THREE_OR_MORE_PLAYERS;

    playingDeck->shuffleCards();

    for (int i = 0; i < cardsPerPlayer; i++) {
        for (int j = 0; j < numPlayers; j++) {
            currentPlayer = gamePlayers[j];
            Hand* playerHand = currentPlayer->getHand();
            if (playingDeck->getSize() > 1) {
                playerHand->addToHand(playingDeck->removeTopCard());
            }
        }
    }

    discardDeck->addToDeck(playingDeck->removeTopCard());
}

void Game::calculatePlayerScore(Player* winningPlayer) {
    int winningScore = 0;

    for (std::vector<Player*>::iterator player = gamePlayers.begin();
        player != gamePlayers.end(); ++player) {
            if ((*player)->getPlayerNumber() !=
                winningPlayer->getPlayerNumber()) {
                Hand* playerHand = (*player)->getHand();

                std::vector<Card*> cardsInHand = playerHand->getCards();

                for (size_t i = 0; i < cardsInHand.size(); i++) {
                    Card* card = cardsInHand[i];
                    winningScore += card->getScore(card->getRank());
                }
            }
    }
    winningPlayer->setScore(winningScore);
}
