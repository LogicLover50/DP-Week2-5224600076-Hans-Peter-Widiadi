#include "RandomInputGenerator.h"
#include <cstdlib>

RandomInputGenerator::RandomInputGenerator(int min, int max)
    : min_(min), max_(max) {}

TurnInput RandomInputGenerator::Generate() const {
    int range = max_ - min_ + 1;
    int value = min_ + (std::rand() % range);
    return TurnInput{ value };
}
