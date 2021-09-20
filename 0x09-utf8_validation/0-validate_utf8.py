#!/usr/bin/python3
""" method that determines if a given data set represents...
    ...a valid UTF-8 encoding """


def validUTF8(data):
    """ validUTF8 method """
    data = iter(data)
    for leadingByte in data:
        leadingOnes = countLeadingOnes(leadingByte)
        if leadingOnes in [1, 7, 8]:
            return False
        for _ in range(leadingOnes - 1):
            trailingByte = next(data, None)
            if trailingByte is None or trailingByte >> 6 != 0b10:
                return False
    return True


def countLeadingOnes(byte):
    """ countLeadingOnes method """
    for i in range(8):
        if byte >> (7 - i) == 0b11111111 >> (7 - i) & ~1:
            return i
    return 8
