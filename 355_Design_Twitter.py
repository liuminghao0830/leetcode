class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.user2tweet = collections.defaultdict(list)
        self.follows = collections.defaultdict(set)
        self.order = 0

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: None
        """
        self.order -= 1
        self.user2tweet[userId] += [(self.order, tweetId)]

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        news = sorted([tweet for user in self.follows[userId] | set([userId]) for tweet in self.user2tweet[user]])[:10]
        return [n for i, n in news]

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        self.follows[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        self.follows[followerId].discard(followeeId)