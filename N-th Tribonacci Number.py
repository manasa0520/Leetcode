class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 1
        a,b,c = 0,1,1
        for i in range(3,n+1):
            a,b,c=b,c,a+b+c
            #print(a,b,c)
        return c 
