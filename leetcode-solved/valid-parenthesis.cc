class Solution {
public:
  bool isValid(string s) {
    if(s.empty()) return false;
        
    deque<char> t;
    for(int i=0;i<s.length();i++){
      if(s[i] == '(' || s[i] == '[' || s[i] == '{') t.push_front(s[i]);
      if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
	char top = t.front();
	if(! ((s[i]==')' && top=='(') || (s[i]==']' && top=='[') || (s[i]=='}' && top=='{')) ) return false;
	t.pop_front();
      }
    }
        
    if(t.empty()) return true;
    else return false;
  }
};
