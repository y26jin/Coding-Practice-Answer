/*
 * sum up all increasing intervals
 */

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if(prices.empty() || prices.size() == 1) return 0;
       
    int out = 0;
    for(int i=0;i<prices.size()-1;i++){
      if(prices[i] < prices[i+1]) out += prices[i+1]-prices[i];
    }
    return out;
  }
};
