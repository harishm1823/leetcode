#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstColZero = false;

        // Pass 1: Use first row and first column as markers
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
            }
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Pass 2: Fill zeroes based on markers (bottom-up to protect original flags)
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (firstColZero) {
                matrix[i][0] = 0;
            }
        }
    }
};