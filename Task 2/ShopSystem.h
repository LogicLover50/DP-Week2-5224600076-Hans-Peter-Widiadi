#ifndef SHOP_SYSTEM_H
#define SHOP_SYSTEM_H

#include "Deck.h"

// ShopSystem is responsible for the shop phase only.
// It offers a card for purchase and updates the deck if bought.
// GameSession calls RunShop() — it does NOT know what's inside.

class ShopSystem {
public:
    ShopSystem(int cardCost = 2);
    void RunShop(Deck& deck, int& chips);

private:
    int cardCost_;
};

#endif
