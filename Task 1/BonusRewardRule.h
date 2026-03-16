#ifndef BONUS_REWARD_RULE_H
#define BONUS_REWARD_RULE_H

#include "IRewardRule.h"

// Modification 2: reward behavior changed.
// - On even rounds: reward = baseScore * 2
// - On odd rounds:  reward = baseScore + 2
// RunSession does NOT change — only the injected reward rule changes.

class BonusRewardRule : public IRewardRule {
public:
    int ComputeReward(int baseScore, int round) const override;
};

#endif
