#pragma once

#include <array>
#include <string>
#include <string_view>
#include <filesystem>
#include <fstream>
#include <optional>
#include <memory>
#include <nlohmann/json.hpp>
#include "PuzzleTypes.hpp"

struct TrieNode {
    std::array<std::unique_ptr<TrieNode>, 26> children;
    bool isWord = false;
};

class TrieEngine {
public:
    TrieEngine() {};
    bool InsertWord(std::string_view word);
    bool LoadDictionaryFromJson(const std::filesystem::path& dictionaryPath);
    void GetPrunedWordList(AlphabetFrequencies letterWheel, std::vector<std::string>& outWordList) const;
private:
    std::unique_ptr<TrieNode> m_rootNode;
    
    void TraverseAndPrune(TrieNode* node, AlphabetFrequencies& letterWheel, std::vector<std::string>& outWordList, std::string& currentPath, uint8_t currentDepth = 0) const;
};