#include "FixedInputGenerator.h"

FixedInputGenerator::FixedInputGenerator(int value)
    : value_(value) {}

TurnInput FixedInputGenerator::Generate() const {
    return TurnInput{ value_ };
}
