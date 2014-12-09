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
  ListNode *sortList(ListNode *head) {
    if(!head || !head->next) return head;
        
    ListNode *a,*b;
    split(head,&a,&b);
        
    ListNode *aa = sortList(a);
    ListNode *bb = sortList(b);
        
    ListNode *out = merge(aa,bb);
    return out;
  }
    
  ListNode *merge(ListNode *a, ListNode *b){
    if(!a && !b) return NULL;
    if(!a && b) return b;
    if(a && !b) return a;
        
    ListNode *out=NULL;
    if(a->val <= b->val){
      out = a;
      out->next = merge(a->next,b);
    }
    else{
      out = b;
      out->next = merge(a,b->next);
    }
    return out;
  }
    
  void split(ListNode *head, ListNode **a, ListNode **b){
    ListNode *fast,*slow,*prev;
    slow=fast=head;
    while(fast && fast->next)
      {
	prev=slow;
	slow=slow->next;
	fast=fast->next->next;
      }
    *a=head;
    *b=slow;
    prev->next=NULL;
  }
    
};
