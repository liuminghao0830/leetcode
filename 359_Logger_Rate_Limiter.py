class Logger(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.timer = {}
        self.mesg = set()

    def shouldPrintMessage(self, timestamp, message):
        """
        Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity.
        :type timestamp: int
        :type message: str
        :rtype: bool
        """
        if message in self.mesg:
            if timestamp - self.timer[message] < 10:
                return False
            else:
                self.timer[message] = timestamp
                return True
        else:
            self.timer[message] = timestamp
            self.mesg.add(message)
        return True