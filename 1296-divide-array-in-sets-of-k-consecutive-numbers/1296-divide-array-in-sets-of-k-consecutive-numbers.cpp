class Solution {
public:
    
    
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        
        map<int,int> mp;
        int n = nums.size();
        map<int, int>:: iterator it;
        
        if(n%k != 0) return false;
        
        for(int i = 0; i<n; i++)
        {
            mp[nums[i]]++;
           
         
        }
        
        for(it = mp.begin(); it!= mp.end(); it++)
        {
            if(it->second)
            {
                int freq = it->second;
                
                for(int i = 0; i<k; i++)
                {
                    if(mp[it->first+i]<freq)
                        return false;
                    else
                        mp[it->first+i] -= freq;
                    
                }
            }
        }

        
       return true;
      
        
        
    }
};