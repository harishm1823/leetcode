#include <vector>

class Solution {
public:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: combination of size k is formed
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Pruning optimization: only loop if enough elements remain to reach size k
        for (int i = start; i <= n - (k - current.size()) + 1; ++i) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back(); // Backtrack
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};