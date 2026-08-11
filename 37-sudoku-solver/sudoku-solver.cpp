class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c) return false;
            // Check column
            if (board[i][col] == c) return false;
            // Check 3x3 sub-box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch; // Place candidate digit

                            if (solve(board)) {
                                return true; // Found valid solution
                            }

                            board[r][c] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid digit fits here
                }
            }
        }
        return true; // All cells filled successfully
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};