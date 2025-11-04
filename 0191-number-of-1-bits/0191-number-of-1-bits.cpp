class Solution {
public:
    int hammingWeight(int n) {
        string res = "";

        while(n!=0){
            if(n%2==1) res+='1';
            else{
                res+='0';
            }
            n=n/2;
        }
        reverse(res.begin(), res.end());
        int setBit = count(res.begin(), res.end(),'1');

        return setBit;
    }
};