/* Invert a Binary Tree! */

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode* top = Q.front();
            Q.pop();
            
            if(top->left!=NULL)
                Q.push(top->left);
            if(top->right !=NULL)
                Q.push(top->right);
            
            TreeNode* tmp = top->left;
            top->left = top -> right;
            top->right = tmp;
        }
        return root;
    }
};