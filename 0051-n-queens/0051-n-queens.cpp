class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board){
        int n = board.size();
        // i need to check 3 dir
        // left horizonatal
        for (int i = 0; i <= col; i++){
            if (board[row][i] == 'Q'){
                // same row me Queen 
                return false;
            }
        }

        // left upperdiagonal
        int i = row-1;
        int j = col-1;

        while(i >=0 && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

         i = row+1;
         j = col-1;

        while(i < n && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }

        // no attack
        return true;
    }

    void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int n) {
        vector<string> temp;
        for(int row = 0; row < n; row++){
            string output = "";
            for(int col = 0; col < n; col++){
                char ch = board[row][col];
                output.push_back(ch);
            }

            // ek string ready
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    void solve( vector<vector<char>> &board, vector<vector<string>> &ans, int n , int col){
        // base case
        if(col >= n){
            // ek answer ready
            storeSolution (board, ans, n);
            return;
        }
        // 1 case solve
        for(int row = 0; row < n ; row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                solve(board,ans,n,col+1);
                // backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // n*n board initialisation with '.'
        vector<vector<char>>board(n,vector<char>(n,'.'));
        // starting with col = 0
        int col = 0;

        solve(board, ans, n, col);
        return ans;
    }
};