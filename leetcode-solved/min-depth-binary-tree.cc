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
  int minDepth(TreeNode *root) {
    if(!root) return 0;
        
    int left = minDepth(root->left), right = minDepth(root->right);
    if(left == 0 && right == 0) return 1;
    else if(left == 0) return right+1;
    else if(right == 0) return left+1;
    else return left<right?left+1:right+1;
  }
};
