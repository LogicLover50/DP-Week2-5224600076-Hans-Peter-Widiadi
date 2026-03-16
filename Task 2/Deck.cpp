#include "Deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck() {
    // Build a standard 52-card deck
    for (Suit suit : { Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades }) {
        for (int r = 2; r <= 14; ++r) {
            cards_.emplace_back(static_cast<Rank>(r), suit);
        }
    }
}

void Deck::Shuffle() {
    std::mt19937 rng(std::random_device{}());
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

std::vector<Card> Deck::Draw(int n) {
    if (n > static_cast<int>(cards_.size())) {
        n = static_cast<int>(cards_.size()); // draw whatever is left
    }
    std::vector<Card> drawn(cards_.end() - n, cards_.end());
    cards_.erase(cards_.end() - n, cards_.end());
    return drawn;
}

void Deck::AddCard(const Card& card) {
    cards_.insert(cards_.begin(), card); // add to bottom of deck
}

int Deck::Size() const {
    return static_cast<int>(cards_.size());
}
