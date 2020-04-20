class Solution():
    def countComponents(self, n, edges):
        # BFS time complexity: O(n)
        def bfs(s):
            queue = [s]
            while queue:
                t = queue.pop()
                seen[t] = True
                for n in graph[t]:
                    if not seen[n]:
                        queue.append(n)

        graph = [set() for _ in range(n)]
        for e1, e2 in edges:
            graph[e1].add(e2)
            graph[e2].add(e1)

        cnt = 0
        seen = [False for _ in range(n)]
        for i in range(n):
            if seen[i]:
                continue
            bfs(i)
            cnt += 1
        return cnt


solution = Solution()
res = solution.countComponents(5, [[0, 1], [1, 2], [3, 4]])
print("Result: ", res)

res = solution.countComponents(5, [[0, 1], [1, 2], [2, 3], [3, 4]])
print("Result: ", res)