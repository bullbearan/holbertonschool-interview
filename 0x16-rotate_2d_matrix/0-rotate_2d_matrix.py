#!/usr/bin/python3
"This is a line of text"


def rotate_2d_matrix(matrix):
    "This is a line of text"
    left = 0
    r = len(matrix) - 1
    while left < r:
        matrix[left], matrix[r] = matrix[r], matrix[left]
        left += 1
        r -= 1
    for i in range(len(matrix)):
        for j in range(i):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
