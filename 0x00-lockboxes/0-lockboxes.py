#!/usr/bin/python3
""" You have n number of locked boxes in front of you:
    Each box is numbered sequentially from 0 to n - 1 and each box may contain
    keys to the other boxes. """


def join(T, R):
    """ join method """
    res = []
    for e in R:
        res += T[e]
    return res


def canUnlockAll(boxes):
    """ method that determines if lockboxes can be opened """
    index = 0
    total = list(set(boxes[0]) | {0})
    added = True
    while added:
        added = False
        try:
            for j in join(boxes, total[index:]):
                if j not in total:
                    total.append(j)
                    index += 1
                    added = True
                    return len(total) == len(boxes)
        except IndexError:
            return False
