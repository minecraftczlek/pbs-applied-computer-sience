def sum(a,b,c):
    sum = a + b+ c
    if(a==b and a==c):
        sum *= 2
    return sum

print(sum(10,10,10))