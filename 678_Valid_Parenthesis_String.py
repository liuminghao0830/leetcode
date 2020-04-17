class Solution(object):    
    def dfs(self, cnt, s):
        if cnt < 0: 
            return False
        for j, c in enumerate(s):
            if c == '*':
                return self.dfs(cnt - 1, s[j + 1:]) or \
                       self.dfs(cnt + 1, s[j + 1:]) or \
                       self.dfs(cnt, s[j + 1:])
            elif c == '(': 
                cnt += 1
            elif c == ')':
                if cnt <= 0: 
                    return False
                cnt -= 1
            
        return cnt == 0

    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left, star = [], []
        for i, c in enumerate(s):
            if c == '*':
                star += [i]
            elif c == '(':
                left += [i]
            else:
                if left:
                    left.pop()
                elif star:
                    star.pop()
                else:
                    return False
        while left and star:
            if left[-1] > star[-1]:
                return False
            else:
                left.pop()
                star.pop()
        return len(left) == 0