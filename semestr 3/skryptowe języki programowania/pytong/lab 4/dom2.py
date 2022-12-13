from threading import Thread
import time

stanSzklanki = 0

class Barman(Thread):
    def run(self):
        global stanSzklanki
        while 1:
            if not stanSzklanki:
                print("BARMAN - rozpoczynam nalewanie")
                time.sleep(5)
                print("BARMAN - zakończyłem nalewanie")
                stanSzklanki = 1

class Klient(Thread):
    def run(self):
        global stanSzklanki
        while 1:
            if stanSzklanki:
                print("KLIENT - rozpoczynam konsumowanie")
                time.sleep(5)
                print("KLIENT - zakończyłem nalewanie")
                stanSzklanki = 0

barman = Barman().start()
klient = Klient().start()
