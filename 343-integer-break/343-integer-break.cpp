class Solution {
public:
    int integerBreak(int n) {
        
        if(n == 3) return 2;
        if(n == 2) return 1;
        
        int Product = 1;
        
        while(n>4)
        {
            Product = Product*3;
            n -= 3;
        }
        
        Product *= n;
        
        return Product;

    }
};