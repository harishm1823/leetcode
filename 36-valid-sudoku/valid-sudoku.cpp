class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track seen numbers for rows, columns, and 3x3 sub-boxes
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1'; // Convert '1'-'9' to index 0-8
                int pos = 1 << val;         // Bit mask for the value
                int boxIdx = (r / 3) * 3 + (c / 3);

                // Check if the digit already exists in row, col, or box
                if ((rows[r] & pos) || (cols[c] & pos) || (boxes[boxIdx] & pos)) {
                    return false;
                }

                // Mark the digit as seen
                rows[r] |= pos;
                cols[c] |= pos;
                boxes[boxIdx] |= pos;
            }
        }

        return true;
    }
};