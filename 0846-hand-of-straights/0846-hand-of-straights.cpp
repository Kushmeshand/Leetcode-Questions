class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mpp;
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        for (int x : hand) {
            mpp[x]++;
        }
        while(!mpp.empty()) {
            int curr = mpp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (mpp.find(curr + i) == mpp.end()) {
                    return false;
                }
                mpp[curr + i]--;
                if (mpp[curr  + i] == 0)
                    mpp.erase(curr + i);
            }
        }
        return true;
    }
};