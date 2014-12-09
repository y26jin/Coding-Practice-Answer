class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int>> combo;
    if(n==0 || n<k) return combo;
        
    vector<int> temp;
    rec(combo, temp, n, k, 0);
    return combo;
  }
  void rec(vector<vector<int>> &combo, vector<int> &temp, int n, int k, int s){
    if(k == 0){
      combo.push_back(temp);
      return;
    }
        
    for(int i=s;i<n;i++){
      temp.push_back(i+1);
      rec(combo,temp,n,k-1,i+1);
      temp.pop_back();
    }
  }
};
