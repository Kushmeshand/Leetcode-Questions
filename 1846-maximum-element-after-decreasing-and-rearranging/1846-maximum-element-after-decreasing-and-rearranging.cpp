class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int element = 0;
        int ind = 0;
        sort(begin(arr),end(arr));
        if(arr[0]==1){
            for(int i = 1; i < n; i++){
                int diff = abs(arr[i] - arr[i-1]);
                if(diff>1){
                   arr[i] = arr[i-1] + 1;
                }
            }
        }
        else{
            arr[0] = 1;
             for(int i = 1; i < n; i++){
                int diff = abs(arr[i] - arr[i-1]);
                if(diff>1){
                   
                  arr[i] = arr[i-1] + 1;
                }
            }
        }
        int maxi = *max_element(arr.begin(), arr.end());
        return maxi;
    }
};