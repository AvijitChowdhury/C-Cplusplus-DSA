
# Polymorphism
# Polymorphism is an ability (in OOP) to use a common interface for multiple forms (data types).
# Suppose, we need to color a shape, there are multiple shapes (rectangle, square, circle). However we could use same method to color any shape. This concept is called Polymorphism.

class Shape:
    def __init__(self,name):
        self.name = name

    def draw(self):
        pass

class Circle(Shape):
    def __init__(self,name, radius):
        self.radius  = radius
        super().__init__(name)
    def area(self):
        return 3.1416*self.radius*self.radius
class Rectangle(Shape):
    def __init__(self,name, length, width):
        self.length = length
        self.width = width
        super().__init__(name)
    def area(self):
        return self.length*self.width
class Triangle(Shape):
    def __init__(self,name, base, height):
        self.base = base
        self.height = height
        super().__init__(name)
    def area(self):
        return 0.5*self.base*self.height

shapes = [Circle('Circle', 5), Rectangle('Rectangle', 5, 10), Triangle('Triangle', 5, 10)]

print([(shape.name,shape.area()) for shape in shapes]) # [{'Circle', 78.54}, {'Rectangle', 50}, {'Triangle', 25.0}]

