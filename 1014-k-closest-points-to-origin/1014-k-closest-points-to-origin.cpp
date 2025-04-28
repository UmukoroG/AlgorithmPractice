class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<
            pair<double, vector<int>>, 
            vector<pair<double, vector<int>>>, 
            greater<pair<double, vector<int>>>
        > minHeap;

        for(int i=0; i<points.size(); i++){
            double distance = euclideanDistance(points[i][0], points[i][1], 0, 0);  
            minHeap.push({distance, points[i]});
        }
        int count = 0;
        while(!minHeap.empty() && count < k){
            auto top = minHeap.top();
            minHeap.pop();
            result.push_back(top.second);
            count++;
        }
        return result;
    }
private: 
    double euclideanDistance(int x1, int y1, int x2, int y2) {
        return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    }
};