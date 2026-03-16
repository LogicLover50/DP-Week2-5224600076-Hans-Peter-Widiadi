# Task 2 — Simplified Balatro Core Loop

## Game Concept
A simplified Balatro run: draw cards, play a hand, score it (base chips only), 
repeat 3 times, with a shop between rounds to buy extra cards.

---

## Core Loop

1. Draw cards from the deck
2. Player selects cards to play (skeleton: all cards are played)
3. Score the hand based on poker hand type + card chip values
4. Update total chips
5. Shop phase — buy an extra card if you have enough chips
6. Advance to next round
7. Repeat for 3 rounds

---

## Step 2 — Invariant Structure

### Which steps must NEVER change order?
The phase sequence inside `GameSession::StartGame()`:
1. DrawPhase
2. PlayPhase
3. ScorePhase
4. UpdatePhase
5. ShopPhase

### Which components must always exist?
- `GameSession` — controls the loop
- `Deck` — provides cards to draw
- `Hand` — holds cards to be played and scored
- `IHandScorer` — scores the hand
- `ShopSystem` — handles shop logic
- `totalChips_` — tracks the game state

### What breaks if the order changes?
- Score before Play → scoring an empty or un-played hand
- Update before Score → updating chips with the wrong (stale) score
- Draw after Play → no cards exist to play
- Shop during a round → chips update mid-round, breaking round integrity

---

## Step 3 — Mutable Elements

1. **Chip values per hand type** (`BaseChipScorer.cpp` constants)  
   Can be changed freely. Only `BaseChipScorer` is affected. `GameSession` never sees these numbers.

2. **Scoring algorithm** (`BaseChipScorer`)  
   A completely different scorer can be created (e.g. one with multipliers) by implementing `IHandScorer` and passing it to `GameSession`. `GameSession` does not need to change.

3. **Shop offer and cost** (`ShopSystem`)  
   What the shop sells, how many items, and the cost are all contained inside `ShopSystem`. The phase order (shop happens after update) stays intact.

4. **Number of cards drawn per round** (`CARDS_DRAWN` constant in `GameSession.h`)  
   Changing this only affects how many cards are dealt — not the phase sequence.

5. **Deck composition** (`Deck`)  
   Extra cards can be added (e.g. via the shop). The deck can be refactored to support multiple decks. `GameSession` only calls `Draw()` and doesn't care what's inside.

These are mutable because they change *numeric behavior or content* but not the structural phase sequence.

---

## Step 4 — Architectural Notes

- `GameSession` controls phase order ONLY. It contains no scoring formulas, no card generation logic, no shop logic.
- `IHandScorer` is an interface. `GameSession` depends on the interface, not the concrete class. This means the scorer is swappable without touching `GameSession`.
- If you want to add multipliers later, create `MultiplierScorer : IHandScorer` and pass it in. `GameSession` stays the same.
- If you want a bigger shop, only `ShopSystem` changes.

The invariant (phase order) is protected. The mutable parts (formulas, content, logic) are isolated.

---

## File Structure

```
Card.h / Card.cpp           — Represents a single playing card
Deck.h / Deck.cpp           — Holds and manages the card deck
Hand.h / Hand.cpp           — Holds the player's current cards
IHandScorer.h               — Interface: contract for any scorer
BaseChipScorer.h/.cpp       — Concrete scorer: poker hands → base chips
ShopSystem.h / ShopSystem.cpp — Shop phase logic
GameSession.h / GameSession.cpp — Invariant loop controller
main.cpp                    — Entry point
```
