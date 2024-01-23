/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include "TurnUI.h"

TurnUI::TurnUI() {
    currentPlayer = nullptr;
    discardDeck = nullptr;
    playingDeck = nullptr;
}

TurnUI::TurnUI(Player* currentPlayer1, Deck* discard, Deck* play) {
    currentPlayer = currentPlayer1;
    discardDeck = discard;
    playingDeck = play;
}

TurnUI::~TurnUI() {}

void TurnUI::display() {
    Card* c = discardDeck->getTopCard();
    std::string Rank = c->rankToString();
    std::string Suit = c->suitToString();

    std::cout << "==============================" << std::endl;
    std::cout << "Player " << currentPlayer->getPlayerNumber()
              << " turn" << std::endl;
    std::cout << "==============================" << std::endl;

    for (int i = 0; i < currentPlayer->getHand()->getCards().size(); i++) {
        std::cout << i << ": "
                  << currentPlayer->getHand()->getCards().at(i)->rankToString()
                  << " of "
                  << currentPlayer->getHand()->getCards().at(i)->suitToString()
        << std::endl;
    }
    std::cout << "==============================" << std::endl;
    std::cout << "Discard Pile: " << Rank << " of " << Suit << std::endl;
    std::cout << "==============================" << std::endl;
}

Action TurnUI::getPlayerAction() {
    display();
    std::cout << "Enter 1 to PlayCard!" << std::endl;
    std::cout << "Enter 2 to DrawCard!" << std::endl;
    std::cout << "Enter 3 to SortHand!" << std::endl;
    std::cout << "Enter 4 to GetHelp!" << std::endl;
    std::cout << "Enter 5 to QuitGame!" << std::endl;
    int input;
    std::cin >> input;
    switch (input) {
        case 1:
            return Action::PlayCard;
        case 2:
            return Action::DrawCard;
        case 3:
            return Action::SortHand;
        case 4:
            return Action::GetHelp;
        case 5:
            return Action::QuitGame;
        default:
            invalidInput("Invalid input. Select Numbers 1-5");
    }
}

void TurnUI::invalidInput(std::string error) {
    std::cout << error << std::endl;
}

Suit TurnUI::setCardSuitPrompt() {
    std::cout << "What suit would you like: "
              << std::endl
              << "Press 1 for Clubs!"
              << std::endl
              << "Press 2 for Diamonds!"
              << std::endl
              << "Press 3 for Hearts!"
              << std::endl
              << "Press 4 for Spades!" << std::endl;
    int input;
    std::cin >> input;
    switch (input) {
        case 1:
            return Suit::Club;
        case 2:
            return Suit::Diamond;
        case 3:
            return Suit::Heart;
        case 4:
            return Suit::Spade;
        default:
            invalidInput("Invalid input. Select Numbers 1-4");
    }
}

int TurnUI::getPlayedCardIndex() {
    displayHand();
    int index = 0;
    std::cout << "Choose the index of the card you wish to play: ";
    std::cin >> index;
    return index;
}

void TurnUI::displayQuit() {
    std::cout << "==============================" << std::endl;
    std::cout << "Quitting the game............" << std::endl;
    std::cout << "==============================" << std::endl;
    exit(0);
}

void TurnUI::displayDrawCard() {
    std::cout << "==============================" << std::endl;
    std::cout << "You have drawn a card: " << std::endl;
    std::cout << "==============================" << std::endl;
}

void TurnUI::displaySwapDecks() {
    std::cout << "==============================" << std::endl;
    std::cout << "Play deck is empty, Swapping decks" << std::endl;
    std::cout << "==============================" << std::endl;
}

void TurnUI::displaySortHand() {
    std::cout << "Sorting the hand.........." << std::endl;
}

void TurnUI::displayHand() {
    std::cout << "==============================" << std::endl;
    std::cout << currentPlayer->getName()
              << currentPlayer->getPlayerNumber()
              << "'s hand: " << std::endl;
    std::cout << "==============================" << std::endl;
    for (int i = 0; i < currentPlayer->getHand()->getCards().size(); i++) {
        std::cout << i << ": "
       << currentPlayer->getHand()->getCards().at(i)->rankToString() << " of "
       << currentPlayer->getHand()->getCards().at(i)->suitToString()
       << std::endl;
    }

    Card* c = discardDeck->getTopCard();
    std::string Rank = c->rankToString();
    std::string Suit = c->suitToString();
    std::cout << "Discard Pile: " << Rank << " of " << Suit << std::endl;
    std::cout << "==============================" << std::endl;
}
