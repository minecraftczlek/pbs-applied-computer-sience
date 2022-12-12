import random
from threading import Thread
import time

class Watek(Thread):
    def __init__(self, nr):
        Thread.__init__(self)
        self.nr = nr
    def run(self):
        while 1:
            x = random.randint(0,2137)
            print(f"Wątek nr: {self.nr}, wynik: {x}")
            if(x%2==0):
                time.sleep(2)

watek1 = Watek(1)
watek2 = Watek(2)

watek1.start()
watek2.start()