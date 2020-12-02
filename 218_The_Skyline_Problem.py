from heapq import heappop, heappush

class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        buildings = sorted([(l, -h, r) for l, r, h in buildings] + \
                           [(r, 0, 0) for _, r, _ in buildings])
        
        res = [(0, 0)]
        events = [(0, float('inf'))]
        for l, nh, r in buildings:
            while l >= events[0][1]: 
                heappop(events)

            if nh:
                heappush(events, (nh, r))

            if res[-1][1] != -events[0][0]:
                res.append((l, -events[0][0]))

        return res[1:]


solution = Solution()
print(solution.getSkyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]))
print(solution.getSkyline([[0,2,3],[2,5,3]]))