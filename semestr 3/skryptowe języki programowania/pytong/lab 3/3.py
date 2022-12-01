import re

tekst = "345-03-02"
regex = r"-"

print(re.sub(regex, "", tekst))