#!/usr/bin/python3


def makeChange(coins, total):
    if total <= 0:
        return 0
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
