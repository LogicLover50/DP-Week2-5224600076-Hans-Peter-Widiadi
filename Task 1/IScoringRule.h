#ifndef ISCORING_RULE_H
#define ISCORING_RULE_H

#include "TurnInput.h"

// Interface: anything that computes a base score must implement this.
// RunSession calls this — it does NOT know what formula is used inside.

class IScoringRule {
public:
    virtual int ComputeScore(const TurnInput& input) const = 0;
    virtual ~IScoringRule() = default;
};

#endif
