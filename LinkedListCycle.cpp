/*    Given a linked list, determine if it has a cycle in it.
 
 Follow up:
 Can you solve it without using extra space?
 
 */

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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
            if(fast)
                fast = fast->next;
            if(slow == fast)
                break;
        }
        if(fast && fast == slow)
            return true;
        
        return false;
    }
    
};