L1 = ['a','b','c','d']
L2 = ['b','c','d','e']

print(list(set(L1)-set(L2)))
print(list(set(L2)-set(L1)))
print(list(set(L1)&set(L2)))
print(list(set(L1)|set(L2)))