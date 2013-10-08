/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        vector<int> line;
        while(true)
        {
            TreeNode* cur = que.front(); que.pop();
            if(cur == NULL)
            {
                ans.push_back(line);
                line.clear();
                if(que.empty())
                    break;
                que.push(NULL);
                continue;
            }
            line.push_back(cur->val);
            if(cur->left)
            {
                que.push(cur->left);
            }
            if(cur->right)
            {
                que.push(cur->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
