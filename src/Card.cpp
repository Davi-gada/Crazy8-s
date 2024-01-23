/**
 * @author Crazy-8 groups
 * @date 2023-02
*/

#include "Card.h"

Card::Card() {
    suit = Suit::Club;
    rank = Rank::Ace;
}

Card::Card(Rank cardRank, Suit cardSuit): suit{cardSuit}, rank{cardRank} {}

Card::~Card() {
}

Rank Card::getRank() {
    return rank;
}

Suit Card::getSuit() {
    return suit;
}

void Card::setSuit(Suit cardSuit) {
    suit = cardSuit;
}

bool Card::isEight() {
    if (rank == Rank::Eight)
        return true;
    else
        return false;
}

int Card::getScore(Rank r) {
    switch (r) {
        case Rank::Ace:
            return 1;
        case Rank::Two:
            return 2;
        case Rank::Three:
            return 3;
        case Rank::Four:
            return 4;
        case Rank::Five:
            return 5;
        case Rank::Six:
            return 6;
        case Rank::Seven:
            return 7;
        case Rank::Eight:
            return 50;
        case Rank::Nine:
            return 9;
        case Rank::Ten:
            return 10;
        case Rank::Jack:
            return 10;
        case Rank::Queen:
            return 10;
        case Rank::King:
            return 10;
        default:
            return -99;
    }
}

std::string Card::rankToString() {
    Rank r = getRank();
    switch (r) {
        case 1:
            return "Ace";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        default:
            return "no";
    }
}

std::string Card::suitToString() {
    Suit s = getSuit();
    switch (s) {
        case 0:
            return "Clubs";
        case 1:
            return "Diamonds";
        case 2:
            return "Hearts";
        case 3:
            return "Spades";
        default:
            return "no";
    }
}
