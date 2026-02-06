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
            for(int i = qLength; i > 0; --i) //this ensures you always get the right side by running the amount of sizes
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
            //after you get the queues and the right sides, after each queue ends and you get the right side you want to puhs that into result
            if(rightSide)
            {
                result.push_back(rightSide->val);
            }
        }
        return result;
    }
};