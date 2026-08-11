class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        // Build frequency map for words
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        // Run sliding window for each offset from 0 to wordLen - 1
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> currentMap;

            for (int right = i; right <= sLen - wordLen; right += wordLen) {
                string sub = s.substr(right, wordLen);

                if (wordMap.count(sub)) {
                    currentMap[sub]++;
                    count++;

                    // If word frequency exceeds target, shrink window from left
                    while (currentMap[sub] > wordMap[sub]) {
                        string leftWord = s.substr(left, wordLen);
                        currentMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Valid match found
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word found; reset window
                    currentMap.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};