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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *fast;
        ListNode *slow;
        
        int cntf = 0, cnts = 0;
        
        fast = head;
        slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next;
            cntf++;
            
            if( n != 1 && cntf>=n)
            {
                slow = slow->next;
                
            }
            
            if( n == 1 && cntf>n)
            {
                slow = slow->next;
                
            }
            
           
            
           
        }
        
        if(fast == head)
            return head->next;
        
        if(n>1)
        {
        ListNode* temp;
        temp = slow->next;
        slow->val = temp->val;
        slow->next = temp->next;
        delete temp;
        }
        else
        {
             slow->next = NULL;
             delete fast;
                 
            
        }
        
        
            
        
        return head;
        
    }
};