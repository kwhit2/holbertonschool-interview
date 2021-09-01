#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics """
from sys import stdin


def printMetrics(statusCodes, fileSize):
    """ ^ print metrics ^ """
    print("File size: " + str(fileSize))
    for line in sorted(statusCodes.keys()):
        if statusCodes[line] > 0:
            print(line + ": " + str(statusCodes[line]))


statusCodes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
               "404": 0, "405": 0, "500": 0}
statusCode = 0
lineCount = 0
fileSize = 0


try:
    for line in stdin:
        lineCount += 1
        splitArgs = line.split()

        if len(splitArgs) > 1:
            fileSize += int(splitArgs[-1])

        if len(splitArgs) > 2 and splitArgs[-2].isnumeric():
            statusCode = splitArgs[-2]
        else:
            statusCode = 0

        if statusCode in statusCodes.keys():
            statusCodes[statusCode] += 1

        if lineCount % 10 == 0:
            printMetrics(statusCodes, fileSize)

    printMetrics(statusCodes, fileSize)

except KeyboardInterrupt:
    printMetrics(statusCodes, fileSize)
