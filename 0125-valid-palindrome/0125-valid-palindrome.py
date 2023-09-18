class Solution:
    def isPalindrome(self, s: str) -> bool:
        newS=''
        revs=''

        if not s:
            return true

        for i in s:
            if i.isalnum():
                newS+=i.lower()
            else:
                continue
        revS= newS[::-1]#reverse a string

        return newS==revS
