class Solution {
public:
    
    bool isclose(char b)
    {
           if(b == ')' || b =='}' || b == ']') return true;
           return false;
    }
    
     
    bool isopen(char b)
    {
           if(b == '(' || b == '{' || b == '[') return true;
           return false;
    }
    
    
    
    bool isValid(string s) {
        
        stack<char> st;
        
        if(isclose(s[0])) return false;
        if(isopen(s[s.length()-1])) return false;
        
        for(int i = 0; i<s.length(); i++)
        {
            if(isopen(s[i])) {st.push(s[i]); continue;}
            
            if(st.empty()) return false;
            char cur = st.top();
            
            if(s[i] == ')' && cur == '(') {st.pop(); continue;}
            if(s[i] == ']' && cur == '[') {st.pop(); continue;}
            if(s[i] == '}' && cur == '{') {st.pop(); continue;}
               
            return false;                        
            
        }
        
        if(!st.empty())
            return false;
        return true;
        
    }
};