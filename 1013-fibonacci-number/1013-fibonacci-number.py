class Solution:
    def fib(self, n: int) -> int: 
        #USING RECURSION       
        # if n==0:
        #     return 0
        # if n==1:
        #     return 1
        # if(n>1):
        #     return self.fib(n-1)+self.fib(n-2)
        #using caching
        
        #USING CACHING WITH RECURSION
        if n==0:
            return 0
        
        f=[-1]*(n+1)
        f[0]=0
        f[1]=1
        for i in range(2,n+1):
            f[i]=f[i-1]+f[i-2]
        return f[n]