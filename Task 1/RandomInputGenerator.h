#ifndef RANDOM_INPUT_GENERATOR_H
#define RANDOM_INPUT_GENERATOR_H

#include "IInputGenerator.h"

// Modification 1: replacement for FixedInputGenerator.
// Generates a random value between min and max each round.
// RunSession does NOT change — only the injected generator changes.

class RandomInputGenerator : public IInputGenerator {
public:
    RandomInputGenerator(int min = 1, int max = 10);
    TurnInput Generate() const override;

private:
    int min_;
    int max_;
};

#endif
