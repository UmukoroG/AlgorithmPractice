class Solution {
public:
    vector<int> res;
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    unordered_set<int> visited;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++){
            preMap[i] = {};
        }


        for(const auto& prereq: prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for(int c=0; c<numCourses; c++){
            if(!dfs(c)){
                return {};
            }
        }
        return res;
    }

    bool dfs(int crs){
        if(visiting.count(crs)){//find course in set
            return false; //cycle detected
        }

        if(visited.count(crs)) return true;// already done
       
        visiting.insert(crs);

        for(int pre: preMap[crs]){
            if(!dfs(pre)){
                return false;
            }
        }
        visiting.erase(crs);
        visited.insert(crs);//mark as done
        preMap[crs].clear();

        res.push_back(crs);
        
        return true;
    }
};