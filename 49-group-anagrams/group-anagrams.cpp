#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        for (const std::string& str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end()); // Sorted string acts as the unique key
            anagramGroups[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(anagramGroups.size());

        for (auto& entry : anagramGroups) {
            result.push_back(std::move(entry.second));
        }

        return result;
    }
};