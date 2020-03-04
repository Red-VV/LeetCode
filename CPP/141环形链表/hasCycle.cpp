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
        if(!head)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        for( ; ; ) {
            for(int i = 0; i < 2; ++i) {
                fast = fast->next;
                if(fast == nullptr)
                    return false;
                if(fast == slow)
                    return true;
            }
            slow = slow->next;
            if(fast == slow)
                return true;
        }
    }
};