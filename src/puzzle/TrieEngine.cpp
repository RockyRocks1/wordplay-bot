#include "puzzle/TrieEngine.hpp"

void TrieEngine::TraverseAndPrune(TrieNode* node, AlphabetFrequencies& letterWheel, std::vector<std::string>& outWordList, std::string& currentPath, uint8_t currentDepth) const{
	if (!node || currentDepth > 8)
		return;
	if (node->isWord)
		outWordList.push_back(currentPath);

	for (int i = 0; i < 26; i++) {
		if (letterWheel[i] == 0)
			continue;

		if (!node->children[i])
			continue;

		letterWheel[i]--;
		currentPath.push_back('a' + i);
		TraverseAndPrune(node->children[i].get(), letterWheel, outWordList, currentPath, currentDepth + 1);
		currentPath.pop_back();
		letterWheel[i]++;
	}
}

void TrieEngine::GetPrunedWordList(AlphabetFrequencies letterWheel, std::vector<std::string>& outWordList) const {
	outWordList.clear();
	outWordList.reserve(128);

	std::string currentPath = "";
	TraverseAndPrune(m_rootNode.get(), letterWheel, outWordList, currentPath, 0);
}

bool TrieEngine::InsertWord(std::string_view word) {
	TrieNode* currentNode = m_rootNode.get();
	for (size_t i = 0; i < word.length(); i++) {
		char letterIndex = word[i] - 'a';

		if (letterIndex < 0 || letterIndex >= 26)
			return false;
		
		if (!currentNode->children[letterIndex])
			currentNode->children[letterIndex] = std::make_unique<TrieNode>();

		currentNode = currentNode->children[letterIndex].get();
	}
	currentNode->isWord = true;
	return true;
}
bool TrieEngine::LoadDictionaryFromJson(const std::filesystem::path& dictionaryPath) {
	using json = nlohmann::json;

	if (!std::filesystem::exists(dictionaryPath))
		return false;

	if (dictionaryPath.extension().wstring() != L".json")
		return false;

	std::ifstream inputStream(dictionaryPath);
	if (!inputStream.is_open())
		return false;

	try {
		json words = json::parse(inputStream);
		for (const auto& [word, wordFrequency] : words.items())
			InsertWord(word);
	}
	catch (const json::parse_error& error) {
		return false;
	}
	return true;
}