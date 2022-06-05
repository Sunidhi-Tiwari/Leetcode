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
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* temp;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // finding mid part
        while(fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Dividing two parts
        temp->next = NULL;
        
        //Divide and Conquer
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergelist(l1,l2);
        
    }
    
    ListNode* mergelist(ListNode* l1, ListNode* l2)
        
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode* ptr;
        
        if(l1->val <= l2->val)
        {
            ptr = l1;
            l1 = l1->next;
        }
        else
        {
            ptr = l2;
            l2 = l2->next;
        }
        
        ListNode* cur;
        
        cur = ptr;
        
        while(l1 && l2)
        {
             if(l1->val <= l2->val)
             {
                 cur->next = l1;
                 
                 l1 = l1->next;
                 
             }
            else
            {
                cur->next = l2;
                
                l2 = l2->next;
            }
            
            cur = cur->next;
             
        }
        
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        
        return ptr;
        
    }
};