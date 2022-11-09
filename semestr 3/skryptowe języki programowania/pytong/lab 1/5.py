def unikaty(L1, L2):
    wynik = []
    for x in L1:
        if x not in L2:
            wynik.append(x)
    return wynik

lista1 = ['a','b','c','d','e']
lista2 = ['a','c','d','f','g']

print(unikaty(lista1, lista2))