class Solution {
public:
    int myAtoi(string A) {
        
         if(A.size()==0) return 0;
    int i=0,sign=0; // sign = 0, means positive, otherwise false.
    
    // Ignore all space character at the beginning
    while(A[i]&&A[i]==' ') i++; 
    
    // Check for its sign, if sign remains zero, that means it is positive,
    // otherwise negative.
    if(A[i]=='-'||A[i]=='+'){
        if(!A[i+1]) return 0;
        if(A[i+1]<'0'||A[i+1]>'9') return 0;
        if(A[i]=='-') sign=1; 
        i++;
    }
    // Take a temporary long variable, long is convenient to use because of overflow.
    // If you don't want to use long, you can add extra conditions before adding extra 
    // digit in x.
    long long x=0; 
    // Keep iterating the string until you reach to the end or 
    // until you find any garbage character
    while(A[i]&&A[i]>='0'&&A[i]<='9'){ 
        x = x*10 + (A[i]-'0'); // Keep apending the digit in order
        if(x>INT_MAX){ // In case of overflow, check for its sign and return accordingly.
            if(sign) return INT_MIN;
            return INT_MAX;
        }
        i++;
    }
    // With respect to sign return the newly generated integer.
    if(sign) return -x; 
    return x;
        
    }
};