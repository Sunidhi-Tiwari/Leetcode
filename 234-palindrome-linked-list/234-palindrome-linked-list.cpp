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
    ListNode* reverseList(ListNode* head)
{  
    if(!head || !head->next) return head;
    
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* n;
    
    while(cur)
    {
        n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }
    
   return prev; 
}
    
    bool isPalindrome(ListNode* A) {
        
          if(!A) return 1;
    if(!A->next) return 1;
    
    
    
    ListNode* fast = A;
    ListNode* slow = A;
    ListNode* h1 = A;
    ListNode* temp;
    
    while(fast && fast->next)
    {   
        temp = slow;
        fast = fast->next->next;
        slow = slow->next;
        
    }
    
    ListNode* h2 = reverseList(slow);
    temp->next = NULL;
    
    bool flag = 1;
    
    while(h2 && h1)
    {
        if(h1->val != h2->val)
        {   
             flag = 0;
             break;
        }
        
        h1 = h1->next;
        h2 = h2->next;
    }
    
    return flag;

        
    }
};