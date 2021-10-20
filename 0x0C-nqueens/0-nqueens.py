#!/usr/bin/python3
""" This module contains a program that solves the N queens problem """

import sys
from sys import argv


def queens(n, i, a, b, c):
    if i < n:
        for j in range(n):
            if j not in a and i + j not in b and i - j not in c:
                yield from queens(n, i + 1, a + [j], b + [i + j], c + [i - j])
    else:
        yield a

for solution in queens(8, 0, [], [], []):
    print(solution)

# way to much output
