import re

tekst = "Nie lubię w poniedziałki wcześnie wstawać"
print(re.findall(r"N\w*", tekst))
print(re.findall(r"\b\w{3}\b", tekst))
print(re.findall(r"\b\S", tekst))