class Solution {
    
    
 public:
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
       vector<int> ans;
       
       int maxo = 0;
       int total = (1<<12);
       
        for(int i = 0; i<total; i++)
        {
            vector<int> temp(12,0);
            
            int count = numArrows;
            int sum = 0;
            for(int j = 0; j<12; j++)
            {   
                if( i & (1<<j) )
                {
                    if(aliceArrows[j] + 1 <= count)
                    {
                        count -= aliceArrows[j] + 1;
                        temp[j] = aliceArrows[j] + 1;
                    }
                }
            }
            
            
             if(count){
                int pos=0,mini=INT_MAX;
                for(int i=11;i>=0;i--){
                    if(temp[i]<mini){
                        mini=temp[i];
                        pos=i;
                    }
                }
                temp[pos]=count;
                count=0;
             }
                 
                 
            
            for(int i = 0; i<12; i++)
            {
                if(temp[i] > aliceArrows[i])
                    sum += i;
            }
            
             
            if(sum>maxo)
            {
                ans = temp;
                maxo = sum;
            }
            
                 
    }
        return ans;
    }
};