/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef CI_H_
#define CI_H_

#include <string>
#include "Player.h"

enum CIStrategy {
    PlaySameRank,
    PlaySameSuit,
};

/**
 * A class representing the computer intelligence. Inherits from Player and 
 * encapsulates behaviour of a CI player.
*/
class CI : public Player {
 public:
    /**
     * @brief Default constructor for CI
    */
    CI();

    /**
    * Constructor
    * Requires the players name, score, and a pointer to their hand
    * @param name the players name.
    * @param playerNumber the player number of the CI player.
    * @param hand pointer to the players hand.
    */
    CI(std::string name, int playerNumber, Hand* hand);

    /**
     * A destructor for the CI
    */
    virtual ~CI();

    /**
     * @brief Sets the strategy that the CI is going to follow in each turn
     * 
     * @param[in] strategy The strategy that is set for this CI player.
    */
    virtual void setStrategy(CIStrategy strategy1);

    /**
     * @brief Returns the current strategy of the CI player
     * 
     * @return The strategy that is followed by this CI player.
    */
    virtual CIStrategy getStrategy();

 private:
    CIStrategy strategy;
};



#endif /* CI_H_ */
