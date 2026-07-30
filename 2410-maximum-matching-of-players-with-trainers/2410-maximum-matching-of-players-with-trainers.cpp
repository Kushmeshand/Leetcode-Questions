class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int n = players.size();
        int m = trainers.size();
        int l = 0,r = 0;
        while(r<m && l<n){
            if(players[l] <= trainers[r]){
                l++;
            }
            r++;
        }
        return l;
    }
};