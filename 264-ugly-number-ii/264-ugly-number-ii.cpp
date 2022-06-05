class Solution {
public:
    
    
        
    
    int nthUglyNumber(int n) {
        
        
           int ugly[n+1];
           ugly[0] = 0;
           ugly[1] = 1;
           int a = 1, b = 1, c = 1;
           
           for(int i = 2; i<=n; i++)
           {
                                         ugly[i] = min({ugly[a]*2, ugly[b]*3, ugly[c]*5});
                                         if(ugly[i] == ugly[a]*2) a++;
                                         if(ugly[i] == ugly[b]*3) b++;
                                         if(ugly[i] == ugly[c]*5) c++;
           }
        
        return ugly[n];
        
        
    }
};