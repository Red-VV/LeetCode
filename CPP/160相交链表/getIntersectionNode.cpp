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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getListLength(headA);
        int lengthB = getListLength(headB);
        int subAB =  lengthA - lengthB;
        int subBA = -subAB;
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        for(int i = 0; i < subAB; ++i) {
            ptrA = ptrA->next;
        }
        for(int i = 0; i < subBA; ++i) {
            ptrB = ptrB->next;
        }
        while(ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
    int getListLength(ListNode *head) {
        int length = 0;
        ListNode *ptr = head;
        while(ptr) {
            ++length;
            ptr = ptr->next;
        }
        return length;
    }
};