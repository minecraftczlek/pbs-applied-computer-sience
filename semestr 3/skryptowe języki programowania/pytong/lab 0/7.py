from datetime import datetime

data1 = datetime.strptime(input("Podaj datę nr 1: "), "%Y-%m-%d")
data2 = datetime.strptime(input("Podaj datę nr 2: "), "%Y-%m-%d")
# pobieram daty w odpowiednmim formacie

print("różnica dni jest równa: ", abs((data2-data1).days))
# pobieram ilość dni z różnicy dni oraz wyciągam z niej wartość bezwlgędną
