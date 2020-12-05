import collections

class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        # Time complexity: O(m * n), m: len(paths), n: files in each paths
        # Space complexity: O(m * n)
        group = collections.defaultdict(list)
        for p in paths:
            files = p.split()
            for f in files[1:]:
                cont = f.split('(')
                group[cont[-1]].append(files[0] + '/' + cont[0])
        
        return [x for x in list(group.values()) if len(x) > 1]


solution = Solution()
input1 = ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
print(solution.findDuplicate(input1))