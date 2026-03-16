#ifndef RUN_SESSION_H
#define RUN_SESSION_H

#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

// RunSession controls the phase order ONLY.
// It contains NO input generation logic.
// It contains NO scoring logic.
// It contains NO reward logic.
// All behavior is injected via interfaces — fully swappable.

class RunSession {
public:
    RunSession(IInputGenerator* generator,
               IScoringRule*    scorer,
               IRewardRule*     rewardRule,
               ShopSystem*      shop);

    void StartRun();

private:
    // ── Invariant phase order (must never change) ──
    TurnInput GenerateInputPhase();
    int       ComputeScorePhase(const TurnInput& input);
    int       ComputeRewardPhase(int baseScore, int round);
    void      UpdateMoneyPhase(int reward);
    void      ShopPhase();
    void      AdvanceRound();

    // ── Injected dependencies ──
    IInputGenerator* generator_;
    IScoringRule*    scorer_;
    IRewardRule*     rewardRule_;
    ShopSystem*      shop_;

    // ── State ──
    int money_;
    int currentRound_;

    static const int TOTAL_ROUNDS = 3;
};

#endif
