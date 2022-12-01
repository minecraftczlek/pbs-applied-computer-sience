import re

tekst = "profesor Bujnowski jest uwielbiany przez wszystiech studentów"
regex = re.compile(r"Bujnowski")

print(regex.sub("*********", tekst))