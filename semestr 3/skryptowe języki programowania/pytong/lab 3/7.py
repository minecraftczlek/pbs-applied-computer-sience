import re 

tekst = "15 styczeń 2015, 15.01.2015, 15.1.15 26.15.1997"
regex = r"[0-3]\d\.[0-1]\d.\d{0,4}"

print(re.findall(regex, tekst))