/*
  21. Merge Two Sorted Lists
  Easy

  You are given the heads of two sorted linked lists list1 and list2.

  Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

  Return the head of the merged linked list.

  Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]
    
  Example 2:
    Input: list1 = [], list2 = []
    Output: []
    
  Example 3:
    Input: list1 = [], list2 = [0]
    Output: [0]

  Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
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
    // ListNode* merge(ListNode* l1, ListNode* l2) {
    //     if(l1 == NULL) return l2;        
    //     if(l2 == NULL) return l1;
    //     if(l1->val < l2->val) {
    //         l1->next = merge(l1->next, l2);
    //         return l1;
    //     }
    //     else {
    //         l2->next = merge(l1, l2->next);
    //         return l2;
    //     }
    // }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // return merge(l1, l2);
        if(l1 == NULL) return l2;        
        if(l2 == NULL) return l1;
        ListNode* ans = new ListNode(-1);
        ListNode *tail = ans;
        
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        
        if(l1 == NULL) tail->next = l2;
        else tail->next = l1;
        return ans->next;
    }
};
