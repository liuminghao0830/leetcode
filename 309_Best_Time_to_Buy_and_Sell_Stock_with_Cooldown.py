class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
        	return 0
        	
        # buy, sell, cool, hold
        buy = [0] * len(prices)
        sell = [0] * len(prices)
        rest = [0] * len(prices)

        buy[0] = -prices[0]

        for i in range(1, len(prices)):
            buy[i] = max(buy[i - 1], rest[i - 1] - prices[i])
            rest[i] = max(rest[i - 1], sell[i - 1])
            sell[i] = buy[i - 1] + prices[i]

        return max(buy[-1], rest[-1], sell[-1])


solution = Solution()
prices = [1,2,3,0,2]
print(solution.maxProfit(prices))