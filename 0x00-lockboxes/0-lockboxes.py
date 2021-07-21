#!/usr/bin/python3
""" You have n number of locked boxes in front of you:
    Each box is numbered sequentially from 0 to n - 1 and each box
    may contain keys to the other boxes. """


def canUnlockAll(boxes):
    """ Check if all boxes can be opened, starting at 0 """
    keysDict = {
        0: True
    }
    # keep track of number of times going through the...
    # ...while loop (prevent infinite loop)
    loopIterations = 0

    # set the rest of the dict to False values to start
    for i in range(1, len(boxes)):
        keysDict[i] = False

    # loop through all keys
    try:
        while False in keysDict.values() and loopIterations < len(boxes):
            for i in list(keysDict):
                if keysDict[i] is True:
                    for k in boxes[i]:
                        keysDict[k] = True
                    loopIterations += 1
    except IndexError:
        return False

    # if there is still a False value anywhere in dict...
    # ...then the method returns false
    if False in keysDict.values():
        return False
    return True
