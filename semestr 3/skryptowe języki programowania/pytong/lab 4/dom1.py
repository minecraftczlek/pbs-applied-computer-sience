from threading import Thread

class Watek1(Thread):
     def run(self):
        # liczenic ciągu fibonnaciego od 2 do 100
        wynik1 = 0
        wynik2 = 1
        for i in range(2,20):
            tmp = wynik2
            wynik2 += wynik1
            wynik1 = tmp
            print(f"Wątek id: {self.ident}, fibbonaci, i: {i}, wynik: {wynik2}")

class Watek2(Thread):
     def run(self):
        # liczenic silni 2 do 100
        wynik = 1
        for i in range(2,20):
            wynik *= i
            print(f"Wątek id: {self.ident}, silnia, i: {i}, wynik: {wynik}")

class Watek3(Thread):
    def run(self):
        print(f"Wątek id: {self.ident}, zadziałałem dopiero teraz")

watek1 = Watek1()
watek1.start()
watek2 = Watek2()
watek2.start()

while(watek1.is_alive() or watek2.is_alive()):
    pass
# czekamy aż wątki się zakończą

watek3 = Watek3().start()