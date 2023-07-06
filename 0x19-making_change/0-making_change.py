#!/usr/bin/python3
"This is a line of text"


def makeChange(coins, total):
    "This is a line of text"
    if total <= 0:
        return 0
    if total in coins:
        return 1
    if len(coins) <= 0:
        return -1
    current_sum = 0
    res = 0
    coins.sort(reverse=True)
    for coin in coins:
        while current_sum < total:
            current_sum += coin
            res += 1
        if current_sum == total:
            return res
        current_sum -= coin
        res -= 1
    return -1
