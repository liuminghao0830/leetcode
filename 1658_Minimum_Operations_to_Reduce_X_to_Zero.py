class Solution(object):
    def minOperations1(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        # backtracking: O(2^n), TLE
        def backtrack(l, r, s, cnt):
            if not s: return cnt
            if s < 0 or l > r: return float('inf')
            
            return min(backtrack(l + 1, r, s - nums[l], cnt + 1), backtrack(l, r - 1, s - nums[r], cnt + 1))
        
        res = backtrack(0, len(nums) - 1, x, 0)
        return res if res != float('inf') else -1

    def minOperations2(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        # hash map, O(n)
        if not x: 
            return 0
        target = sum(nums) - x
        if target < 0: return -1
        if target == 0: return len(nums)
        mx_len, s, idx = -1, 0, {0:-1}

        for i in range(len(nums)):
            s += nums[i]
            if s - target in idx:
                mx_len = max(mx_len, i - idx[s - target])
            idx[s] = i
        return len(nums) - mx_len if mx_len >= 0 else -1

solution = Solution()
print(solution.minOperations2([3,2,20,1,1,3], 10))
print(solution.minOperations2([5,6,7,8,9], 4))
print(solution.minOperations2([1,1,4,2,3], 5))
print(solution.minOperations2([1,1], 3))
print(solution.minOperations2([1000,1,1,2,3], 1004))