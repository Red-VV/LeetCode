/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->gHead = head;
        int size = findListSize(this->gHead);
        return sortedListToBST(0, size - 1);
    }
private:
    ListNode* gHead;
    int findListSize(ListNode* head) {
        int count = 0;
        while(head) {
            ++count;
            head = head->next;
        }
        return count;
    }
    TreeNode* sortedListToBST(int low, int high) {
        if(low > high)
            return nullptr;
        int mid = (low + high) / 2;
        TreeNode* left = sortedListToBST(low, mid - 1);
        int rootVal = this->gHead->val;
        TreeNode* root = new TreeNode(rootVal);
        this->gHead = this->gHead->next;
        root->left = left;
        TreeNode* right = sortedListToBST(mid + 1, high);
        root->right = right;
        return root;
    }
};
