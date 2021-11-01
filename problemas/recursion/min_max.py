import random

# O(1)
def GetRandom(l, r):
    return random.randint(l, r)

# O(n)
def Minimo(a, l, r):
    if l == r:
        return l
    pos = Minimo(a, l, r - 1)
    if a[pos] < a[r]:
        return pos
    return r

'''
mn , mx = l, l
for i in range(l + 1, r + 1):
    if a[i] < a[mn]:
        mn = i
    if a[i] > a[mx]:
        mx = i
'''

# O(n)
def Maximo(a, l, r):
    if l == r:
        return l
    pos = Maximo(a, l, r - 1)
    if a[pos] > a[r]:
        return pos
    return r

# O(1)
n = 30
a = []
# O(n)
for i in range(0, n):
    a.append(GetRandom(-100, 100))

# O(n)
print(a)

# O(1)
q = 5

# O(qn)
for i in range(0, q):
    l = GetRandom(0, n - 1)  # O(1)
    r = GetRandom(0, n - 1)  # O(1)
    l, r = min(l, r), max(l, r)  # O(1)
    print("l: ", l, " r: ", r)  # O(1)
    pos_min = Minimo(a, l, r)  # O(n)
    pos_max = Maximo(a, l, r)  # O(n)
    print("pos: ", pos_min, " minimo: ", a[pos_min])  # O(1)
    print("pos: ", pos_max, " maximo: ", a[pos_max])  # O(1)
