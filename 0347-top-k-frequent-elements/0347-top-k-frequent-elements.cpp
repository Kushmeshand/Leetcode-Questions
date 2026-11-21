class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int n = nums.size();
        for(auto x : nums){
            mp[x]++;
        }
        for(auto y : mp){
            pq.push({y.second,y.first});
        }
        
        while(k--){
            auto [freq,el] = pq.top();
            pq.pop();

            ans.push_back(el);
        }
        return ans;
    }
};