#!/usr/bin/python3
"This is a line of text"


def makeChange(coins, total):
    "This is a line of text"
    if total <= 0:
        return 0
    current_sum = total
    i = 0
    res = 0
    coins.sort(reverse=True)
    while (i < len(coins)):
        if current_sum == 0:
            return res
        if coins[i] > current_sum:
            i += 1
        else:
            current_sum -= coins[i]
            res += 1
    return -1
