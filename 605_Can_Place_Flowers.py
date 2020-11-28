class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if not n: return True
        
        flowerbed = [0] + flowerbed + [0]
        for i, p in enumerate(flowerbed[1:-1], 1):
            if not flowerbed[i]:
                if flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                    n -= 1
                    flowerbed[i] = 1
                    
            if not n: return True
            
        return False

solution = Solution()
print(solution.canPlaceFlowers([1, 0, 0, 0, 1], 1))
print(solution.canPlaceFlowers([1, 0, 0, 0, 1], 2))