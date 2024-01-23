/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Hand.h"

/**
 * A class representing behaviour of a player in Crazy-8. The class contains
 * information regarding a player.
*/
class Player {
 public:
    /**
     * @brief Default constructor for Player
    */
    Player();
    /**
     * Constructor
     * Requires the players name, score, and a pointer to their hand
     * @param pname the players name
     * @param playerNum the number denoting the player
     * @param hand pointer to the players hand
     */
    Player(std::string pname, int playerNum, Hand* hand);

    /**
     * A destructor for the player class.
     */
    virtual ~Player();

    /**
     * Returns the players hand
     * @return a pointer to the players hand
     */
    virtual Hand* getHand();

    /**
     * @brief Returns an integer with the players score
     * @return the players score as an integer
     */
    virtual int getScore();

    /**
     * @brief returns the player's name
     * @return the player's name
     */
    virtual std::string getName();

    /**
     * @brief Sets the score of the player. This method changes a player's
     * current score based on the value passed to the method.
     * @param pscore the amount that the score is to be changed by.
     */
    virtual void setScore(int pscore);

    /**
     * @brief Returns the number denoting the current player. This is used to
     * track the identity/id of a player.
     *
     * @return Returns an integer indicating the player's number.
     */
    virtual int getPlayerNumber();

    /**
     * @brief Toggles a boolean that indicates whether the current player is a
     * human or CI player.
     *
     * @param[in] human A boolean flag that sets whether a player is a human
     * player.
     */
    virtual void setPlayerType(bool human);

    /**
     * @brief Checks whether the current player is a human player.
     *
     * @return A boolean value indicating whether the current player is a human
     * player. Returns true if the player is human, returns False if the player
     * is a CI.
     */
    virtual bool isHumanPlayer();

 private:
    std::string name;
    int score;
    Hand* playerHand;
    bool humanPlayer;
    int playerNumber;
};

#endif /* PLAYER_H_ */
