#!/usr/bin/python3
"a"


def makeChange(coins, total):
    "a"
    if total <= 0:
        return 0
    if len(coins) <= 0:
        return -1
    r = [total + 1] * (total + 1)
    r[0] = 0
    for i in range(1, total + 1):
        for c in coins:
            if i >= c:
                r[i] = min(r[i], r[i - c] + 1)
            else:
                break
    return r[total] if r[total] != total + 1 else -1
