from random import random
lista = []

for i in range(10):
    lista.append(int(random()*10))
print(lista)

lista[0:5] = [6,6,6,6,6]
print(lista)

lista.pop(1)
lista.pop(7)
print(lista)

rozmiar = int(len(lista)/2)
lista.insert(rozmiar, "słowo")
lista.insert(rozmiar+1, "tok")
print(lista)