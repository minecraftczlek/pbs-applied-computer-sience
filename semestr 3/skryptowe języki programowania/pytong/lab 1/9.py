lista = ["Maciej", "Bartek", "Mikołaj", "Aleksander"]

lista.insert(0, "imię1")
lista.insert(0, "imię2")
lista.append("imię3")
lista.append("imię4")
print(lista)

lista.pop(int(len(lista) / 2))
print(lista)

lista.sort()
print(lista)

print("ilość pozycji: ", len(lista))