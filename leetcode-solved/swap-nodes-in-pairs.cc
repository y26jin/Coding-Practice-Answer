class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if(!head || !head->next) return head;
        
    ListNode *t1 = head, *t2 = head->next;
    ListNode *temp = t2->next;
    t1->next = swapPairs(temp);
    t2->next = t1;
    return t2;
  }
};
