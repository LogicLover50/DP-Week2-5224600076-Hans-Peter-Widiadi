#include "DirectScoringRule.h"

int DirectScoringRule::ComputeScore(const TurnInput& input) const {
    return input.value; // base score = input value
}
