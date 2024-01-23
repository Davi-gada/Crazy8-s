/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#pragma once

#include <string>
#include "CardEnumerations.h"

/**
  * The Card class contains the rank and suit of each Card used during a Game.
*/
class Card {
 public:
    /**
     * @brief Default constructor for Card.
    */
    Card();

    /**
     * @brief Constructor for the Card class. This initialized the rank and suit
     * of a card.
     *
     * @param[in] cardRank The rank of the Card
     * @param[in] cardSuit The suit of the Card
     */
    Card(Rank cardRank, Suit cardSuit);

    /**
     * @brief Destructor for the Card class.
     */
    virtual ~Card();

    /**
     * @brief Gets the rank of the Card
     * 
     * @return A Rank enum that indicates the rank of the Card.
     */
    virtual Rank getRank();

    /**
     * @brief Gets the suit of the Card
     * 
     * @return A Suit enum that indicates the suit of the Card.
     */
    virtual Suit getSuit();

    /**
     * @brief Sets the suit of the card when an 8 is played.
     * 
     * @param[in] cardSuit The suit that the current card needs to be set to.
     * 
     * @details When an 8 is played by a player, they are able to set the suit
     * of the next card played. This functions allows the suit of the current
     * top card to be changed, therefore allowing the next card to match the 
     * new suit.
     */
    virtual void setSuit(Suit cardSuit);

    /**
     * @brief Checks if the rank of the card is 8.
     *  
     * @return Returns true if the rank is 8. Returns false otherwise
     */
    virtual bool isEight();

    /**
     * @brief Returns the score of a particular card.
    */
    virtual int getScore(Rank r);

    virtual std::string rankToString();
    virtual std::string suitToString();

 private:
    Suit suit;
    Rank rank;
};
