/*
  206. Reverse Linked List
  Easy

  Given the head of a singly linked list, reverse the list, and return the reversed list.



  Example 1:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
    
  Example 2:
      Input: head = [1,2]
      Output: [2,1]
      
  Example 3:
    Input: head = []
    Output: []


  Constraints:
    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000
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
    ListNode* reverse(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode* reverseHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return reverseHead;
    }
    
    ListNode* reverseList(ListNode* head) {
//         if(head == NULL) return NULL;
//         ListNode* p = NULL, *c = head, *n = head->next;
        
//         // itterative method
//         while(c != NULL)
//         {
//             c->next = p;
//             p = c;
//             c = n;
//             if(n != NULL) n = n->next;
//         }
//         return p;
//       recursive solution
        if(head == NULL) return NULL;
        return reverse(head);
    }
};
