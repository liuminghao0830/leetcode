class TrieNode():
    def __init__(self):
        self.children = [None] * 26
        self.endWord = False

class WordDictionary(object):
    """ O(word) : 20% """
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: None
        """
        p = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if not p.children[idx]:
                p.children[idx] = TrieNode()
            p = p.children[idx]
        p.endWord = True

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        p = self.root
        return self.dfs_search(word, p)

    def dfs_search(self, word, root):
        res = False
        if not word:
            if root.endWord: res = True
            return res

        if word[0] != '.':
            idx = ord(word[0]) - ord('a')
            if root.children[idx] is None:
                return res
            res = self.dfs_search(word[1:], root.children[idx])
        else:
            for child in root.children:
                if child is None:
                    continue
                res = self.dfs_search(word[1:], child)
                if res: break
        return res



# Your WordDictionary object will be instantiated and called as such:
obj = WordDictionary()
obj.addWord("bbb")
print obj.search("b..")