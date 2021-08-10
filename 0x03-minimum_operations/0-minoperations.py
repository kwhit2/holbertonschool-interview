#!/usr/bin/python3
""" Sum of prime factors """


def prime_factors(n):
    """ Brute force the return of the prime factors of n in a list """
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


def minOperations(n):
    """ deterime sum of minimum number of operations """
    if n == 0 or n == 1:
        return 0
    else:
        factList = prime_factors(n)
        return sum(factList)
