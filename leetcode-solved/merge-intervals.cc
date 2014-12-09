/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator < (const Interval &a, const Interval &b) {return a.start < b.start;}
class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> out;
    if(intervals.empty()) return out;
        
    sort(intervals.begin(),intervals.end()); 
    Interval working_interval(intervals[0].start, intervals[0].end);
    for(int i=0;i<intervals.size();i++){
      if(working_interval.end >= intervals[i].start){
	if(working_interval.end < intervals[i].end) working_interval.end = intervals[i].end;
      }
      else{
	Interval temp(working_interval.start, working_interval.end);
	out.push_back(temp);
	working_interval.start = intervals[i].start;
	working_interval.end = intervals[i].end;
      }
    }
    out.push_back(working_interval);
        
    return out;
  }
};
