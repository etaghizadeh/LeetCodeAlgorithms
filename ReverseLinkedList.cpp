/*   Reverse a singly linked list. */

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
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp, *counter = head, *pre = NULL;
        while(counter)
        {
            tmp = counter-> next;
            counter->next = pre;
            pre = counter;
            counter = tmp;
        }
        return pre;
    }
    
};