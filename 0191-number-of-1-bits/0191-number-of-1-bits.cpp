class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
        while(n!=0){
            count+=n&1; //add 1 if the last bit is 1
            n>>=1; //right shift to check the next bit
        }
        return count;
    }
};