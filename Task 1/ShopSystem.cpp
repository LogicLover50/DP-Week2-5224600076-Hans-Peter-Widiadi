#include "ShopSystem.h"
#include <iostream>

ShopSystem::ShopSystem(int itemCost)
    : itemCost_(itemCost) {}

void ShopSystem::RunShop(int& money) {
    std::cout << "[SHOP] Offered: Bonus(+2) | Cost: " << itemCost_ << "\n";

    if (money >= itemCost_) {
        money -= itemCost_;
        std::cout << "[SHOP] Purchased! Money remaining: " << money << "\n";
    } else {
        std::cout << "[SHOP] Not enough money. Skipped.\n";
    }
}
