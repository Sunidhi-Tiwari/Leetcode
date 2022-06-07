class Solution {
public:
    
    string finalstring(string str)
{
    
                             stack<char> st;
                              string rev;
                              for(int i = 0; i<str.length(); i++)
                              {
                                                            if(str[i] == '#')
                                                            {
                                                                                         if(!st.empty()) st.pop();
                                                            }
                                                            
                                                            else
                                                            st.push(str[i]);
                              }
                              
                              while(!st.empty())
                              {
                                           rev += st.top();
                                           st.pop();
                              }
                              
                              return rev;
}
    
    bool backspaceCompare(string s, string t) {
        
         
                              string revs = finalstring(s);
                              string revt = finalstring(t);
                              
                              return (revs == revt);
        
    }
    
};