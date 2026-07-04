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
class Solution
{
public:
  bool isLeaf(TreeNode *node)
  {
    if (node->left == nullptr && node->right == nullptr)
      return true;
    return false;
  }
  bool solve(TreeNode *root, int sum, int targetSum)
  {
    if (root == nullptr)
      return false;
    sum += root->val;
    if (isLeaf(root) && sum == targetSum)
      return true;
    // if(sum > targetSum) return false;

    if (solve(root->left, sum, targetSum) || solve(root->right, sum, targetSum))
      return true;
    return false;
  }
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    return solve(root, 0, targetSum);
  }
};