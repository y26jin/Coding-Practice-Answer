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
  void helper(vector<vector<int>> &out, int sum, vector<int> list, TreeNode *t, int temp){
    if(!t->left && !t->right){
      temp += t->val;
      if(temp == sum){
	list.push_back(t->val);
	out.push_back(list);
      }
      return;
    }
        
    if(t->left){
      list.push_back(t->val);
      helper(out,sum,list,t->left,temp+t->val);
      list.pop_back();
    }
    if(t->right){
      list.push_back(t->val);
      helper(out,sum,list,t->right,temp+t->val);
      list.pop_back();
    }
        
  }
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int>> out;
    if(!root) return out;
        
    vector<int> l;
    helper(out,sum,l,root,0);
        
    return out;
  }
};
