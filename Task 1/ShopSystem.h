#ifndef SHOP_SYSTEM_H
#define SHOP_SYSTEM_H

// ShopSystem handles the shop phase.
// RunSession calls RunShop() — it does NOT know what's offered inside.

class ShopSystem {
public:
    ShopSystem(int itemCost = 2);
    void RunShop(int& money);

private:
    int itemCost_;
};

#endif
