/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "UI.h"
#include "Deck.h"
#include "Player.h"

/**
 * The Game class contains the central logic of the game. The class deals
 * with starting a game, setting UIs and ending the game.
*/
class Game {
 public:
    /**
     * @brief Constructor for the Game class. This sets the game based 
     * on the the number of players currently in the game.
     * 
     * @param[in] players The players that will be taking part in the game.
    */
    Game(std::vector<Player*> players, Deck* playing, Deck* discard);

    /**
     * @brief Destructor for the game class.
    */
    virtual ~Game();

    /**
     * @brief Sets the UI that will be displayed to the player.
     * 
     * @param[in] ui The ui that will be shown to the player.
    */
    void setUI(UI* ui);

    /**
     * @brief Starts the game of Crazy 8. Contains the main gameplay 
     * loop for the game.
     * 
     * @return A pointer to the player that has won the game.
    */
    Player* playGame();

    /**
     * @brief Encapsulates events regarding the game ending. Displays, the
     * final scores and the winner of the game.
     * 
     * @param[in] winningPlayer A pointer to the player that won the game.
     * 
    */
    void endGame(Player* winningPlayer);

    /**
     * @brief Check if the game is over
     * 
     * @return A boolean indicating whether the game is over. Returns true if
     * there is a player with an empty hand, false otherwise.
    */
    bool isGameOver();

    /**
     * @brief A method that encapsulates logic for a human player's turn.
    */
    bool playHumanTurn();

    /**
     * @brief A method that encapsulates logic for a CI player's turn.
    */
    void playCITurn();

    /**
     * @brief Determines whether the card played matches the suit or rank
     * of the top card in the discard deck.
     * 
     * @details This methods allows us to match a card played with the card that
     * is currently on top of the discard pile. A match is valid when the card
     * played has the same suit or rank to the top card in the discard pile. A
     * match is invalid when the suit or rank of the played card are not
     * similar.
     *
     * @param[in] playerCard The card played by the player.

     * @return A boolean value showing whether the 2 cards match
    */
    bool matchCards(Card* playerCard);

    /**
     * @brief Swaps the discard pile with the stock pile when the stock pile 
     * runs out.
     * 
     * @details The method is used to handle the situation where the stock
     * pile runs out during the game. In this situation, we turn the 
     * discard/played pile into the stock pile but keep the top card of the
     * discard pile intact. The remaining cards are shuffled and turned into 
     * stock.
    */
    void swapDecks();

    /***
     * @brief Determines the winner of the game. The function finds the winner
     * of the game is.
     * 
     * @return Returns a pointer to the player if someone has won the game. If
     * no one has won the game yet, returns a nullptr.
    */
    Player* determineWinner();

    /**
     * @brief Deals the cards to the players.
    */
    void dealCards();

    /**
     * @brief Calculates the scores 
    */
    void calculatePlayerScore(Player* winningPlayer);

 private:
    std::vector<Player*> gamePlayers;
    Deck* discardDeck;
    Deck* playingDeck;
    UI* currentUI;
    Player* currentPlayer;
};

#endif // GAME_H
