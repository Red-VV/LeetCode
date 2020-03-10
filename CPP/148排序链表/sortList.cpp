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
    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;

        int length = getListLength(head);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        for(int i = 1; i < length; i = i * 2) {
            ListNode* cur = dummy;
            ListNode* tail = nullptr;
            ListNode* left = dummy->next;
            ListNode* right = nullptr;
            while(left) {
                ListNode* nextList = splitList(i, left, right);
                cur->next = mergeList(left, right, tail);
                cur = tail;
                left = nextList;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
private:
    int getListLength(ListNode* head) {
        int length = 0;
        while(head) {
            head = head->next;
            ++length;
        }
        return length;
    }

    ListNode* splitList(int interval, ListNode* left, ListNode* &right) {
        right = left;
        ListNode *nextList = left;
        ListNode *preNext = nullptr;
        ListNode *preRight = nullptr;
        for(int i = 0; i < interval; ++i) {
            if(right) {
                preRight = right;
                right = right->next;
            }
            if(nextList) {
                preNext = nextList;
                nextList = nextList->next;
            }
            if(nextList) {
                preNext = nextList;
                nextList = nextList->next;
            }
        }
        if(preRight) {
            preRight->next = nullptr;
        }
        if(preNext) {
            preNext->next = nullptr;
        }
        return nextList;
    }

    ListNode* mergeList(ListNode* left, ListNode* right, ListNode* &tail) {
        ListNode* dummy = new ListNode(0);
        dummy->next = nullptr;
        ListNode* ptr = dummy;
        while(left && right) {
            if(left->val < right->val) {
                ptr->next = left;
                left = left->next;
            } else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        if(left) {
            ptr->next = left;
        }
        if(right) {
            ptr->next = right;
        }
        tail = ptr;
        while(tail->next) {
            tail = tail->next;
        }
        ListNode* newList = dummy->next;
        delete dummy;
        return newList;
    }
};