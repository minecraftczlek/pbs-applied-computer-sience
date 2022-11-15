lista1 = ['a','b','c']
lista2 = []

dlugosc = int(input("podaj długość napisu"))

for i in range(dlugosc):
    lista2.append(lista1[i % len(lista1)])

print(lista2)