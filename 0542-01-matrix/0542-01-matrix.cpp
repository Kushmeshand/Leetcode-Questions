class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            dis[i][j] = d;
            q.pop();
            for (int t = 0; t < 4; t++) {
                int r = dr[t] + i;
                int c = dc[t] + j;
                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]) {
                    vis[r][c] = 1;
                    q.push({{r, c}, d + 1});
                }
            }
        }
        return dis;
    }
};