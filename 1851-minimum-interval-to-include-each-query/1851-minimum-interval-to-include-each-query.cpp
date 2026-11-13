
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int j = 0;

        for (auto& [query, idx] : q) {

            while (j < intervals.size() &&
                   intervals[j][0] <= query) {

                int len = intervals[j][1] - intervals[j][0] + 1;

                pq.push({len, intervals[j][1]});

                j++;
            }

            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};
