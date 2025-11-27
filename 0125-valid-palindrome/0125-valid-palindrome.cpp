class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return true;
        }
        string newStr;
        for(int i=0; i<s.size(); i++){
            if(isalnum(s[i])){
                newStr += tolower(s[i]);
            }
        }

        cout<<newStr;
        int l=0, r=newStr.size()-1;

        while(l<=r){
            if(newStr[l]!=newStr[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};