#ifndef CARD_H
#define CARD_H

#include <string>

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank { Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
public:
    Card(Rank rank, Suit suit);

    Rank GetRank() const;
    Suit GetSuit() const;
    int  GetChipValue() const;   // base chip value of this card
    std::string ToString() const;

private:
    Rank rank_;
    Suit suit_;
};

#endif
