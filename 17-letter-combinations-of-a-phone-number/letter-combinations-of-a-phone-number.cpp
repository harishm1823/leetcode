class Solution {
private:
    void backtrack(const string& digits, int index, string& current, 
                   const vector<string>& phoneMap, vector<string>& result) {
        // Base case: if current combination length matches digits length, store it
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get corresponding characters for current digit
        string letters = phoneMap[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);                      // Choose
            backtrack(digits, index + 1, current, phoneMap, result); // Explore
            current.pop_back();                       // Backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Telephone keypad mapping
        vector<string> phoneMap = {
            "",     "",     "abc",  "def", // 0, 1, 2, 3
            "ghi",  "jkl",  "mno",         // 4, 5, 6
            "pqrs", "tuv",  "wxyz"         // 7, 8, 9
        };

        vector<string> result;
        string current = "";
        
        backtrack(digits, 0, current, phoneMap, result);
        
        return result;
    }
};