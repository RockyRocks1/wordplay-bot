#pragma once
#include "PuzzleTypes.hpp"
#include <vector>
#include <string>
class SolverEngine {
public:
	SolverEngine(PuzzleState& initialState);
	bool Solve(const WordList& wordList, int maxSolutionCount = 1);
	inline const std::vector<PuzzleState>& GetSolutions() const noexcept {
		return m_solutions;
	}
private:
	PuzzleState& m_state;
	std::vector<PuzzleState> m_solutions;
	std::vector<std::vector<Intersection>> m_intersectionsBySlot;
	// TODO: use a hueristic to make this faster...
	bool SolveRecursive(const WordList& wordList, int8_t currentSlotIndex, int maxSolutionCount = 1);
};