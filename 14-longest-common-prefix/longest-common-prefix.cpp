class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Take the first string as the base reference
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            // Shorten the prefix until the current string starts with it
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, there's no common prefix
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};