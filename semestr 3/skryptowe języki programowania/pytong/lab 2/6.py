class Person(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return "%s:%d" % (self.name, self.age)
    def __repr__(self):
        return str(self)
    def __call__(self, arg):
        print ('wywołanie dla', self, 'z argumentem', arg)
    def __eq__(self, o):
        print ('wywołanie eq dla', self, 'i', o)
        return self.age == o.age and self.name == o.name
    def __ne__(self, o):
        print ('wywołanie ne dla', self, 'i', o)
        return self.age != o.age or self.name != o.name
    def __lt__(self, o):
        print ('wywołanie lt dla', self, 'i', o)
        if self.name != o.name:
            return self.name < o.name
        else:
            return self.age < o.age

def exercise():
    p1 = Person('Ania', 24)
    p2 = Person('Magda', 24)
    p3 = Person('Magda', 23)
    p4 = Person('Wiktoria', 23)
    p5 = Person('Kasia', 25)
    # dzięki call obiekt może zachowywać się jak funkcja
    p1('foo')
    # eq (equals) daje możliwość porównania 2 obiektów
    print (p1 == p2)
    print (p2 == p3)
    # ne (not equals)
    print (p1 != p2)
    print (p2 != p3)
    # lt (lover then)
    print (p1 < p5)
    # widać, że < działa po wieku
    # lista
    l = [p1,p2,p3,p4,p5]
    print ('sortowanie!')
    # operator lt (<) jest również wykorzystywany do sortowania
    l.sort()
    print (l)

exercise()