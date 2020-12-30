import random

def GetRandom(l, r):
    return random.randint(l, r)

'''
Invertir(1234) = 4 * 1000 + Invertir(123)
Invertir(123) = 3 * 100 + Invertir(12)
Invertir(12) = 2 * 10 + Invertir(1)
Invertir(1) = 1
'''

def Potenciar(a, b):
    if b == 0:
        return 1
    ans = Potenciar(a, b // 2)
    ans *= ans
    if b & 1:
        ans *= a
    return ans

def Contar(n):
    if n < 10:
        return 1
    return 1 + Contar(n // 10)

def Invertir(n):
    if n < 10:
        return n
    return (n % 10) * Potenciar(10, Contar(n // 10)) + Invertir(n // 10)

def Imprimir(n):
    print(n, "reflejado es", Invertir(n))

MAXIMO = 1 << 20
n = 50
print(n)
while n > 0:
    Imprimir(GetRandom(0, MAXIMO))
    n -= 1
