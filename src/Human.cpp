/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include <string>
#include "Human.h"
#include "Hand.h"

Human::Human() {}

Human::Human(std::string name, int playerNumber, Hand* hand):
    Player(name, playerNumber, hand) {}

Human::~Human() {}
