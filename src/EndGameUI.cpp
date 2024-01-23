/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include "EndGameUI.h"

EndGameUI::EndGameUI() {
}

EndGameUI::~EndGameUI() {
    delete this;
}

void EndGameUI::display() {
  std::cout << "======== Game Over ========" << std::endl;
  std::cout << "======== Thanks for playing ========" << std::endl;
}

void EndGameUI::displayScores(std::vector<Player*> players) {
    std::cout<< "Scores: " << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player " << players.at(i)->getName() << ": "
        << players.at(i)->getScore() << std::endl;
    }
}


void EndGameUI::displayWinner(Player* player) {
  std::cout << "========== Congratulations!!! ==========" << std::endl;
  std::cout <<  "The Winner is " << player->getName() << std::endl;
}

