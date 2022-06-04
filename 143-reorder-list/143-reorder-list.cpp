/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        
        if((!head) || (!head->next) || (!head->next->next)) return;
        
        stack<ListNode*> st;
        
        ListNode* ptr = head;
        
        int cnt = 0;
        
        while(ptr != NULL)
            
        {
            st.push(ptr);
            ptr = ptr->next;
            cnt++;
        }
        
        ptr = head;
        
        for(int i = 0; i<cnt/2; i++)
        {
            
            ListNode* element = st.top();
            st.pop();
            element->next = ptr->next;
            ptr->next = element;
            ptr = ptr->next->next;
            
        
        }
        
        ptr->next = NULL;
        
        
        
    }
};