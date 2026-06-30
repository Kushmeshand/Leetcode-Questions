class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr={-1,-1,-1};
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']=i;
            int mini = min(arr[0],min(arr[1],arr[2]));
            cnt = cnt + (mini+1);

        }
        return cnt;
    }
};