from threading import Thread
import time

class Watek(Thread):
    def run(self):
        while 1:
            print(self.ident)
            time.sleep(2)

for i in range(2):
    my_thread = Watek()
    my_thread.start()

