class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by end time (second element)
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlap → need to remove this interval
                count++;
            } else {
                // No overlap → update prevEnd
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};
