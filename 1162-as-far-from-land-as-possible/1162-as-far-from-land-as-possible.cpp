class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = -1;
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        if(q.empty() || q.size() == n*m) return -1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol]!=1 && 
                grid[nrow][ncol] == 0){
                    q.push({{nrow,ncol},steps + 1});
                    visited[nrow][ncol] = 1; 
                }
            }
            maxi = max(steps,maxi);
        }
        return maxi;
    }
};