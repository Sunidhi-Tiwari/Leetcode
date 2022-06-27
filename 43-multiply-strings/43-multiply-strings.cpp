class Solution {
public:
    string multiply(string A, string B) {
        
        // First reverse the string, so that at 0th index we will get integer at unit place, 
    // and so on.
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    // To store our result
    string res;
    
    // We know that when we multiply a numbers having x and y digit respectively, we
    // won't get a resulting number more having more than x+y digits.
    // That's why fill 0's beforehand.
    res.resize(A.size() + B.size(), '0');
    
    // Now start multiplying the numbers, as you do in the paper.
    for (int i = 0; i < A.size(); ++i) {
        int carry = 0;
        for (int j = 0; j < B.size() || carry; ++j) {
            
            // This is an important part of our algorithm, as it stores the result of (i+j)th place.
            int val = res[i+j]-'0'; // we subtract '0' to make it a digit.
            
            int mul = 0;
            // Taking our second digit to multiply, our first digit is (A[i] - '0')
            if (j < B.size()) {
                mul = (B[j] - '0');
            }
            
            // In multiplication we add our result in the end, this is that same addition with carry
            val += (A[i]-'0')*mul + carry;
            
            carry = val/10; // Keep the carry for the next multiplication
            val %= 10; // Since we need to store digit only at the unit place.
            res[i+j] = (val+'0'); // Now assign it to the res, by converting that digit back to the character
        }
    }
    
    // Check condition if result is not equal to 0 and it has a first character as 0 then remove that.
    while ((res.size() > 1) && (res[res.size() - 1] == '0'))
        res.pop_back();
        
    // Now again reverse the number as it is provided in the input.
    reverse(res.begin(), res.end());
    
    // Then return our result.
    return res;
        
    }
};