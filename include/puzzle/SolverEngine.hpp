#pragma once
#include "PuzzleTypes.hpp"
#include <vector>
#include <string>
class SolverEngine {
public:
	SolverEngine(PuzzleState& initialState);
	bool Solve(const std::vector<std::string>& dictionary);
	inline const PuzzleState& GetState() const noexcept {
		return m_state;
	}
private:
	PuzzleState& m_state;
};