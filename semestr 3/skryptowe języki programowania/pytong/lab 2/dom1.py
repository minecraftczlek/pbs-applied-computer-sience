class Triange:
    number_of_sides = 3
    def __init__(self, angle1, angle2, angle3):
        self.angle1 = angle1
        self.angle2 = angle2
        self.angle3 = angle3
    def check_angles(self):
        return self.angle1 + self.angle2 + self.angle3 == 180
    def __eq__(self, o):
        return self.angle1 == o.angle1 and self.angle2 == o.angle2 and self.angle2 == o.angle2
    
my_triangle = Triange(50, 60, 70)

print(my_triangle.number_of_sides)
print(my_triangle.check_angles())