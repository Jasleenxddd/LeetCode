class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<int>& dr, vector<int>& dc){
        board[row][col]='*';  
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='O'){
                dfs(nr, nc, board, dr, dc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        for(int j=0;j<n;j++){
            if(board[j][0]=='O'){
                dfs( j, 0, board, dr, dc);
            }
            if(board[j][m-1]=='O'){
                dfs( j, m-1, board, dr, dc);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs( 0, j, board, dr, dc);
            }
            if(board[n-1][j]=='O'){
                dfs( n-1, j, board, dr, dc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='*') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};