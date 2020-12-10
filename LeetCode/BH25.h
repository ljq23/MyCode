#ifndef BH25_H_INCLUDED
#define BH25_H_INCLUDED


/**
Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode *tail = head;
        for(int i=0; i<k; ++i){
            if(tail ==NULL) return head;
            tail = tail->next;
        }
        ListNode *node = fun(head, tail);
        head->next = reverseKGroup(tail,k);
        return node;
    }
    ListNode* fun(ListNode* cur, ListNode* tail){
        ListNode *pre=NULL,*next;
        while(cur!=tail){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
#endif // BH25_H_INCLUDED
