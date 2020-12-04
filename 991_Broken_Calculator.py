'''
On a broken calculator that has a number showing on its display, 
we can perform two operations:

    Double: Multiply the number on the display by 2, or;
    Decrement: Subtract 1 from the number on the display.

Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.
'''

class Solution(object):
    def brokenCalc(self, X, Y):
        """
        :type X: int
        :type Y: int
        :rtype: int
        """
        # Time complexity: O(Y/X)
        # Space complexity: O(1)
        res = 0
        while Y > X:
            Y = Y + 1 if Y % 2 else Y / 2
            res += 1
        return res + X - Y

solution = Solution()
print(solution.brokenCalc(2, 3))
print(solution.brokenCalc(5, 8))