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
  TreeNode *helper(vector<int> &preorder, int pa, int pb, vector<int> &inorder, int ia, int ib){
    if(pa>pb && ia>ib) return NULL;
    TreeNode *root = new TreeNode(preorder[pa]);
    if(pa==pb && ia==ib) return root;
        
    int loc;
    for(int i=ia;i<=ib;i++){
      if(inorder[i] == preorder[pa]){
	loc = i;
	break;
      }
    }
    int left_len = loc-1-ia+1;
    TreeNode *l = helper(preorder, pa+1, pa+1+left_len-1, inorder, ia, loc-1), *r = helper(preorder, pa+1+left_len, pb, inorder, loc+1, ib);
    root->left = l;
    root->right = r;
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if(preorder.empty() || inorder.empty()) return NULL;
        
    return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
  }
};
