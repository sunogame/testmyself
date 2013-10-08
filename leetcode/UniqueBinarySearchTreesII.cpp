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
    vector<TreeNode*> gen(int l, int r)
    {
        if( l > r )
            return vector<TreeNode*>(1, (TreeNode*)NULL);
        vector<TreeNode*> ans;
        for(int i=l;i<=r;i++)
        {
            vector<TreeNode* > left = gen(l, i-1);
            vector<TreeNode* > right = gen(i+1, r);
            for(int li=0;li<left.size();li++)
            {
                for(int ri=0;ri<right.size();ri++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[li];
                    root->right = right[ri];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }


    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<TreeNode*> ans = gen(1, n);
        return ans;
    }
};

