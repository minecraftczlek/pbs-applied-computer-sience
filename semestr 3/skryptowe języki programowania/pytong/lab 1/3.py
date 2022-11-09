lista1 = []
lista2 = []

rozmiar1 = int(input("Podaj rozmiar 1 listy: "))
for i in range(rozmiar1):
    lista1.append(int(input("Podaj element: ")))

rozmiar2 = int(input("Podaj rozmiar 2 listy: "))
for i in range(rozmiar2):
    lista2.append(int(input("Podaj element: ")))

lista3 = lista1 + lista2

print("max: ", max(lista3))
print("min: ", min(lista3))