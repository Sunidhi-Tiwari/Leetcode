class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        
        int l = 0;
        int r = n-1;
        
        int maxvol = 0;
        
        while(l<=r)
        {
            maxvol = max(maxvol, min(height[l], height[r])*(r-l));
            if(height[r]>height[l]) l++;
            else r--;
        }
        
        return maxvol;
        
    }
};