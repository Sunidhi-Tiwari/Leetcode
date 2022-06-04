/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
      
        
        ListNode* fast;
        ListNode* slow;
        ListNode* notcycle = NULL;
        
        fast = slow = head;
         if(!head || !head->next) return notcycle;
        int flag = false;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast)
            {flag = true;
             break;}
        }
        
        
        ListNode* entry = head;
        
        if(!flag) return notcycle;
        
        while(slow != entry)
        {
            slow = slow->next;
            entry = entry -> next;
        }
        
        return entry;
    }
};