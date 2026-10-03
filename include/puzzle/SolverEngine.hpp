#pragma once
#include "PuzzleTypes.hpp"
#include <vector>
#include <string>
class SolverEngine {
public:
	SolverEngine(PuzzleState& initialState);
	// TODO: add exhaustive solution finding
	bool Solve(const WordList& wordList);
	inline const PuzzleState& GetState() const noexcept {
		return m_state;
	}
private:
	PuzzleState& m_state;
	std::vector<std::vector<Intersection>> m_intersectionsBySlot;
	bool SolveRecursive(const WordList& wordList, int8_t currentSlotIndex);
};