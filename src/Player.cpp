/**
 * @author Crazy-8 groups
 * @date 2023-02
*/


#include <string>
#include "Player.h"
#include "Hand.h"

Player::Player() {}

Player::Player(std::string pname, int playerNum, Hand* hand) {
  name = pname;
  playerNumber = playerNum;
  playerHand = hand;
  score = 0;
}

Player::~Player() {}

Hand* Player::getHand() {
  return playerHand;
}

int Player::getScore() {
  return score;
}

std::string Player::getName() {
  return name;
}

void Player::setScore(int pscore) {
  score = pscore;
}

int Player::getPlayerNumber() {
  return playerNumber;
}

void Player::setPlayerType(bool human) {
  humanPlayer = human;
}

bool Player::isHumanPlayer() {
  return humanPlayer; // true for human, false for Ai
}
