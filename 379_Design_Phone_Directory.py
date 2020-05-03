class PhoneDirectory(object):

    def __init__(self, maxNumbers):
        """
        Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory.
        :type maxNumbers: int
        """
        self.dir = set([n for n in range(maxNumbers)])

    def get(self):
        """
        Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available.
        :rtype: int
        """
        if not self.dir:
            return -1
        return self.dir.pop()

    def check(self, number):
        """
        Check if a number is available or not.
        :type number: int
        :rtype: bool
        """
        return number in self.dir

    def release(self, number):
        """
        Recycle or release a number.
        :type number: int
        :rtype: None
        """
        self.dir.add(number)