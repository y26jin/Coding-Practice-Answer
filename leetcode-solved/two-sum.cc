class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> out;
    if(numbers.empty()) return out;
        
    unordered_map<int,int> hash;
    for(int i=0;i<numbers.size();i++){
      if(hash.find(target-numbers[i]) == hash.end()) hash.insert(make_pair(numbers[i], i+1));
      else{
	out.push_back(hash[target-numbers[i]]);
	out.push_back(i+1);
	break;
      }
    }
    return out;
  }
};
