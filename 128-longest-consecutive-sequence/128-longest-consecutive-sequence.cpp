class Solution {
public:
   
        	
        
     int longestConsecutive(vector<int>& nums) {
         	
        set<int> st;
         int len = 0;
         int streak, curnum;
         
         for(auto num:nums) st.insert(num);
         
         for(auto num : nums)
         {
             if(!st.count(num-1))
             {
                 curnum = num;
                 streak = 1;
                 
                 while(st.count(curnum+1))
                 {
                     curnum = curnum + 1;
                     streak++;
                 }
             }
             
             len = max(len, streak);
         }

        return len;
        
    }
};