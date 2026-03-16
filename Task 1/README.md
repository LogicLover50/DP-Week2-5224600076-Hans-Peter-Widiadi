# Task 1 — Balatro-Like Run Loop

## Program Behavior
Simulates a 3-round run with a fixed phase order each round, followed by a shop phase.
Demonstrates two modifications that change behavior without touching RunSession.

---

## Phase Order (Invariant — never changes)

For each of 3 rounds:
1. Generate input
2. Compute base score
3. Compute reward
4. Update money
5. Shop phase
6. Advance round

---

## File Structure

```
TurnInput.h                  — Data passed between phases
IInputGenerator.h            — Interface: generates TurnInput
IScoringRule.h               — Interface: computes base score
IRewardRule.h                — Interface: computes money reward
FixedInputGenerator.h/.cpp   — Always returns a fixed value
RandomInputGenerator.h/.cpp  — Returns a random value (Modification 1)
DirectScoringRule.h/.cpp     — Score = input value
BaseRewardRule.h/.cpp        — Reward = base score (original)
BonusRewardRule.h/.cpp       — Reward != base score (Modification 2)
ShopSystem.h/.cpp            — Shop phase logic
RunSession.h/.cpp            — Invariant loop controller
main.cpp                     — Entry point, wires dependencies together
```

---

## Modification 1 — Replace Input Generator

`RandomInputGenerator` replaces `FixedInputGenerator`.

In `main.cpp`, only one line changes:
```cpp
// Before:
FixedInputGenerator generator(3);

// After:
RandomInputGenerator generator(1, 10);
```

`RunSession` is NOT modified. It depends on `IInputGenerator` (the interface),
not on any concrete class. Swapping the generator is invisible to RunSession.

---

## Modification 2 — Change Reward Logic

`BonusRewardRule` replaces `BaseRewardRule`.

Reward is no longer equal to base score:
- Odd rounds:  reward = baseScore + 2
- Even rounds: reward = baseScore * 2

In `main.cpp`, only one line changes:
```cpp
// Before:
BaseRewardRule rewardRule;

// After:
BonusRewardRule rewardRule;
```

`RunSession` is NOT modified. It calls `rewardRule_->ComputeReward()` through
the `IRewardRule` interface and has no knowledge of what formula is used inside.

---

## Reflection

### 1. What is the invariant structure in your program?
The phase order inside `RunSession::StartRun()`:
GenerateInput → ComputeScore → ComputeReward → UpdateMoney → Shop → Advance.
This sequence must never change. Each phase depends on the result of the previous one.

### 2. Which parts are mutable?
- How input is generated (`IInputGenerator` — swap `FixedInputGenerator` for `RandomInputGenerator`)
- How score is computed (`IScoringRule` — swap or change `DirectScoringRule`)
- How reward is computed (`IRewardRule` — swap `BaseRewardRule` for `BonusRewardRule`)
- What the shop offers (`ShopSystem` — change items, cost, or quantity inside)

### 3. When you replaced the InputGenerator, why didn't RunSession change?
Because `RunSession` depends on the `IInputGenerator` interface, not on any specific
class. It only calls `generator_->Generate()`. It does not know — or care — whether
the generator is fixed or random. The concrete class is injected from outside
(in `main.cpp`), so swapping it requires zero changes to `RunSession`.

### 4. What would happen if scoring logic was placed inside RunSession?
Every time the scoring formula needed to change, `RunSession` would have to be
modified too. This means the invariant (phase order) and the mutable behavior
(formula) would be tangled together in the same class. A change to scoring could
accidentally break the loop order, and the class would become harder to test,
maintain, and extend. Separating them ensures changes to one never affect the other.
