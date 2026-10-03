#include <iostream>
#include "puzzle/TrieEngine.hpp"
#include "puzzle/SolverEngine.hpp"
int main() {
	/*
	CapContext context = Cap_createContext();
	VideoCapture a(context, 1, 14);
	CapFormatInfo info;
	for (int i = 0; i < Cap_getNumFormats(context, 1); i++) {
		Cap_getFormatInfo(context, 1, i, &info);
		std::cout << "\n\nDEVICE FORMAT #" << i;
		std::cout << "\nWidth: " << info.width;
		std::cout << "\nHeight: " << info.height;
		std::cout << "\nFPS: " << info.fps;
		std::cout << "\nBPP: " << info.bpp;
	}
	FrameView view = a.GetLatestFrame();
	system("pause");
	*/
	AlphabetFrequencies pool{};
	pool['c' - 'a'] = 1;
	pool['a' - 'a'] = 1;
	pool['t' - 'a'] = 1;
	TrieEngine engine;
	engine.InsertWord("dog");
	engine.InsertWord("cat");
	
	WordList wordList{};
	engine.GetPrunedWordList(pool, wordList);
	PuzzleLayout layout{
		.slots = {
			WordSlot{ SlotDirection::Horizontal, 0, 0, 3 }
		},
		.intersections = {}
	};
	PuzzleState state{
		.layout = layout,
		.guesses = {},
		.isWordUsed = {}
	};
	SolverEngine solver(state);
	solver.Solve(wordList);
	auto hi = solver.GetState();
	std::cout << hi.isWordUsed[0] << std::endl;
	
}