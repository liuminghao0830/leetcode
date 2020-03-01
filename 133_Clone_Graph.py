# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors

class Solution(object):
    def dfs(self, node, m):
        if not node: return None
        if node in m: return m[node]
        
        nnode = Node(node.val)
        m[node] = nnode
        for neigh in node.neighbors:
            nnode.neighbors.append(self.dfs(neigh, m))
        return nnode
    
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        m = dict()
        return self.dfs(node, m)