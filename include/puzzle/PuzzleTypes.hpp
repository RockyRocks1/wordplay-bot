#pragma once
#include <array>

enum class SlotDirection : uint8_t {
    Horizontal,
    Vertical
};
struct WordSlot {
    SlotDirection direction;
    uint16_t startRow;
    uint16_t startCol;
    uint16_t length;
};
struct Intersection {
    size_t slotAIndex;
    size_t slotBIndex;

    uint8_t slotAOffset;
    uint8_t slotBOffset;
};
using AlphabetFrequencies = std::array<uint8_t, 26>;

