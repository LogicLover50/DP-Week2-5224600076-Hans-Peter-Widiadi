#include "BaseRewardRule.h"

int BaseRewardRule::ComputeReward(int baseScore, int /*round*/) const {
    return baseScore; // reward = base score directly
}
