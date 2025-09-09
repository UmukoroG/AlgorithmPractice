class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for(int i=0; i<intervals.size(); i++){ 
            if(newInterval[1] < intervals[i][0]){// non overlapping
                // newInterval comes before current interval, no overlap
                res.push_back(newInterval);
                //append remaining intervals
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            else if(newInterval[0] > intervals[i][1]){// non overlapping
                // newInterval comes after current interval, no overlap
                res.push_back(intervals[i]);
            }
            else{//overlapping merge
                newInterval ={min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            }
        }
        res.push_back(newInterval);
        return res;
    }
};