class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        paths = input.split('\n')
        cnt, max_len = {}, 0
        for path in paths:
            if '.' not in path:
                level = path.count('\t')
                path = path.replace('\t', '')
                cnt[level] = len(path)
            else:
                level = path.count('\t')
                path = path.replace('\t', '')
                length = 0
                for l in range(level):
                    length += cnt[l]
                length += len(path) + level
                max_len = max(max_len, length)
        return max_len

solution = Solution()
print(solution.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"))