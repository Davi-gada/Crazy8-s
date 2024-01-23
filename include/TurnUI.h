/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef TURNUI_H
#define TURNUI_H

#include <iostream>
#include <string>
#include "UI.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"

enum Action {
    PlayCard,
    DrawCard,
    SortHand,
    GetHelp,
    QuitGame
};

/**
 * Displays the UI that contains elements for a turn.
*/
class TurnUI : public UI {
 public:
    /**
     * @brief Default constructor for TurnUI class.
    */
    TurnUI();

    /**
    * @brief The constructor for the TurnUI class.
     * 
     * @param[in] currentPlayer The current player who has to play a turn.
     * @param[in] discard The discard deck that a player will be interacting
     * with.
     * @param[in] playing The playing deck that a player will be interacting
     * with.
    */
    TurnUI(Player* currentPlayer, Deck* discard, Deck* playing);

    /**
     * @brief Destructor for the TurnUI class.
    */
    virtual ~TurnUI();

    /**
     * @brief Displays the general elements of the turn ui to the user. This
     * is what the user first sees when its their turn.
    */
    virtual void display();

        /**
     * @brief Asks the user for a card that they want to play from their hand.
     * 
     * @returns Returns the index of the card the user wants to play.
    */
    virtual int getPlayedCardIndex();

    /**
     * @brief Takes input from the user to get their choice for their turn.
     * 
     * @return A string denoting the turn choice of the player.
    */
    virtual Action getPlayerAction();

    /**
     * @brief A method that displays a message when an invalid input is
     * entered by the player.
     * @param[in] error The error message displayed to the player.
    */
    virtual void invalidInput(std::string error);

    /**
     * @brief Prompts the user to set a new suit if an eight is played
    */
    virtual Suit setCardSuitPrompt();

    /**
     * @brief Displays UI elements for when a player decides to quit a game
     * during their turn.
    */
    virtual void displayQuit();

    /**
     * @brief Displays the UI elements for when the player decides to draw a
     * card from the deck.
    */
    virtual void displayDrawCard();

    /**
     * @brief Displays the UI elements for when decks are swapped after
     * the playing deck runs out of cards.
    */    
    virtual void displaySwapDecks();

    /**
     * @brief Displays the UI element for when the player decides to sort their
     * hand.
    */
    virtual void displaySortHand();

    /**
     * @brief Displays the player's hand.
    */
    virtual void displayHand();

 private:
    Player* currentPlayer;
    Deck* discardDeck;
    Deck* playingDeck;
    Action action;
};


#endif // TURNUI_H
