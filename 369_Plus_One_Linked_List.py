# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def dfs(self, head):
        if not head:
            return 1
        c = self.dfs(head.next)
        carry = (head.val + c) // 10
        head.val = (head.val + c) % 10
        return carry

    def plusOne(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        carry = self.dfs(head)
        if carry != 0:
            dummy.val = carry
            return dummy
        return head
