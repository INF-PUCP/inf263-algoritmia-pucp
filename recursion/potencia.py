# Calcular a^b
def Potenciar(a, b):
    if b == 0:
        return 1
    ans = Potenciar(a, b >> 1)
    ans *= ans
    if b & 1:
        ans *= a
    return ans

def PotenciarRapido(a, b):
    ans = 1
    pot = a
    while b > 0:
        if b & 1:
            ans *= pot
        pot *= pot
        b = b >> 1
    return ans


a = 2
b = 63
'''
Solucion O(b)
ans = 1
for i in range(0, b):
    ans *= a
'''

'''
Solucion recursiva en O(lg b)
print(Potenciar(a, b))
'''

# Solucion iterativa en O(lg b)
print(PotenciarRapido(a, b) - 1)
