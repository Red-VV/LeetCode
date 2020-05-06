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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        vector<int> ret;
        while(head != nullptr)
        {
            ret.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int j = ret.size() - 1;
        while(i < j) {
            if(ret[i] != ret[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};