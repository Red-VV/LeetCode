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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode* ptr = head;
        int n = 0;
        while(ptr) {
            ++n;
            ptr = ptr->next;
        }
        reorderList(head, n);
    }
private:
    ListNode* reorderList(ListNode* head, int len) {
        if(len == 1)
            return head;
        if(len == 2)
            return head->next;
        ListNode* tail = reorderList(head->next, len - 2);
        ListNode* tmp = tail->next;
        tail->next = tmp->next;
        tmp->next = head->next;
        head->next = tmp;
        return tail;
    }
};