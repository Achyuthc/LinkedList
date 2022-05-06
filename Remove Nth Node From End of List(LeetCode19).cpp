/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=NULL,*fast=head;
        int cnt=0;
        while(fast)
        {
            fast=fast->next;
            if(slow)
                slow=slow->next;
            if(cnt==n)
                slow=head;
            cnt++;
        }
        if(!slow)
            return head->next;   
        if(slow->next&&slow->next)
        slow->next=slow->next->next;
        return head;
    }
};
