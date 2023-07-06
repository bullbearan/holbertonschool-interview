#!/usr/bin/python3
"This is a line of text"


def makeChange(coins, total):
    "This is a line of text"
    if total <= 0:
        return 0
    i = 0
    res = 0
    coins.sort(reverse=True)
    while (i < len(coins)):
        if total - coins[i] >= 0:
            total -= coins[i]
            res += 1
            i -= 1
        if total == 0:
            return res
        i += 1
    return -1
