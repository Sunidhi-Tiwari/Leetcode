class Solution {
public:
    
    
    int findNumberOfLIS(vector<int>& nums) {
        
     int n = nums.size();
       vector<int> dp(n,1);
       vector<int> cnt(n,1);
       
       int imax = 0;
       for(int i = 1; i<nums.size(); i++)
       {
           for(int j = 0; j<i; j++)
           {
               if(nums[j]<nums[i])
               {
                   if(dp[j] + 1 > dp[i])
                   { 
                       dp[i] = dp[j] + 1;
                       cnt[i] = cnt[j];
                    
                   }
                   
                    else if(dp[j]+1 == dp[i])
                    {
                        cnt[i] += cnt[j];
                    }
                }
               
               
           }
           
           if(dp[i]>=dp[imax]) imax = i;
       }
        
       int total = 0;
       for(int i = 0; i<n; i++) if(dp[i] == dp[imax]) total += cnt[i];
       
        return total;
    }
       
     
    
};