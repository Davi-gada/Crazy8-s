#include "Game.h"
#include "UI.h"
#include "Player.h"
#include "Human.h"
#include "CI.h"
#include "TurnUI.h"
#include "StartGameUI.h"
#include "EndGameUI.h"
#include "EndGameUI.h"

int main() {
    StartGameUI* ui = new StartGameUI();
    std::vector<Player*> players;
    Deck* discard = new Deck();
    Deck* draw = new Deck();

    ui->display();
    int x = ui->getNumCIPlayers();
    int y = ui->getNumHumanPlayers();
    //if (x + y < 2 && x + y > 6)
      //  std::cout << "You must have at least 2 player and at most 6." << '\n';
        //return 0;
    draw->createPlayingDeck();
    draw->shuffleCards();
    discard->addToDeck(draw->removeTopCard());
    for (int i = 0; i < y; i++) {
        players.push_back(new Human("Player", i+1, new Hand()));
    }
    for (int i = 0; i < x; i++) {
        players.push_back(new CI("CI", i+1, new Hand()));
    }

    Game* game = new Game(players, draw, discard);
    TurnUI* turnUI = new TurnUI(players[0], discard, draw);
    ui->displayHelp();
    game->setUI(turnUI);
    Player* winner = game->playGame();
    game->endGame(winner);
    return 0;
}

