napis1 = "hello.py".split(".")
napis2 = ""

for i in range(1, len(napis1)+1):
    if(napis1[-i] == "py"):
        napis1[-i] = ".py"
    napis2 += " " + napis1[-i]

print(napis2)

    