class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
           
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //step 1.use fast and slow pointer approacch to find mid node of list
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        //step 2.reverse the second half list and split the list into two
        
        ListNode* second = reverse(slow->next);
        slow->next = NULL;
        ListNode* first = head;
        
        
        //step 3.merge the list
        
        while(second)
        {
             ListNode* temp1 = first->next;
             ListNode* temp2 = second->next;
             first->next = second;
             second->next = temp1;
             first = temp1;
             second = temp2;
        }
    }
};