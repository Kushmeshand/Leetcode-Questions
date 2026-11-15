class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> q;
        map<char, int> mp;
        
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        for (auto& x : mp) {
            q.push(x.second);
        }
        int cnt = 0;
        while (!q.empty()) {
            int rep = 0;
            vector<int> temp;
            while(!q.empty() && rep < n + 1) {
                int el = q.top();
                q.pop();
                el--;
                temp.push_back(el);
                rep++;
            }
            for(int &x : temp){
                if(x > 0) q.push(x);
            }

            if(q.empty()){
                cnt += temp.size();
            }else{
                cnt += n + 1;
            }
        }
        return cnt;
    }
};