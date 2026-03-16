#ifndef BASE_CHIP_SCORER_H
#define BASE_CHIP_SCORER_H

#include "IHandScorer.h"
#include "Hand.h"
#include <string>

// Concrete implementation of IHandScorer.
// All chip values for hand types live HERE — nowhere else.
// Mutable: change chip values freely without touching GameSession.

class BaseChipScorer : public IHandScorer {
public:
    int Score(const Hand& hand) const override;

private:
    // Hand type detection helpers
    bool IsFlush(const Hand& hand) const;
    bool IsStraight(const Hand& hand) const;
    int  GetOfAKindCount(const Hand& hand, int n) const; // how many groups of n-of-a-kind

    std::string DetectHandName(const Hand& hand) const;
};

#endif
