#!/usr/bin/python3
""" This module contains a program that solves the N queens problem """

import sys
from sys import argv
BOARD_SIZE = int(argv[1])


def under_attack(col, queens):
    return col in queens or \
           any(abs(col - x) == len(queens)-i for i, x in enumerate(queens))


def solve(n):
    solutions = [[]]
    for row in range(n):
        solutions = (solution+[i+1]
                     for solution in solutions
                     for i in range(BOARD_SIZE)
                     if not under_attack(i+1, solution))
    return solutions

answers = solve(BOARD_SIZE)
first_answer = next(answers)
print(list(enumerate(first_answer, start=1)))

# printing one line of output like so incorrectly for our task
# [(1, 2), (2, 4), (3, 1), (4, 3)]
