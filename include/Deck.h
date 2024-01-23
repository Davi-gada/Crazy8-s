/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#pragma once

#include <vector>
#include "Card.h"

/**
 * A class representing a Deck. A deck is used to represent both stock and 
 * discard piles in the game.
*/
class Deck {
 public:
    /**
     * Default constructor for a deck.
    */
    Deck();

    /**
     * @brief Constructor for the Deck class. This initializes the cards
     * in the Deck object.
     *
     * @param[in] cards The vector of Cards for the Deck object.
     */
    Deck(std::vector<Card*> cards);

    /**
     * @brief Destructor for the Deck class.
     */
    virtual ~Deck();

    /**
     * @brief Gets the top Card of the Deck.
     * 
     * @return A pointer to a Card that is at the top of the deck.
     */
    virtual Card* getTopCard();

    /**
     * @brief Shuffles the Cards in the Deck
     */
    virtual void shuffleCards();

    /**
     * @brief Adds a Card to the Deck, as long as it is a valid card.
     *
     * @param[in] card The Card to be added to the Deck
     */
    virtual void addToDeck(Card* card);

    /**
     * @brief Removes the top card from the Deck.
     * 
     * @return Returns a pointer to the card that is removed from the top of
     * the Deck.
    */
    virtual Card* removeTopCard();

    /**
     * @brief Returns the size of the Deck.
     * 
     * @return The current size of the Deck.
     */
    virtual int getSize();

    /**
     * @brief Creates the playing deck
    */
    void createPlayingDeck();

 private:
    std::vector<Card*> deckCards;
};
