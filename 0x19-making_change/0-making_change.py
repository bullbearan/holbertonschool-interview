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
        if total == 0:
            return res
        if coins[i] > total:
            i += 1
        else:
            total -= coins[i]
            res += 1
    return -1
