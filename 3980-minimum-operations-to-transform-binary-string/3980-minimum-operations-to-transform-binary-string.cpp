class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int cnt1 = 0;
        int cnt2 = 0;
        if(n == 1) return s1 == s2 ? 0: s1[0] == '0' ? 1: -1;
        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i]) continue;

            if(s1[i] == '0'){
                cnt1++;
            }

            else if(i+1 < n && s1[i+1] == '1' && s2[i+1] == '0'){
                      cnt2++;
                      i++;
            }
            else cnt2 += 2; 
            }
        return cnt1+cnt2;
    }
};