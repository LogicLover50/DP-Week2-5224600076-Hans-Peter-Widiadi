#ifndef FIXED_INPUT_GENERATOR_H
#define FIXED_INPUT_GENERATOR_H

#include "IInputGenerator.h"

// Original input generator.
// Always returns the same fixed value.
// Used before Modification 1.

class FixedInputGenerator : public IInputGenerator {
public:
    explicit FixedInputGenerator(int value = 3);
    TurnInput Generate() const override;

private:
    int value_;
};

#endif
