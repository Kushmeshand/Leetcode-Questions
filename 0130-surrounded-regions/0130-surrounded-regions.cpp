class Solution {
public:
    void DFS(vector<vector<char>>& board, vector<vector<char>>& ans, int row,int col,int delrow[],int delcol[]){
        int n = board.size();
        int m = board[0].size();
        if(ans[row][col] == 'O'){
           return;
        }
        ans[row][col] = 'O';
        
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && ans[nrow][ncol] != 'O'){
               DFS(board,ans,nrow,ncol,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        vector<vector<char>> ans(n,vector<char>(m,'X'));
            for(int j = 0; j < m; j++){
                if(board[0][j] == 'O'){
                    DFS(board,ans,0,j,delrow,delcol);
                }
                if(board[n-1][j] == 'O'){
                    DFS(board,ans,n-1,j,delrow,delcol);
                }
            }

            for(int i = 0; i < n; i++){
                if(board[i][0] == 'O'){
                    DFS(board,ans,i,0,delrow,delcol);
                }
                if(board[i][m-1] == 'O'){
                    DFS(board,ans,i,m-1,delrow,delcol);
                }
            }
            board = ans;
    }
};