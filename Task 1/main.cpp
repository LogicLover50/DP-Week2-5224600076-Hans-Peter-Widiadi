#include <iostream>
#include <cstdlib>
#include <ctime>

#include "RunSession.h"
#include "FixedInputGenerator.h"
#include "RandomInputGenerator.h"
#include "DirectScoringRule.h"
#include "BaseRewardRule.h"
#include "BonusRewardRule.h"
#include "ShopSystem.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // ── BASE RUN ──────────────────────────────────────────
    // Fixed Input + Base Reward 
    // Reward == Base Score
    std::cout << "========================================\n";
    std::cout << " BASE RUN : Fixed Input, Base Reward\n";
    std::cout << "========================================\n";
    {
        FixedInputGenerator generator(3);
        DirectScoringRule   scorer;
        BaseRewardRule      rewardRule;
        ShopSystem          shop(2);

        RunSession session(&generator, &scorer, &rewardRule, &shop);
        session.StartRun();
    }

    std::cout << "\n";

    // ── MODIFICATION 1: Replace Input Generator ───────────
    // RandomInputGenerator replaces FixedInputGenerator.
    std::cout << "========================================\n";
    std::cout << " MOD 1: Random Input\n";
    std::cout << "========================================\n";
    {
        RandomInputGenerator generator(1, 10); // <-- only this changes
        DirectScoringRule    scorer;
        BaseRewardRule       rewardRule;
        ShopSystem           shop(2);

        RunSession session(&generator, &scorer, &rewardRule, &shop);
        session.StartRun();
    }

    std::cout << "\n";

    // ── MODIFICATION 2: Change Reward Logic ───────────────
    // BonusRewardRule replaces BaseRewardRule.
    // Reward =/= Base Score.
    std::cout << "========================================\n";
    std::cout << " MOD 2: Bonus Reward\n";
    std::cout << "========================================\n";
    {
        RandomInputGenerator generator(1, 10);
        DirectScoringRule    scorer;
        BonusRewardRule      rewardRule;  // <-- only this changes
        ShopSystem           shop(2);

        RunSession session(&generator, &scorer, &rewardRule, &shop);
        session.StartRun();
    }

    return 0;
}
