class Solution {
public:
   
        	
        
     int longestConsecutive(vector<int>& nums) {
         	
         unordered_set<int> st;
         int len = 0;
        
         
         for(auto num:nums) st.insert(num);
         
         for(auto num : nums)
         {
             if(!st.count(num-1))
             {
                 int curnum = num;
                 int streak = 1;
                 
                 while(st.count(curnum+1))
                 {
                     curnum = curnum + 1;
                     streak++;
                     
                     
                 }
                 
                  len = max(len, streak);
             }
             
            
         }

        return len;
        
    }
};