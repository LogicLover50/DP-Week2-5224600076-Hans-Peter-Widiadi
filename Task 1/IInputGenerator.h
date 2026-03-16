#ifndef IINPUT_GENERATOR_H
#define IINPUT_GENERATOR_H

#include "TurnInput.h"

// Interface: anything that generates a TurnInput must implement this.
// RunSession depends on this interface — NOT on any concrete class.
// Swapping FixedInputGenerator for RandomInputGenerator
// requires zero changes to RunSession.

class IInputGenerator {
public:
    virtual TurnInput Generate() const = 0;
    virtual ~IInputGenerator() = default;
};

#endif
