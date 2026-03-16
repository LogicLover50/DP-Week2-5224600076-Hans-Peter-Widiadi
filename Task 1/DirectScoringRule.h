#ifndef DIRECT_SCORING_RULE_H
#define DIRECT_SCORING_RULE_H

#include "IScoringRule.h"

// Concrete scoring rule.
// Base score = the input value directly.
// Mutable: swap this class to change scoring without touching RunSession.

class DirectScoringRule : public IScoringRule {
public:
    int ComputeScore(const TurnInput& input) const override;
};

#endif
