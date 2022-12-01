import re

tekst = "jan@onremove_thiset.pl."
regex = r"(.*)remove_this(.*)"

s = re.search(regex, tekst)
print("".join(s.groups()))