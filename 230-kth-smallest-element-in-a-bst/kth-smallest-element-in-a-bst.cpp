/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> myStack;
        TreeNode* current = root;

        while(current || !myStack.empty())
        {
            while(current)
            {
                myStack.push(current);
                current = current->left;
            }

            current = myStack.top();
            myStack.pop();
            --k;
            if(k==0)
            {
                return current->val;
            }
            current = current->right;
        }
        return -1;
    }
};