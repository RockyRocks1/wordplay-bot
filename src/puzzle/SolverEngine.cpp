#include "puzzle/SolverEngine.hpp"

SolverEngine::SolverEngine(PuzzleState& initialState) : m_state(initialState) {

}

bool SolverEngine::Solve(const std::vector<std::string>& dictionary) {
	const PuzzleLayout& layout = m_state.layout.get();
	if (dictionary.size() < layout.slots.size())
		return false;

	// ...
}