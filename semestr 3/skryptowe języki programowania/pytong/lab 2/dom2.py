class drink:
    def __init__(self, name, percent, price, capacity):
        self.name = name
        self.price = price
        self.percent = percent
        self.capacity = capacity
    def __add__(self, o):
        name = self.name + " z " + o.name
        price = self.price + o.price
        capacity = self.capacity + o.capacity
        percent = (self.percent/100*self.capacity + o.percent/100*o.capacity) / capacity * 100
        return drink(name, percent, price, capacity)
    def __mul__(self, n):
        return drink(self.name, self.percent, self.price*n, self.capacity*n)
    def str(self):
        print("name: ", self.name)
        print("price: ",self.price)
        print("percent: ",self.percent)
        print("capacity: ",self.capacity)
        print("------------------")
    def __lt__(self, o):
        r1 = 0
        r2 = 0
        if self.price != 0:
            r1 = self.percent*self.capacity/self.price
        if o.price != 0:
            r2 = o.percent*o.capacity/o.price
        return r1 < r2


d = []
d.append(drink("wódka", 40, 8, 50)) #0
d.append(drink("rum", 60, 9, 10))  #1   
d.append(drink("cola", 0, 2, 200)) #2
d.append(drink("lód", 0, 0, 33))   #3

d.append(d[0]+d[1]+d[2]+d[3]) #4
d[4].str()

d.append(d[0]*5) #5
d[5].str()

d.append(drink("whiskey", 70, 12, 50))    #6
d.append(drink("spirytus", 98, 25, 100))   #7

d.append( d[6] + d[2] + d[3] )    #8
d.append( d[7] + d[3] )     #9

d.sort()
d[-1].str()

