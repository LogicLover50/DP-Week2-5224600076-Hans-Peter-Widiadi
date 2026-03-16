#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
public:
    Deck();                          // builds a standard 52-card deck
    void Shuffle();
    std::vector<Card> Draw(int n);   // draw n cards from the top
    void AddCard(const Card& card);  // used by ShopSystem to add bought cards
    int  Size() const;

private:
    std::vector<Card> cards_;
};

#endif
