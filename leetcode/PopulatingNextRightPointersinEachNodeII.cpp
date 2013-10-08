/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        TreeLinkNode* line_tail = root;
        TreeLinkNode* cur = root;
        TreeLinkNode* tail = root;
        while(cur != NULL)
        {
            if(cur->left)
            {
                tail->next = cur->left;
                tail = cur->left;
            }
            if(cur->right)
            {
                tail->next = cur->right;
                tail = cur->right;
            }
            if(cur == line_tail)
            {
                cur = cur->next;
                line_tail->next = NULL;
                line_tail = tail;
            }
            else
                cur = cur->next;
        }
    }
};
