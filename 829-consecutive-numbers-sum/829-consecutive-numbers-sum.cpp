class Solution {
public:
    int consecutiveNumbersSum(int n) {
        
       
                             
                              int cnt = 0;
                              
                              for(int k = 1; 2*n > k*(k-1); k++)
                              {
                                                            int numerator = n - (k*(k-1)/2);
                                                            
                                                            if(numerator%k == 0)
                                                            {
                                                            
                                                            cnt++;
                                                            }
                              }
        
        return cnt;
                              
     }
};