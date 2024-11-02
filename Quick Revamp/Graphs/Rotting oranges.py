# https://leetcode.com/problems/rotting-oranges/

from typing import List
from queue import Queue


class Solution:
    def rot_neighbours(self, i: int, j: int, queue: Queue, grid: List[List[int]]):
        rotten_oranges = 0
        if i-1 >= 0 and grid[i-1][j] == 1:
            grid[i-1][j] = 2
            queue.put((i-1, j))
            rotten_oranges += 1
        if j-1 >= 0 and grid[i][j-1] == 1:
            grid[i][j-1] = 2
            queue.put((i, j-1))
            rotten_oranges += 1
        if i+1 < len(grid) and grid[i+1][j] == 1:
            grid[i+1][j] = 2
            queue.put((i+1, j))
            rotten_oranges += 1
        if j+1 < len(grid[0]) and grid[i][j+1] == 1:
            grid[i][j+1] = 2
            queue.put((i, j+1))
            rotten_oranges += 1
        return rotten_oranges

    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = Queue()
        current_rotten_oranges = 0
        oranges = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.put((i, j))
                    current_rotten_oranges += 1
                elif grid[i][j] == 1:
                    oranges += 1

        if oranges == 0:
            return 0

        time = -1
        while not q.empty():
            q_size = current_rotten_oranges
            current_rotten_oranges = 0
            time += 1
            for _ in range(q_size):
                rotten_orange = q.get()
                current_rotten_oranges += self.rot_neighbours(
                    rotten_orange[0], rotten_orange[1], q, grid)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1

        return time
