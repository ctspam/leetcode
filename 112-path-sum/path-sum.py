# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode | None, targetSum: int) -> bool:
        # we want to run this recursively till we find a leaf and then it should find a diff path, DFS

        # base case for if current node is null return F
        if not root:
            return False
        # if the curr node doesn't have left and right child, then sub the ucrrent value from target sum, when the answer is 0 return true and not reutnr false
        if not root.left and not root.right:
            return targetSum - root.val == 0
        #move on so sub current val from target sum
        targetSum -= root.val
        #call if recurviely for left or right
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)
        