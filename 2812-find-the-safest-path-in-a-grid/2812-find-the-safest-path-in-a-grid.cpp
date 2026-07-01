class Solution {
public:
    bool solve(vector<vector<int>>& dist, int mid, int row, int col,int delrow[], int delcol[],vector<vector<bool>>& vis) {

        int n = dist.size();
        int m = dist[0].size();
        if(row == n-1 && col == m-1)
            return true;

        vis[row][col] = true;

        for(int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && dist[nrow][ncol] >= mid){
                if(solve(dist, mid, nrow, ncol, delrow, delcol, vis))
                    return true;
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + delrow[k];
                int nc = c + delcol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == INT_MAX){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        int low = 0;
        int high = n + m;
        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(dist[0][0] < mid) {
                high = mid - 1;
                continue;
            }
            vector<vector<bool>> vis(n, vector<bool>(m,false));
            if(solve(dist, mid, 0, 0, delrow, delcol, vis)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};