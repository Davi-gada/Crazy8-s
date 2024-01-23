/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#ifndef ENDGAMEUI_H
#define ENDGAMEUI_H

#include <iostream>
#include <vector>
#include "UI.h"
#include "Player.h"

/**
 * Displays the UI that contains elements that show when the game ends.
*/
class EndGameUI : public UI {
 public:
    /**
     * @brief Default constructor for EndGameUI
    */
    EndGameUI();

    /**
     * @brief Default destructor for EndGameUI
    */
    ~EndGameUI();
    /**
     * @brief Displays the elements of the end game ui to the user.
    */
    virtual void display();

    /**
     * @brief Displays the scores of all the players at the end of a game
    */
    virtual void displayScores(std::vector<Player*> players);

    /**
     * @brief Displays the winner of the game and other related elements.
    */
    virtual void displayWinner(Player* player);
};

#endif // ENDGAMEUI_H
