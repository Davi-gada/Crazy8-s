/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include "StartGameUI.h"
#include <fstream>

StartGameUI::StartGameUI() {
}

void StartGameUI::display() {
    std::string line;
    std::ifstream myFile;
    myFile.open("text/start.txt");

    if (myFile.is_open()) {
        while (std::getline(myFile, line)) {
            std::cout << line << '\n';
    }
    myFile.close();
    } else {
        std::cout << "Unable to open file";
    }

    int choice;
    std::cout << "Enter the your choice: ";
    std::cin >> choice;
    switch (choice) {
    case (1):
    {
        int playerNum, ciNum;
        std::cout <<" Enter the number of human players: ";
        std::cin >> playerNum;
        std::cout << std::endl;

        std::cout << " Enter the number of Ci players: ";
        std::cin >> ciNum;
        std::cout << std::endl;

        numCIPlayers = ciNum;
        numHumanPlayers = playerNum;
    }
    break;
    case (2):
    {
        displayHelp();
    }
    break;
    case (0):
    {
        std::cout << "Game exit" << std::endl;
        exit(0);
    }
    default:
    {
        std::cout << " Please enter valid input." << std::endl;
    }
  }
}

int StartGameUI::getNumCIPlayers() {
    return numCIPlayers;
}

int StartGameUI::getNumHumanPlayers() {
    return numHumanPlayers;
}

