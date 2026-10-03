#pragma once
#include <array>
#include <functional>
#include <vector>
#include <string>

using AlphabetFrequencies = std::array<uint8_t, 26>;

enum class SlotDirection : uint8_t {
    Horizontal,
    Vertical
};
struct WordSlot {
    SlotDirection direction;
    uint8_t startRow;
    uint8_t startCol;
    uint8_t length;
};
struct Intersection {
    uint8_t slotAIndex;
    uint8_t slotBIndex;
    uint8_t slotAOffset;
    uint8_t slotBOffset;
};
struct PuzzleLayout {
    std::vector<WordSlot> slots;
    std::vector<Intersection> intersections;
};
struct PuzzleState {
    std::reference_wrapper<PuzzleLayout> layout;
    std::vector<int32_t> guesses;
    std::vector<uint8_t> isWordUsed;
};
struct WordListBoundary {
    uint32_t startIndex;
    uint32_t count;
};
struct WordList {
    std::vector<std::string> words;
    std::vector<WordListBoundary> boundaries;
};