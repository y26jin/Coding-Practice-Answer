class Solution {
public:
  // maintain the min before each day.
  int maxProfit(vector<int> &prices) {
    if(prices.empty()) return 0;
    int min=prices[0],c=-0xfffff;
    for(int i=0;i<prices.size();i++){
      if(prices[i] < min) min = prices[i];
      if(c < prices[i] - min) c = prices[i] - min;
    }
    return c;
  }
};
