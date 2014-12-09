class Solution {
public:
  void helper(string s, vector<string> &t, int pos, vector<string> &out){
    if(pos > s.length() - 1) return;
    if(t.size() == 3){
      if(s[pos] == '0' && pos == s.length()-1){
	string temp_s;
	for(int i=0;i<3;i++){
	  temp_s += t[i];
	  temp_s += ".";
	}
	temp_s += "0";
	out.push_back(temp_s);
	return;
      }
      else if((s[pos] == '1' || s[pos] == '2') && pos >= s.length()-3 && pos <= s.length()-1){
	int temp_n = 0;
	for(int i=pos;i<s.length();i++){
	  temp_n *= 10;
	  temp_n += s[i]-'0';
	}
	if(temp_n >= 0 && temp_n <= 255){
	  string temp_s;
	  for(int i=0;i<3;i++){
	    temp_s += t[i];
	    temp_s += ".";
	  }
	  temp_s += s.substr(pos,s.length()-pos);
	  out.push_back(temp_s);
	  return;
	}
      }
      else if(s[pos] >= '3' && s[pos] <= '9' && pos >= s.length()-2 && pos <= s.length()-1){
	string temp_s;
	for(int i=0;i<3;i++){
	  temp_s += t[i];
	  temp_s += ".";
	}
	temp_s += s.substr(pos,s.length()-pos);
	out.push_back(temp_s);
	return;
      }
      else return;
    }
        
    if(s[pos] == '0'){
      t.push_back("0");
      helper(s,t,pos+1,out);
      t.pop_back();
    }
    else if(s[pos] == '1' || s[pos] == '2'){
      for(int i=1;i<=3;i++){
	int temp_n = 0;
	for(int j=pos;j<pos+i;j++){
	  temp_n *= 10;
	  temp_n += s[j]-'0';
	}
	if(temp_n >= 0 && temp_n <= 255){
	  t.push_back(s.substr(pos,i));
	  helper(s,t,pos+i,out);
	  t.pop_back();
	}
      }
    }
    else if(s[pos] >= '3' && s[pos] <= '9'){
      for(int i=1;i<=2;i++){
	string temp = s.substr(pos,i);
	t.push_back(temp);
	helper(s,t,pos+i,out);
	t.pop_back();
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> out;
    if(s.empty()) return out;
    if(s.length() > 16) return out;
        
    vector<string> temp;
    helper(s,temp,0,out);
    return out;
  }
};
