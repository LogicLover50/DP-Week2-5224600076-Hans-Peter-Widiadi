#include "GameSession.h"
#include "BaseChipScorer.h"
#include <iostream>

GameSession::GameSession()
    : deck_(),
      scorer_(new BaseChipScorer()),
      shop_(2),
      totalChips_(0),
      roundScore_(0)
{
    deck_.Shuffle();
}

void GameSession::StartGame()
{
    std::cout << "\n=== RUN START ===\n\n";

    for (int round = 1; round <= ROUNDS; ++round)
    {
        std::cout << "--- Round " << round << " ---\n";

        // ── INVARIANT PHASE ORDER ──────────────────
        DrawPhase();
        PlayPhase();
        ScorePhase();
        UpdatePhase(roundScore_);
        ShopPhase();
        // ──────────────────────────────────────────

        hand_.Clear();
        std::cout << "\n";
    }

    std::cout << "=== RUN END ===\n";
    std::cout << "Final chips: " << totalChips_ << "\n";

    delete scorer_;
}

// ── Phase implementations ──────────────────────────────

void GameSession::DrawPhase()
{
    std::vector<Card> drawn = deck_.Draw(CARDS_DRAWN);
    hand_.AddCards(drawn);
    std::cout << "[DRAW] Drew " << drawn.size() << " cards: ";
    hand_.Print();
}

void GameSession::PlayPhase()
{
    // In a full game, the player selects which cards to play.
    // For this skeleton, all drawn cards are played.
    std::cout << "[PLAY] Playing hand: ";
    hand_.Print();
}

void GameSession::ScorePhase()
{
    // Scoring is fully delegated to the scorer — GameSession doesn't know how.
    roundScore_ = scorer_->Score(hand_);
}

void GameSession::UpdatePhase(int score)
{
    totalChips_ += score;
    std::cout << "[UPDATE] +" << score
              << " chips | Total: " << totalChips_ << "\n";
}

void GameSession::ShopPhase()
{
    // Shop logic is fully delegated to ShopSystem — GameSession doesn't know what's inside.
    shop_.RunShop(deck_, totalChips_);
}
