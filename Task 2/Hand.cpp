#include "Hand.h"
#include <iostream>

void Hand::AddCards(const std::vector<Card>& cards) {
    for (const auto& c : cards)
        cards_.push_back(c);
}

void Hand::Clear() {
    cards_.clear();
}

const std::vector<Card>& Hand::GetCards() const {
    return cards_;
}

int Hand::Size() const {
    return static_cast<int>(cards_.size());
}

void Hand::Print() const {
    for (const auto& c : cards_)
        std::cout << c.ToString() << " ";
    std::cout << "\n";
}
