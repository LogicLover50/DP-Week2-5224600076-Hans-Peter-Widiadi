#include "ShopSystem.h"
#include <iostream>

ShopSystem::ShopSystem(int cardCost)
    : cardCost_(cardCost) {}

void ShopSystem::RunShop(Deck& deck, int& chips) {
    // Offer a fixed card for simplicity (Ace of Spades)
    Card offered(Rank::Ace, Suit::Spades);

    std::cout << "[SHOP] Offered: " << offered.ToString()
              << " (cost: " << cardCost_ << " chips)"
              << " | Your chips: " << chips << "\n";

    if (chips >= cardCost_) {
        chips -= cardCost_;
        deck.AddCard(offered);
        std::cout << "[SHOP] Purchased! " << offered.ToString()
                  << " added to deck. Chips remaining: " << chips << "\n";
    } else {
        std::cout << "[SHOP] Not enough chips. Skipping shop.\n";
    }
}
