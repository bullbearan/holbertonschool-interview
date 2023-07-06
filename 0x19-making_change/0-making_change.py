#!/usr/bin/python3
"This is a line of text"


def makeChange(coins, total):
    "This is a line of text"
    if total <= 0:
        return 0
    if total in coins:
        return 1
    res = [total + 1] * (total + 1)
    res[0] = 0
    for i in range(1, total + 1):
        for coin in coins:
            if i - coin >= 0:
                res[i] = min(res[i], res[i - coin] + 1)
    if res[total] == total + 1:
        return -1
    return res[total]
