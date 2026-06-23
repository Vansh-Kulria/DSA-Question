class Solution {
public:
    bool findEmptyCell(vector<vector<char>>& board, int& row, int& col) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, char& num) {
        // check current row;
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) {
                return false;
            }
        }

        // check current col;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }

        // check subbox 3*3;
        int startRow = row - (row % 3); // subbox start row
        int startCol = col - (col % 3); // subbox start col

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int r = i + startRow;
                int c = j + startCol;

                if (board[r][c] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board) {
        // write one case
        // 1. find empty cell
        int row, col;
        if (!findEmptyCell(board, row, col)) {
            return true;
        }

        // fill it with a Suitable number after checking it is safe or not;
        for (int i = 1; i <= 9; i++) {
            char num = i + '0';
            if (isSafe(board, row, col, num)) {
                board[row][col] = num;
                // next number fill
                if (solveSudokuHelper(board)) {
                    return true;
                }
                board[row][col] = '.'; // backtracking
            }
        }
        // if was not able to put any number then backtrack return false;
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { solveSudokuHelper(board); }
};