#ifndef TURN_INPUT_H
#define TURN_INPUT_H

// TurnInput is the data generated each round.
// It flows from IInputGenerator → IScoringRule → IRewardRule.
// Think of it as the "hand played" this round.

struct TurnInput {
    int value; // e.g. number of cards played, or a dice roll
};

#endif
