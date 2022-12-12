import time

def funkcja():
    czas_start = time.perf_counter()
    czas_s = 0
    i = 10
    dzialanie = 0
    while czas_s < 5:
        if(time.perf_counter() >= (czas_start + czas_s )):
            czas_s += 1
            print(i)
            i -= 1
        dzialanie += 1
    print(f"wynik działania: {dzialanie}")

funkcja()