class Solution {
public:
    int uniquePaths(int m, int n) {
        // Choose the smaller parameter to minimize iterations
        int N = m + n - 2;
        int k = std::min(m - 1, n - 1);
        long long result = 1;

        // Calculate N C k = N * (N-1) * ... * (N-k+1) / (1 * 2 * ... * k)
        for (int i = 1; i <= k; ++i) {
            result = result * (N - k + i) / i;
        }

        return static_cast<int>(result);
    }
};