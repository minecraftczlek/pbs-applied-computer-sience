import itertools

zbior = [54,7,5,76,23,]
print("Oto wszystkie mozliwe podzbiory:\n")
for i in range(0, len(zbior)+1):
    print(list(itertools.combinations(zbior, i)))