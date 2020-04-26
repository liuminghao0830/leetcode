class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        def dfs(i):
            num, string = '', ''
            while i < len(s):
                if s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z':
                    string += s[i]
                elif s[i] >= '0' and s[i] <= '9':
                    num += s[i]
                elif s[i] == '[':
                    i, d = dfs(i + 1)
                    string += int(num) * d
                    num = ''
                elif s[i] == ']':
                    return i, string
                i += 1
            return i, string
        
        i, res = dfs(0)
        return res



solution = Solution()
print(solution.decodeString("3[a]2[bc]"))

print(solution.decodeString("3[a2[c]]"))

print(solution.decodeString("2[abc]3[cd]ef"))

print(solution.decodeString("3[a]2[b4[F]c]"))