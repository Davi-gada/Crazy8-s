/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef HUMAN_H_
#define HUMAN_H_

#include <string>
#include "Player.h"

/**
 * A class representing the human player. Inherits from Player and encapsulates
 * behaviour of a human player.
*/
class Human : public Player{
 public:
    /**
     * @brief Default constructor for Human class.
    */
    Human();

    /**
     * Constructor
     * Requires the players name, score, and a pointer to their hand
     * @param name the players name
     * @param playerNumber the player number of the human player.
     * @param hand pointer to the players hand
     */
    Human(std::string name, int playerNumber, Hand* hand);

    /**
     * A Destructor for the Human class.
    */
    virtual ~Human();
};
#endif
