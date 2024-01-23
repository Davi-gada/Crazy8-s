/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include <iostream>
#include <string>
#include <fstream>
#include "UI.h"

UI::UI() {}
UI::~UI() {}

void UI::displayHelp() {
    std::string line;
    std::ifstream myFile;
    myFile.open("text/rules.txt");

    if (myFile.is_open()) {
        while (std::getline(myFile, line)) {
            std::cout << line << '\n';
    }
    myFile.close();
    } else {
        std::cout << "Unable to open file";
    }
}
