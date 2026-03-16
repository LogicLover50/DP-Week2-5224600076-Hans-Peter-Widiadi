#include "RunSession.h"
#include <iostream>

RunSession::RunSession(IInputGenerator* generator,
                       IScoringRule*    scorer,
                       IRewardRule*     rewardRule,
                       ShopSystem*      shop)
    : generator_(generator),
      scorer_(scorer),
      rewardRule_(rewardRule),
      shop_(shop),
      money_(0),
      currentRound_(1) {}

void RunSession::StartRun() {
    std::cout << "=== RUN START ===\n\n";

    for (currentRound_ = 1; currentRound_ <= TOTAL_ROUNDS; ++currentRound_) {
        std::cout << "Round " << currentRound_ << "\n";

        // ── INVARIANT PHASE ORDER ──────────────────────────
        TurnInput input  = GenerateInputPhase();
        int baseScore    = ComputeScorePhase(input);
        int reward       = ComputeRewardPhase(baseScore, currentRound_);
        UpdateMoneyPhase(reward);
        ShopPhase();
        AdvanceRound();
        // ──────────────────────────────────────────────────

        std::cout << "\n";
    }

    std::cout << "=== RUN END ===\n";
    std::cout << "Final money: " << money_ << "\n";
}

// ── Phase implementations ──────────────────────────────────

TurnInput RunSession::GenerateInputPhase() {
    // Fully delegated — RunSession does NOT generate input itself
    TurnInput input = generator_->Generate();
    std::cout << "[PLAY] Input generated: " << input.value << "\n";
    return input;
}

int RunSession::ComputeScorePhase(const TurnInput& input) {
    // Fully delegated — RunSession does NOT compute scores itself
    int score = scorer_->ComputeScore(input);
    std::cout << "[SCORE] Base score: " << score << "\n";
    return score;
}

int RunSession::ComputeRewardPhase(int baseScore, int round) {
    // Fully delegated — RunSession does NOT compute rewards itself
    int reward = rewardRule_->ComputeReward(baseScore, round);
    std::cout << "[REWARD] Gain: " << reward
              << " | Money: " << (money_ + reward) << "\n";
    return reward;
}

void RunSession::UpdateMoneyPhase(int reward) {
    // Money is ONLY updated here — never anywhere else
    money_ += reward;
}

void RunSession::ShopPhase() {
    // Fully delegated — RunSession does NOT know what the shop sells
    shop_->RunShop(money_);
}

void RunSession::AdvanceRound() {
    std::cout << "[END] Round " << currentRound_ << " complete."
              << " Money so far: " << money_ << "\n";
}
