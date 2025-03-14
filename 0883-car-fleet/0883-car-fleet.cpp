class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n==0) return 0;

        vector<pair<int,double>> cars;

        //calculate time required to reach the target for each car
        for(int i=0; i<n; i++){
            cars.push_back({position[i], (double)(target-position[i])/speed[i]});
        }

        //sort cars by position in descending order
        sort(cars.rbegin(), cars.rend());
        // for(auto car: cars){
        //     cout<<"position:"<<car.first << " : "<<"time:"<<car.second<<"\n";
        // }

        int fleets=0;
        double LastTime=0.0;

        //traverse from the rightmost (closest to target) to leftmost car
        for(const auto& car: cars){
            double time=car.second;
            if(time>LastTime){
                fleets++;
                LastTime=time;
            }
        }
        return fleets;
    }
};