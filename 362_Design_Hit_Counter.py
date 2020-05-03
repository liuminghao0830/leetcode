class HitCounter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []

    def update_queue(self, timestamp):
        while self.queue and (timestamp - self.queue[0]) >= 300:
            self.queue.pop(0)

    def hit(self, timestamp):
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: None
        """
        self.queue.append(timestamp)
        self.update_queue(timestamp)

    def getHits(self, timestamp):
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: int
        """
        self.update_queue(timestamp)
        return len(self.queue)