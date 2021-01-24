# https://cses.fi/problemset/task/1628
# Meet in the middle

from itertools import combinations
from random import shuffle

line = input().split()

n = int(line[0])
x = int(line[1])

t = [int(n) for n in input().split()]
shuffle(t)


def sums(tab, max_value):
    res = []
    # print("recv: {}".format(tab))
    for i in range(len(tab)+1):
        # print("comb {}: {}".format(i, list(combinations(tab, i))))
        for el in combinations(tab, i):
            summ = sum(el)
            if summ <= max_value:
                res.append(summ)
    # print("send: {}".format(res))
    return res


def count_occur(l1, l2, value):
    count = 0
    for el in l1:
        match_val = value-el
        count += l2.count(match_val)
    return count


l1 = sums(t[:int(len(t)/2)], x)
l2 = sums(t[int(len(t)/2):], x)

# print(l1)
# print(l2)

res = count_occur(l1, l2, x)
print(res)
