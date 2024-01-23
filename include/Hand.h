/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#pragma once

#include <vector>
#include "Card.h"

/**
 * A class that represent's a player's hand. Contains methods that manipulate
 * the cards in a player's hand.
*/
class Hand {
 public:
    /**
     * @brief Default constructor for Hand class.
    */
    Hand();

    /**
     * @brief Constructor for the Hand class. This initializes the cards
     * in the Hand object.
     *
     * @param[in] cards A vector containing the cards in a player's hand.
     */
    Hand(std::vector<Card*> cards);

    /**
     * @brief Destructor for the Hand class.
     */
    virtual ~Hand();

    /**
     * @brief Gets the cards in the Hand of a player.
     * 
     * @return A vector containing the cards in a player's hand.
     */
    virtual std::vector<Card*> getCards();

    /**
     * @brief Adds a Card to the Hand, as long as n_card is a valid
     * card pointer.
     *
     * @param[in] card The Card to the added to the Hand
     */
    virtual void addToHand(Card* card);

    /**
     * @brief Removes a Card from the Hand, as long as card is a valid
     * card pointer.
     *
     * @param[in] card The Card to the removed from the Hand
     * 
     * @return A Card* pointing to the card removed from a player's hand. If the card
     *  doesn't exist in the player's hand, return nullptr.
     */
    virtual Card* removeFromHand(int cardIndex);

    /**
     * @brief Sorts the cards in the hand of the player
    */
    virtual void sortHand();

    /**
     * @brief Checks if the hand is empty.
     * 
     * @return A boolean indicating if the hand is empty or not. Returns true 
     * if hand is empty. Return false if there are cards still in the hand.
    */
    virtual bool isEmpty();

    /**
     * @brief Gets the size of the player's hand.
     * 
     * @return Returns an integer indicating the number of cards in the player's
     * hand.
    */
    virtual int getHandSize();

    /**
     * @brief Finds a card in the player's hand based on the card's rank.
     * 
     * @param[in] rank The rank of the card to find.
     * 
     * @return Returns an integer that indicates the index of the first card 
     * in the hand of the player that matches the rank. If no match is found,
     * returns -1.
    */
    virtual int findCard(Rank rank);

    /**
     * @brief Finds a card in the player's hand based on the card's suit.
     * 
     * @param[in] suit The suit of the card to find.
     * 
     * @return Returns an integer that indicates the index of the first card 
     * in the hand of the player that matches the suit. If no match is found,
     * returns -1.
    */
    virtual int findCard(Suit suit);

    /**
     * @brief Get a Card from the Hand, as long as card is a valid
     * card pointer.
     *
     * @param[in] card The Card from the player's Hand.
     *
     * @return A Card* pointing to the card from a player's hand.
     */
    virtual Card* getFromHand(int cardIndex);


 private:
    std::vector<Card*> cardsInHand;
    int handSize;
    bool empty;
};
