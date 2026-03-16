#ifndef IREWARD_RULE_H
#define IREWARD_RULE_H

// Interface: anything that computes a money reward must implement this.
// RunSession calls this — it does NOT know how reward is calculated.

class IRewardRule {
public:
    virtual int ComputeReward(int baseScore, int round) const = 0;
    virtual ~IRewardRule() = default;
};

#endif
