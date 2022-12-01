from urllib.parse import urlparse

o = urlparse("https://github.com/minecraftczlek/pbs-applied-computer-sience/tree/master/semestr%203/skryptowe%20j%C4%99zyki%20programowania/pytong/lab%203/8.py")

print("schemat adresowania: ", o.scheme)
print("port: ", o.port)
print("ścieżka: ", o.path)