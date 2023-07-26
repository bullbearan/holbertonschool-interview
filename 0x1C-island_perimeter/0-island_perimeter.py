#!/usr/bin/python3
"This is a line of text"


def island_perimeter(grid):
    "This is a line of text"
    res = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                res += 4
                if j > 0 and grid[i][j - 1] == 1:
                    res -= 2
                if i > 0 and grid[i - 1][j] == 1:
                    res -= 2
    return res
