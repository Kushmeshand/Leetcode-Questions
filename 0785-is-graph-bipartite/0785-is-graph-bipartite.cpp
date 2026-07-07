class Solution {
private: 
     bool dfs(int node, vector<int>& col, vector<vector<int>>& graph,
             int color) {
        col[node] = color;
        for (auto it : graph[node]) {
            if (col[it] == -1) {
                if (!dfs(it, col, graph, !color))
                    return false;

            } else if (col[it] == color) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                if (!dfs(i, col, graph, 0))
                    return false;
            }
        }
        return true;
    }
};