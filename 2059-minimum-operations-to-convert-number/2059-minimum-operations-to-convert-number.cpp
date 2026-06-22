class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> visited(1001, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int cnt = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                int num = q.front();
                q.pop();

                if(num == goal) return cnt;

                for(int x : nums){
                    vector<int> next = {num + x, num - x, num ^ x};
                    for(int nxt : next){
                        if(nxt == goal) return cnt + 1;
                        if(nxt >= 0 && nxt <= 1000 && !visited[nxt]){
                            visited[nxt] = 1;
                            q.push(nxt);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};
