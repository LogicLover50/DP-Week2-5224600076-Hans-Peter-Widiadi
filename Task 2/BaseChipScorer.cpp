#include "BaseChipScorer.h"
#include <map>
#include <algorithm>
#include <iostream>

// ─────────────────────────────────────────
//  MUTABLE SECTION: chip values per hand
//  Change these numbers freely — nothing
//  outside this file needs to change.
// ─────────────────────────────────────────
static const int CHIPS_HIGH_CARD    =  5;
static const int CHIPS_PAIR         = 10;
static const int CHIPS_TWO_PAIR     = 20;
static const int CHIPS_THREE_OF_KIND= 30;
static const int CHIPS_STRAIGHT     = 30;
static const int CHIPS_FLUSH        = 35;
static const int CHIPS_FULL_HOUSE   = 40;
static const int CHIPS_FOUR_OF_KIND = 60;
static const int CHIPS_STRAIGHT_FLUSH = 100;

int BaseChipScorer::Score(const Hand& hand) const {
    std::string name = DetectHandName(hand);

    // Sum up the base chip value of every card in the hand
    int cardChips = 0;
    for (const auto& c : hand.GetCards())
        cardChips += c.GetChipValue();

    // Hand bonus chips
    int handBonus = 0;
    if      (name == "Straight Flush")  handBonus = CHIPS_STRAIGHT_FLUSH;
    else if (name == "Four of a Kind")  handBonus = CHIPS_FOUR_OF_KIND;
    else if (name == "Full House")      handBonus = CHIPS_FULL_HOUSE;
    else if (name == "Flush")           handBonus = CHIPS_FLUSH;
    else if (name == "Straight")        handBonus = CHIPS_STRAIGHT;
    else if (name == "Three of a Kind") handBonus = CHIPS_THREE_OF_KIND;
    else if (name == "Two Pair")        handBonus = CHIPS_TWO_PAIR;
    else if (name == "Pair")            handBonus = CHIPS_PAIR;
    else                                handBonus = CHIPS_HIGH_CARD;

    int total = cardChips + handBonus;
    std::cout << "[SCORE] Hand: " << name
              << " | Card chips: " << cardChips
              << " | Bonus: " << handBonus
              << " | Total: " << total << "\n";
    return total;
}

// ─── Helpers ──────────────────────────────

bool BaseChipScorer::IsFlush(const Hand& hand) const {
    const auto& cards = hand.GetCards();
    if (cards.size() < 5) return false;
    Suit s = cards[0].GetSuit();
    for (const auto& c : cards)
        if (c.GetSuit() != s) return false;
    return true;
}

bool BaseChipScorer::IsStraight(const Hand& hand) const {
    const auto& cards = hand.GetCards();
    if (cards.size() < 5) return false;

    std::vector<int> ranks;
    for (const auto& c : cards)
        ranks.push_back(static_cast<int>(c.GetRank()));
    std::sort(ranks.begin(), ranks.end());

    for (int i = 1; i < (int)ranks.size(); ++i)
        if (ranks[i] != ranks[i-1] + 1) return false;
    return true;
}

int BaseChipScorer::GetOfAKindCount(const Hand& hand, int n) const {
    std::map<int,int> freq;
    for (const auto& c : hand.GetCards())
        freq[static_cast<int>(c.GetRank())]++;

    int count = 0;
    for (const auto& [rank, cnt] : freq)
        if (cnt == n) count++;
    return count;
}

std::string BaseChipScorer::DetectHandName(const Hand& hand) const {
    bool flush    = IsFlush(hand);
    bool straight = IsStraight(hand);
    int fours     = GetOfAKindCount(hand, 4);
    int threes    = GetOfAKindCount(hand, 3);
    int pairs     = GetOfAKindCount(hand, 2);

    if (flush && straight)  return "Straight Flush";
    if (fours  == 1)        return "Four of a Kind";
    if (threes == 1 && pairs == 1) return "Full House";
    if (flush)              return "Flush";
    if (straight)           return "Straight";
    if (threes == 1)        return "Three of a Kind";
    if (pairs  == 2)        return "Two Pair";
    if (pairs  == 1)        return "Pair";
    return "High Card";
}
