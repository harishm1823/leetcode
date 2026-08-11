class Solution {
private:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Pruning: if current element exceeds target, no need to check further since candidates is sorted
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicate elements at the same recursion depth
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            // Pass 'i + 1' to ensure each candidate element is used at most once
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Sort candidates to handle duplicates and enable pruning
        sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, current, result);
        return result;
    }
};