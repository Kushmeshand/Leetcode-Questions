class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        for(int i = 0; i < n; i++)  dist[i][i] = 0;

        for(auto &x : edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(dist[j][i] != INT_MAX && dist[i][k] != INT_MAX){
                       dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
                    }
                }
            }
        }
        int ans = 0;
        int cnt = n;
        for(int j = 0; j < n; j++){
            int city = 0;
            for(int k = 0; k < n; k++){
                if(dist[j][k] <= threshold){
                    city++;
                }
            }
            if(city <= cnt){
                cnt = city;
                ans = j;
            }
        }
        return ans;
    }
};