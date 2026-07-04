class Solution {
public:
    void DFS(int n,unordered_map<int,vector<pair<int,int>>>& adj, vector<int>& visited,int u,int &mincost){
        if(visited[u]) return;
        visited[u] = true;
        for(auto &[v,w] : adj[u]){
            mincost = min(mincost, w);
            if(!visited[v]){
               DFS(n,adj,visited,v,mincost);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;
        vector<int> visited(n+1,false);
        int m = roads.size();
        for(auto &v : roads){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        } 
        int mincost = INT_MAX;
        int mini = INT_MAX;
        DFS(n,adj,visited,1,mincost);
        mini = min(mincost,mini);  
        return mini;
    }
};