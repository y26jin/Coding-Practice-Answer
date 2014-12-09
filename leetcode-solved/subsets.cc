class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int>> out;
    if(S.empty()) return out;
        
    sort(S.begin(), S.end());
    for(int i=0;i<=S.size();i++){
      vector<int> temp;
      helper(S,i,temp,0,out);
    }
    return out;
  }
    
  void helper(vector<int> &S, int k, vector<int> &t, int pos, vector<vector<int>> &out){
    if(pos > S.size()) return;
    if(t.size() == k){
      out.push_back(t);
      return;
    }
        
    for(int i=pos;i<S.size();i++){
      t.push_back(S[i]);
      helper(S,k,t,i+1,out);
      t.pop_back();
    }
  }
};
