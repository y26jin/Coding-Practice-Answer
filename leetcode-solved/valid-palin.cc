class Solution {
public:
  bool isPar(string s){
    int low = 0, hi = s.length()-1;
    while(low<hi){
      if(s[low] != s[hi]) return false;
      low++;
      hi--;
    }
    return true;
  }
  bool isPalindrome(string s) {
    if(s.length()==0) return true;
    if(s.length()==1) return true;
        
    string new_s;
    for(int i=0;i<s.length();i++){
      if(s[i] >= 'a' && s[i] <= 'z'){
	new_s += s[i];
      }
      if(s[i] >= '0' && s[i] <= '9'){
	new_s += s[i];
      }
      if(s[i] >= 'A' && s[i] <= 'Z'){
	new_s += s[i]-'A'+'a';
      }
    }
    return isPar(new_s);
  }
};
