import re

tekst = "Kamil ka.mil@google.com, Tomek T_o-me09k@o2.pl"
regex = r"[\w.+-_]+@[\w-]+\.[\w.-]+"

print(re.findall(regex, tekst))