# Suma(a,pos) : suma de los elementos de a en las posiciones [0 .. pos]
def Suma(a, pos):
    if pos == 0:
        return a[0]
    return Suma(a, pos - 1) + a[pos]

a = [1, 2, 3, 4, 5]
n = 5
print(Suma(a, n - 1))
