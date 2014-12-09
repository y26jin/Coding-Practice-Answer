class Solution {
public:
  bool compare_rest(vector<string> &strs, string s, int pos){
    for(int i=1;i<strs.size();i++){
      string temp = strs[i].substr(0,pos);
      if(temp != s) return false;
    }
    return true;
  }

  string longestCommonPrefix(vector<string> &strs) {
    string out;
    if(strs.empty()) return out;
        
    int i=0,flag = 0;
    for(i=strs[0].length()-1;i>=0;i--){
      if(compare_rest(strs,strs[0].substr(0,i+1), i+1)){
	flag = 1;
	break;
      }
    }
    if(flag == 0) return out;
    else{
      out = strs[0].substr(0,i+1);
      return out;
    }
  }
};
