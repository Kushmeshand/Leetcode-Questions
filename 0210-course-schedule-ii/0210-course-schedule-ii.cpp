class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,vector<int>> adj;
        queue<int> q;
        int n = numCourses;
        vector<int> indegree(n,0);
        vector<int> res;
        int m = prerequisites.size();
        for(auto &a : prerequisites){
            indegree[a[0]]++;
        }
        for(auto &a : prerequisites){
            adj[a[1]].push_back(a[0]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                    res.push_back(v);
                }
            }
        }
        return (res.size() == n ? res : vector<int>{});
    }
};