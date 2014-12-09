class Solution {
public:
  int min(int a,int b){
    if(a>b) return b;
    else return a;
  }
  int max(int a,int b){
    if(a>b) return a;
    else return b;
  }
  int maxArea(vector<int> &height) {
    if(height.empty()) return 0;
        
    int maxWater = 0, minH = height[0];
    int i=0, n = height.size();
    int start = 0, end = n-1;
    while(start<end){
      int temp = min(height[start],height[end]) * (end - start);
      maxWater = max(maxWater, temp);
      if(height[start] <= height[end]) start++;
      else end--;
    }
    return maxWater;
  }
};
