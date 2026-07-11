class Solution {
public:
    void DFS( unordered_map<int,vector<int>>& adj,vector<int>& visited,int u,int &edge,int &ver){
        if(visited[u]) return; 
        visited[u] = true;
        ver++;
        
        for(int &x : adj[u]){
            edge++;
            if(!visited[x]){
                DFS(adj,visited,x,edge,ver);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        unordered_map<int,vector<int>> adj;
        vector<int> visited(n,false);

        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt = 0;
       
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int edge = 0;
                int ver = 0;
                DFS(adj,visited,i,edge,ver);
                if(edge == ver*(ver-1)){
                    cnt++;
                }
            }

        }
        
        return cnt;
    }
};