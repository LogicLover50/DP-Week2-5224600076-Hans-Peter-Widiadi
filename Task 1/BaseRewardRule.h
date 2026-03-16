#ifndef BASE_REWARD_RULE_H
#define BASE_REWARD_RULE_H

#include "IRewardRule.h"

// Original reward rule: reward = baseScore.
// Used before Modification 2.

class BaseRewardRule : public IRewardRule {
public:
    int ComputeReward(int baseScore, int round) const override;
};

#endif
