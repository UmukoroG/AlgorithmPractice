class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();
        
        for(int center =0; center<n; center++){
            count+= expandAroundCenter(s, center,center); //odd length pali
            count+= expandAroundCenter(s, center,center+1); //even length pali

        }

        return count;
        
    }

    int expandAroundCenter(const string& s, int left, int right){
        int n=s.size();
        int count =0;

        while(left>=0 && right<n && s[left]==s[right]){
            count++;
            left--;
            right++;
        }

        return count;
    }

    
};