#!/usr/bin/python3
''' This is a line of text '''


def canUnlockAll(boxes):
    keys = [0]
    for i in keys:
        for j in boxes[i]:
            if j not in keys:
                keys.append(j)
    return len(keys) == len(boxes)
