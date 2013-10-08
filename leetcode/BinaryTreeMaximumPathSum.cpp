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
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        std::stack<TreeNode*> st;
        std::set<TreeNode*> check;
        std::map<TreeNode*, pair<int, int> > dp;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            if(cur->left && check.find(cur->left) == check.end())
            {
                check.insert(cur->left);
                st.push(cur->left);
                continue;
            }
            if(cur->right && check.find(cur->right) == check.end())
            {
                check.insert(cur->right);
                st.push(cur->right);
                continue;
            }
            st.pop();
            pair<int, int> l(-(1<<29), -(1<<29)), r(-(1<<29), -(1<<29));
            int max_path, max_path_to_root;
            if(cur->left)
                l = dp[cur->left];
            if(cur->right)
                r = dp[cur->right];
            max_path_to_root = max(cur->val, max(l.first+cur->val, r.first+cur->val));
            max_path = max(max_path_to_root, max(max(l.second, r.second), l.first+r.first+cur->val));
            dp[cur] = make_pair(max_path_to_root, max_path);
        }
        return dp[root].second;
    }
};
