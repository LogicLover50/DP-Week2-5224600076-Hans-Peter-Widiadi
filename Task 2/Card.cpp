#include "Card.h"

Card::Card(Rank rank, Suit suit)
    : rank_(rank), suit_(suit) {}

Rank Card::GetRank() const { return rank_; }
Suit Card::GetSuit() const { return suit_; }

int Card::GetChipValue() const {
    int r = static_cast<int>(rank_);
    if (r >= 2 && r <= 9)  return r;       // 2–9 → face value
    if (r == 10)           return 10;      // Ten
    if (r <= 13)           return 10;      // Jack, Queen, King
    return 11;                             // Ace
}

std::string Card::ToString() const {
    std::string rankStr;
    switch (rank_) {
        case Rank::Two:   rankStr = "2";  break;
        case Rank::Three: rankStr = "3";  break;
        case Rank::Four:  rankStr = "4";  break;
        case Rank::Five:  rankStr = "5";  break;
        case Rank::Six:   rankStr = "6";  break;
        case Rank::Seven: rankStr = "7";  break;
        case Rank::Eight: rankStr = "8";  break;
        case Rank::Nine:  rankStr = "9";  break;
        case Rank::Ten:   rankStr = "10"; break;
        case Rank::Jack:  rankStr = "J";  break;
        case Rank::Queen: rankStr = "Q";  break;
        case Rank::King:  rankStr = "K";  break;
        case Rank::Ace:   rankStr = "A";  break;
    }

    std::string suitStr;
    switch (suit_) {
        case Suit::Hearts:   suitStr = "H"; break;
        case Suit::Diamonds: suitStr = "D"; break;
        case Suit::Clubs:    suitStr = "C"; break;
        case Suit::Spades:   suitStr = "S"; break;
    }

    return rankStr + suitStr;
}
