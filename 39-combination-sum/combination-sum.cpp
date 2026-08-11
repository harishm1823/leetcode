class Solution {
private:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Pruning: if candidate exceeds remaining target, skip
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);
                // Pass 'i' (not 'i + 1') to allow reusing the same candidate unlimited times
                backtrack(i, target - candidates[i], candidates, current, result);
                current.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }
};