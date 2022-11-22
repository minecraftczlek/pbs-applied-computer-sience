def decToLat(liczba):
    dec = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
    lat = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"]
    wynik = ""
    i = len(dec)-1

    while liczba:
        dziel = liczba // dec[i]
        liczba %= dec[i]
        while dziel:
            wynik += lat[i]
            dziel -= 1
        i -= 1
    return wynik

print(decToLat(int(input("Podaj liczbę: "))))