#pragma once
#include "PuzzleTypes.hpp"
#include "VideoCapture.hpp"

struct LetterPoolElement {
	AlphabetFrequencies letters;
	std::vector<std::vector<
};

class PuzzleReader {
public:
	PuzzleLayout ReadPuzzleLayout(FrameView& screenView);
	std::vector<int> GetLetterPoolLetterPos(FrameView& screenView);
	AlphabetFrequencies ReadLetterPoolLetters(FrameView& screenView);
};