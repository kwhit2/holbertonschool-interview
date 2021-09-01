#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics """
import sys

count = 0
fileSizeCt = 0

for line in sys.stdin:
    try:
        metricsInput = line.rstrip()
        count += 1
        fileSize = metricsInput[-3:]
        fileSizeCt += 1
        statusCode = metricsInput
        # fileSize =
        if (count % 10 == 0):
            print("{}: ".format(fileSize))
            print("{}".format(metricsInput))
    except KeyboardInterrupt:
        print('Hello user you have pressed ctrl-c button.')
