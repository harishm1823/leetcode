class Solution {
private:
    void backtrack(int openCount, int closeCount, int n, string current, vector<string>& result) {
        // Base case: string length reaches 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add an open bracket if we haven't used all n open brackets
        if (openCount < n) {
            backtrack(openCount + 1, closeCount, n, current + "(", result);
        }

        // Add a close bracket only if it won't break valid parenthesis balance
        if (closeCount < openCount) {
            backtrack(openCount, closeCount + 1, n, current + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};