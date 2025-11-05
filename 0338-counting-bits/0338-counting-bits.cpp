class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i=0; i<=n;i++){
            int x = cnt(i);
            res.push_back(x);
        }

        return res;
    }

    int cnt(int n){{
        string res ="";
        while(n!=0){
            if(n%2==1) res+='1';
            else{
                res+='0';
            }
            n=n/2;
        }
        int numofOnes = count(res.begin(), res.end(),'1');
        return numofOnes;
    }

    }
};