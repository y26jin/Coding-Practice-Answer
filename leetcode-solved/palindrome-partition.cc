class Solution {
public:
  bool isP(string s, int a, int b){
    if(a>b || s.empty()) return false;
    int i=a,j=b;
    while(i<j){
      if(s[i]!=s[j]) return false;
      i++;
      j--;
    }
    return true;
  }
  void helper(vector<vector<string>> &out, string s, vector<string> &t, int a){
    if(a == s.length()){
      out.push_back(t);
      return;
    }
    for(int i=a;i<s.length();i++){
      if(isP(s,a,i)){
	string temp = s.substr(a,i-a+1);
	t.push_back(temp);
	helper(out,s,t,i+1);
	t.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> out;
    if(s.empty()) return out;
        
    vector<string> temp;
    helper(out,s,temp,0);
    return out;
  }
};
