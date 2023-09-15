class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False

        mp_s={}
        mp_t={}

        # for char in s:
        #     if char in mp_s:
        #         mp_s[char]+=1
        #     else:
        #         mp_s[char]=1
        # for char in t:
        #     if char in mp_t:
        #         mp_t[char]+=1
        #     else:
        #         mp_t[char]=1

        for i in range(len(s)): #optimized loop for the two for loop above
        # The method get() returns a value for the given key. If key is not available then returns default value None(0)
            mp_s[s[i]]=1+mp_s.get(s[i],0)
            mp_t[t[i]]=1+mp_t.get(t[i],0)

        for c in mp_s:
            if mp_s[c] != mp_t.get(c,0):#check if they key:value are not equal then return false, else return 0 if key:value not found in mp_t
                return False
                       
        return True
        
        