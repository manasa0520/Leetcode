class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def find(i, j, k, seen):
            if k == len(word):
                return True
            
            if i<0 or i>=m or j<0 or j>=n or \
                seen[i][j] or board[i][j] != word[k]:
                return False
            
            seen[i][j] = True
            res = find(i+1, j, k+1, seen) or \
                find(i-1, j, k+1, seen) or \
                find(i, j+1, k+1, seen) or \
                find(i, j-1, k+1, seen)
            seen[i][j] = False
            return res
        
        m, n = len(board), len(board[0])
        if len(word) > m*n:
            return False
        
        # check count
        count = Counter(sum(board, []))
        for ch, countChar in Counter(word).items():
            if count[ch] < countChar:
                return False
        
        # reverse word based on boundar count
        if count[word[0]] > count[word[-1]]:
            word = word[::-1]

        seen = [[False] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if find(i, j, 0, seen):
                    return True
        return False
