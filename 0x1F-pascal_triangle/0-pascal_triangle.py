#!/usr/bin/python3
"Titans aeotnas etoa"


def pascal_triangle(n):
    "Titans aeotnas etoa"
    if n <= 0:
        return []

    pascal = [[1]]
    while len(pascal) != n:
        prev = pascal[-1]
        current = [1]
        for i in range(len(prev) - 1):
            current.append(prev[i] + prev[i + 1])
        current.append(1)
        pascal.append(current)
    return pascal
