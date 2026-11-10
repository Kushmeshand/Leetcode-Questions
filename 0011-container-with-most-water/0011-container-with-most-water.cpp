class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;
        while(left < right){
                int count = (right-left)*min(height[left],height[right]);
                area = max(area,count);
                if(height[left]<height[right]){
                    left++;
                }
                else{
                    right--;
                }
        }
        return area;
    }
};