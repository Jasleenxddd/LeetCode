class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> r(9);
        vector<unordered_set<char>> c(9);
        vector<unordered_set<char>> b(9);
        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='.') continue;
                if(r[i].count(board[i][j])) return false;
                r[i].insert(board[i][j]);

                if(c[j].count(board[i][j])) return false;
                c[j].insert(board[i][j]);

                int ind=(floor(i/3))*3 + floor(j/3);
                if(b[ind].count(board[i][j])) return false;
                b[ind].insert(board[i][j]);
            }
        }
        return true;
    }
};