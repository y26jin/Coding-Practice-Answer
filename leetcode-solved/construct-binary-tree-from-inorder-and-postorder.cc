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
  TreeNode *helper(vector<int> &inorder, int ia, int ib, vector<int> &postorder, int pa, int pb){
    if(ia>ib && pa>pb) return NULL;
        
    TreeNode *root = new TreeNode(postorder[pb]);
    if(ia==ib && pa==pb) return root;
        
    int loc;
    for(int i=ia;i<=ib;i++){
      if(inorder[i] == postorder[pb]){
	loc = i;
	break;
      }
    }
                    
    TreeNode *l = helper(inorder,ia,loc-1,postorder,pa,pa+loc-ia-1), *r = helper(inorder,loc+1,ib,postorder,pa+loc-ia,pb-1);
    root->left = l;
    root->right = r;
    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if(inorder.empty() || postorder.empty()) return NULL;
        
    return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
  }
};
