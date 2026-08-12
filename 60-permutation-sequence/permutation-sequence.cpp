#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        int fact = 1;

        // Precompute (n-1)! and populate available numbers [1, 2, ..., n]
        for (int i = 1; i < n; ++i) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        // Convert k to 0-indexed
        k = k - 1;

        std::string result = "";

        while (true) {
            // Determine the index of the current digit
            int index = k / fact;
            result += std::to_string(numbers[index]);

            // Remove the selected number from the pool
            numbers.erase(numbers.begin() + index);

            if (numbers.empty()) {
                break;
            }

            // Update k and the factorial for the next step
            k %= fact;
            fact /= numbers.size();
        }

        return result;
    }
};