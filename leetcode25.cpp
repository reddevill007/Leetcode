/*
  25. Reverse Nodes in k-Group
  Hard
  
  Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

  k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

  You may not alter the values in the list's nodes, only nodes themselves may be changed.



  Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
    
  Example 2:
    Input: head = [1,2,3,4,5], k = 3
    Output: [3,2,1,4,5]


  Constraints:
    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000
*/

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
    void reverse(ListNode* s, ListNode* e)
    {
        ListNode* p = NULL, *c = s, *n = s->next;
        while(p != e) {
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1) return head;
        ListNode *s = head, *e = head;
        int inc = k - 1;
        
        while(inc--) {
            e = e->next;
            if(e == NULL) return head;
        }
        ListNode* nextHead = reverseKGroup(e->next, k);
        reverse(s, e);
        s->next = nextHead;
        return e;
    }
};
