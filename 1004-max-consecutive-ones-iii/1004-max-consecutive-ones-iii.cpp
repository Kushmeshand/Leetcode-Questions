class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end,count=0;
        int maxi=-1;
        for(end=0;end<nums.size();end++)
        {
            if(nums[end]==0) count++;
            if(count>k)
            {
                
                if(nums[start]==0) 
                {
                    count--;
                }
                start++;
            }
        }
        return end-start;
    }
};