import re

tekst = "500-800-4623"
regex = re.compile(r"\d+")

print(regex.findall(tekst))