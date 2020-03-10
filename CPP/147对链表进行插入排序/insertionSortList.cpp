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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return head;
        ListNode* dummy_node = new ListNode();
        ListNode* new_head = dummy_node;
        ListNode* ptr = head;
        while(ptr) {
            ListNode* nptr = new_head;
            while(nptr->next != nullptr && nptr->next->val < ptr->val) {
                nptr = nptr->next;
            }
            ListNode *tmp = ptr;
            ptr = ptr->next;
            tmp->next = nptr->next;
            nptr->next = tmp;
        }
        new_head = new_head->next;
        delete dummy_node;
        return new_head;
    }
};