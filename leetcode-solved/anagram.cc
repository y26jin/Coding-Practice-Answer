class Solution {
public:
  string idgen(string s){
    int hash[256] = {0};
    for(int i=0;i<s.length();i++) hash[s[i]-'a']++;
        
    string out;
    for(int i=0;i<256;i++){
      for(int j=0;j<hash[i];j++) out+=i+'a';
    }
    return out;
  }
  vector<string> anagrams(vector<string> &strs) {
    vector<string> out;
    if(strs.empty()) return out;
    if(strs.size() == 1) return out;
        
    map<string, vector<string>> hash;
    for(int i=0;i<strs.size();i++){
      string temp_id = idgen(strs[i]);
      map<string, vector<string>>::iterator ht = hash.find(temp_id);
      if(ht == hash.end()){
	vector<string> temp;
	temp.push_back(strs[i]);
	hash.insert(make_pair(temp_id, temp));
      }
      else{
	vector<string> temp = ht->second;
	temp.push_back(strs[i]);
	ht->second = temp;
      }
    }
    map<string, vector<string>>::iterator it;
    for(it=hash.begin();it!=hash.end();it++){
      vector<string> temp = it->second;
      if(temp.size() > 1){
	for(int i=0;i<temp.size();i++) out.push_back(temp[i]);
      }
    }
    return out;
  }
};
