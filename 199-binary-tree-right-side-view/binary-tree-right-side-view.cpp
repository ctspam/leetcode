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
    vector<int> rightSideView(TreeNode* root) {
        //make a queue and a vector, and push the root into the queue
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* rightSide = nullptr;
            //now you want to traverse the list since its bfs and then keep track of every level
            int qLength = q.size();
            for(int i = qLength; i > 0; --i) // keep updating, the last node we see in this level will be the rightmost node
            {
                TreeNode* node = q.front();
                q.pop();
            
                if(node)
                {
                    rightSide = node; //now the right side will always be the node, then we puhs the children into the queue for a reprocess
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            // after finishing this level, add the rightmost node to the result
            if(rightSide)
            {
                result.push_back(rightSide->val);
            }
        }
        return result;
    }
};