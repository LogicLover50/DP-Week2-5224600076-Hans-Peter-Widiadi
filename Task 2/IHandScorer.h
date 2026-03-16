#ifndef IHAND_SCORER_H
#define IHAND_SCORER_H

#include "Hand.h"

// Interface: anything that can score a hand must implement this.
// GameSession depends on this interface, NOT on BaseChipScorer directly.
// This means you can swap in a different scorer without touching GameSession.

class IHandScorer {
public:
    virtual int Score(const Hand& hand) const = 0;
    virtual ~IHandScorer() = default;
};

#endif
