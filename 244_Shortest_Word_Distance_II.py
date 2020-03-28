class WordDistance(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.wordmap = {}
        self.max = len(words)

        for i, word in enumerate(words):
            self.wordmap[word] = self.wordmap.get(word, []) + [i]


    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        res, i, j = self.max, 0, 0
        m1 = self.wordmap[word1]
        m2 = self.wordmap[word2]
        while i < len(m1) and j < len(m2):
            res = min(res, abs(m1[i] - m2[j]))
            if m1[i] < m2[j]: 
                i += 1
            else: 
                j += 1
        return res


words = ["practice","makes","perfect","coding","makes"]
solution = WordDistance(words)
print(solution.shortest("coding", "practice"))
print(solution.shortest("makes", "coding"))