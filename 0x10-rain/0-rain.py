#!/usr/bin/python3
"""This is a line of text"""


def rain(walls):
    """This is a line of text"""
    if len(walls) == 0:
        return (0)
    start, end = 0, len(walls) - 1
    max_start, max_end = walls[start], walls[end]
    ans = 0
    while start < end:
        if max_start < max_end:
            start += 1
            if max_start > walls[start]:
                max_start = max_start
            else:
                max_start = walls[start]
            ans += max_start - walls[start]
        else:
            end -= 1
            if max_end > walls[end]:
                max_end = max_end
            else:
                max_end = walls[end]
            ans += max_end - walls[end]
    return ans
