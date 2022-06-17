class Solution {
public:
    
   
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
       
        int n = startTime.size();
         vector<vector<int>> jobs(n);
        
        
        for(int i = 0; i<n; i++)
            jobs[i]  = {startTime[i], endTime[i], profit[i]};
        
         sort(jobs.begin(), jobs.end(), comp);
        
         int dp[n]; 
         dp[0] = jobs[0][2];
        
        for(int i = 1; i<n; i++)
        {   
            
            int inc = jobs[i][2];
            int exc = dp[i-1];
            int low = 0;
            int high = i-1;
            int last = -1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                
                if(jobs[mid][1] <= jobs[i][0] )
                {
                    last = mid;
                    low = mid+1;
                }
                else
                    high = high - 1;
            }
            
            if(last!= -1) inc += dp[last];
            dp[i] = max(inc, exc);
            
         }
        
        return dp[n-1];
    }
};