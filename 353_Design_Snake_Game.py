class SnakeGame(object):

    def __init__(self, width, height, food):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        :type width: int
        :type height: int
        :type food: List[List[int]]
        """
        self.w = width
        self.h = height
        self.snake = [(0, 0)]
        self.food = food
        self.score = 0
        self.dirs = {"U": (-1, 0), "L": (0, -1), "R": (0, 1), "D": (1, 0)}


    def move(self, direction):
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body.
        :type direction: str
        :rtype: int
        """
        
        head = self.snake[0]
        dx, dy = self.dirs[direction]
        nhead = (head[0] + dx, head[1] + dy)
        
        tail = self.snake.pop()
        
        if nhead in self.snake or nhead[0] < 0 or \
            nhead[1] >= self.w or nhead[1] < 0 or nhead[0] >= self.h:
            self.snake.insert(0, nhead)
            return -1
        
        self.snake.insert(0, nhead)

        if self.food and list(nhead) == self.food[0]:
            self.food.pop(0)
            self.snake.append(tail)
            self.score += 1

        return self.score


width, height = 3, 2
food = [[1, 2], [0, 1]]

snakegame = SnakeGame(width, height, food)
print(snakegame.move("R"))
print(snakegame.move("D"))
print(snakegame.move("R"))
print(snakegame.move("U"))
print(snakegame.move("L"))
print(snakegame.move("U"))