#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include "Deck.h"
#include "Hand.h"
#include "IHandScorer.h"
#include "ShopSystem.h"

// GameSession ONLY controls phase order.
// It contains NO scoring logic, NO card generation logic, NO shop logic.
// All of that is delegated to the appropriate classes.

class GameSession
{
public:
    GameSession();
    void StartGame();

private:
    // ── Invariant phases (order must never change) ──
    void DrawPhase();
    void PlayPhase();
    void ScorePhase();
    void UpdatePhase(int score);
    void ShopPhase();

    // ── State ──
    Deck        deck_;
    Hand        hand_;
    IHandScorer* scorer_;   // points to BaseChipScorer — swappable
    ShopSystem  shop_;
    int         totalChips_;
    int         roundScore_;

    static const int ROUNDS      = 3;
    static const int CARDS_DRAWN = 5;
};

#endif
