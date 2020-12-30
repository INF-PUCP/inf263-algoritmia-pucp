import random

def GetRandom(l, r):
    return random.randint(l, r)

def Contar(n):
    if n < 10:
        return 1
    return 1 + Contar(n // 10)

def Imprimir(n):
    print(n, " tiene ", Contar(n), "digitos")

MAXIMO = 100
n = 50
print(n)
while n > 0:
    Imprimir(GetRandom(0, MAXIMO))
    n -= 1
