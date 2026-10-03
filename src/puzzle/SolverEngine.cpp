#include "puzzle/SolverEngine.hpp"

SolverEngine::SolverEngine(PuzzleState& initialState) : m_state(initialState) {
	const PuzzleLayout& layout = m_state.layout.get();
	m_intersectionsBySlot.assign(layout.slots.size(), std::vector<Intersection>());
	for (const Intersection& intersection : layout.intersections)
		m_intersectionsBySlot[intersection.slotBIndex].push_back(intersection);
	
	m_state.guesses.assign(layout.slots.size(), -1);
}

bool SolverEngine::Solve(const WordList& wordList, int maxSolutionCount) {
	const PuzzleLayout& layout = m_state.layout.get();
	if (wordList.words.size() < layout.slots.size())
		return false;

	m_state.isWordUsed.assign(wordList.words.size(), 0);
	return SolveRecursive(wordList, 0, maxSolutionCount);
}
bool SolverEngine::SolveRecursive(const WordList& wordList, int8_t currentSlotIndex, int maxSolutionCount) {
	if (currentSlotIndex == m_state.layout.get().slots.size())
		return true;

	const WordSlot& slot = m_state.layout.get().slots[currentSlotIndex];
	if (slot.length >= wordList.boundaries.size())
		return false;
	
	const WordListBoundary& boundary = wordList.boundaries[slot.length];

	for (int32_t wordIndex = boundary.startIndex; wordIndex < boundary.startIndex + boundary.count; wordIndex++) {
		if (m_state.isWordUsed[wordIndex] != 0)
			continue;
		
		m_state.guesses[currentSlotIndex] = wordIndex;
		m_state.isWordUsed[wordIndex] = 1;
		
		const std::string& wordB = wordList.words[wordIndex];
		bool failedIntersectionCheck = false;
		for (const Intersection& intersection : m_intersectionsBySlot[currentSlotIndex]) {
			const std::string& wordA = wordList.words[m_state.guesses[intersection.slotAIndex]];

			if (wordA[intersection.slotAOffset] != wordB[intersection.slotBOffset]) {
				failedIntersectionCheck = true;
				break;
			}
		}
		
		if (!failedIntersectionCheck && SolveRecursive(wordList, currentSlotIndex + 1, maxSolutionCount)) {
			m_solutions.push_back(m_state);
			if (m_solutions.size() >= maxSolutionCount)
				return true;
		}

		m_state.guesses[currentSlotIndex] = -1;
		m_state.isWordUsed[wordIndex] = 0;
	}
	return false;
}