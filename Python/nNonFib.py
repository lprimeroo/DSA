#!/usr/bin/python
# -*- encoding: utf-8 -*-
#function to calculate nth non fibonacci number
def nthnonfib(n):
    fibs = [2, 3, 5]
    breaks = [0, 1, 2]
    for x in xrange(500):
        fibs.append(fibs[-1] + fibs[-2])
    for x in xrange(500):
        breaks.append(breaks[-1] + breaks[-2] + 1)
    for x in xrange(1, len(breaks)):
        breaks[x] += breaks[x - 1]
    result = None
    l=1
    r=len(breaks)-1
    x=(l+r)//2
# implementing binary search
    while(l<=r):
        if breaks[x] >=n and breaks[x-1]< n:
            result = fibs[x] + n - breaks[x-1]
            break
        elif breaks[x]> n :
            r=x-1
        else :
            l=x+1
        x=(l+r)//2
    return result
for i in xrange(1,500):
    print nthnonfib(i),
