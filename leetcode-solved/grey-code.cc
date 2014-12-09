class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> out;
    if(n<0) return out;
    if(n==0){
      out.push_back(0);
      return out;
    }
        
    for(int i=0;i<(1<<n);i++) out.push_back((i>>1)^i);
        
    return out;
  }
};
