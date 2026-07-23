class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dist(n+1,INT_MAX);
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        dist[k] = 0;
        q.push({0,k});

        while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second;
            q.pop();

            for(auto &[v,w] : adj[node]){
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    q.push({d+w,v});
                }
            }
        }
        int mini = 0;
        for(int i = 1; i < n+1; i++){
            if(dist[i] == INT_MAX) return -1;
            mini = max(mini,dist[i]);
        }
        return mini;
    }
};