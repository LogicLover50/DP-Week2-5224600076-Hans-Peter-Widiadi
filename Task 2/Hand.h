#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand {
public:
    void AddCards(const std::vector<Card>& cards);
    void Clear();

    const std::vector<Card>& GetCards() const;
    int Size() const;
    void Print() const;

private:
    std::vector<Card> cards_;
};

#endif
