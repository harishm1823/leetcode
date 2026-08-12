#include <vector>
#include <string>

class Solution {
private:
    void backtrack(int row, int n, std::vector<std::string>& board, 
                   std::vector<bool>& cols, std::vector<bool>& diag, std::vector<bool>& antiDiag, 
                   std::vector<std::vector<std::string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int dIdx = row - col + n;
            int adIdx = row + col;

            // Check if column or diagonals are under attack
            if (cols[col] || diag[dIdx] || antiDiag[adIdx]) continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = diag[dIdx] = antiDiag[adIdx] = true;

            // Recurse to next row
            backtrack(row + 1, n, board, cols, diag, antiDiag, result);

            // Backtrack (remove queen)
            board[row][col] = '.';
            cols[col] = diag[dIdx] = antiDiag[adIdx] = false;
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, '.'));

        std::vector<bool> cols(n, false);
        std::vector<bool> diag(2 * n, false);
        std::vector<bool> antiDiag(2 * n, false);

        backtrack(0, n, board, cols, diag, antiDiag, result);
        return result;
    }
};