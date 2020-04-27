import collections

class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        def build_graph(e1, e2, v):
            graph[e1].append((e2, v))

        def bfs(query):
            e1, e2 = query[0], query[1]
            queue = [(e1, 1.0)]
            seen = set([e1])

            while queue:
                e, p = queue.pop(0)
                for n, v in graph[e]:
                    if n == e2:
                        return v * p
                    if n in seen:
                        continue

                    queue.append((n, v * p))
                    seen.add(n)
            return -1.0

            
        graph = collections.defaultdict(list)
        for edge, value in zip(equations, values):
            e1, e2 = edge[0], edge[1]
            build_graph(e1, e2, value)
            build_graph(e2, e1, 1. / value)

        res = []
        for query in queries:
            res.append(bfs(query))
        return res

solution = Solution()

equations = [["a", "b"], ["b", "c"]]
values = [2.0, 3.0]
queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]

print(solution.calcEquation(equations, values, queries))
