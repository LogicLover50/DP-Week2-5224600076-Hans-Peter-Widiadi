#include "BonusRewardRule.h"

int BonusRewardRule::ComputeReward(int baseScore, int round) const {
    if (round % 2 == 0)
        return baseScore * 2;   // even round: double reward
    else
        return baseScore + 2;   // odd round:  flat bonus
}
