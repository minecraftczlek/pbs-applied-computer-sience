import threading
import time

def toaleta():
    print("wątek", threading.current_thread().name, "wchodzi do toalety i robi comusi")
    time.sleep(5)
    print("wątek", threading.current_thread().name, "opuszcza toaletę")
for x in range(4):
    t = threading.Thread(target=toaleta)
    t.start()
    while(t.is_alive()):
        pass
    