tab = [0,1,2,3,4,5,6,7,8,9]
suma = 5

for i in tab:
    for j in tab:
        if i + j == suma:
            print(i," + ",j," = ",suma," indeksy: ",tab.index(i)," ",tab.index(j))