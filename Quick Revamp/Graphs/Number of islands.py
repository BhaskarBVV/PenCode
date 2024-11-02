# https://leetcode.com/problems/number-of-islands/

from typing import List


class Solution:

    def visit_island(self, i, j, grid: List[List[str]]):
        grid[i][j] = "x"
        if i-1 >= 0 and grid[i-1][j] == 1:
            self.visit_island(i-1, j, grid)
        if j-1 >= 0 and grid[i][j-1] == 1:
            self.visit_island(i, j-1, grid)
        if i+1 < len(grid) and grid[i+1][j] == 1:
            self.visit_island(i+1, j, grid)
        if j+1 < len(grid[0]) and grid[i][j+1] == 1:
            self.visit_island(i, j+1, grid)

    def numIslands(self, grid: List[List[str]]) -> int:
        number_of_islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    number_of_islands += 1
                    self.visit_island(i, j, grid)

        return number_of_islands
