/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef STARTGAMEUI_H
#define STARTGAMEUI_H

#include <iostream>
#include "UI.h"

/**
 * Displays the UI that contains elements for a game/round.
*/
class StartGameUI : public UI {
 public:
    /**
     * @brief Default constructor for StartGameUI class.
    */
    StartGameUI();

    /**
     * @brief Contains the UI elements that are to be displayed to the user
     * when a game is started.
    */
    virtual void display();

    /**
     * @brief Returns the number of Computer Intelligence players playing the
     * game.
     * 
     * @return A number indicating the amount of CI/AI players.
    */
    virtual int getNumCIPlayers();

    /**
     * @brief Returns the number of Human players playing the
     * game.
     * 
     * @return A number indicating the amount of human players playing the
     * game.
    */
    virtual int getNumHumanPlayers();

 private:
    int numCIPlayers = 0;
    int numHumanPlayers = 0;
};


#endif // STARTGAMEUI_H
