class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size()==0){
            return {1};
        }

        int lastIdx = digits.size()-1;

        // add one to last digit
        digits[lastIdx]+=1;

        //handle carry
        for(int i=lastIdx; i>0; i--){
            if(digits[i]==10){
                digits[i]=0;
                digits[i-1]+=1;
            }
        }

        //if digits rolled over
        if(digits[0]==10){
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }


        return digits;
    }
};