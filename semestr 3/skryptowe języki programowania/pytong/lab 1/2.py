lista1 = []
lista2 = []

rozmiar1 = int(input("Podaj rozmiar 1 listy: "))
for i in range(rozmiar1):
    lista1.append(int(input("Podaj element: ")))
suma1 = sum(lista1)
print("suma1: ", suma1)


rozmiar2 = int(input("Podaj rozmiar 2 listy: "))
for i in range(rozmiar2):
    lista2.append(input("Podaj element: "))
suma2 = "".join(lista2)
print("suma2: ", suma2)