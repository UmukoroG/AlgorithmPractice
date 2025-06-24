class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;

        int count=0;
        int n=s.size();
        for(int i=0; i<n; i++){//takes 0(n3) time
            for(int j = i; j < n; j++) {  
                if(isPali(s.substr(i,j-i+1))){//check pali for substrings
                    count++;
                }
            }
        }
        return count;
        
    }

    bool isPali(string s){
        if(s.empty()) return true;

        int l=0;
        int r=s.size()-1;

        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};