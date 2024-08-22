#Example of multilevel inheritance
class Family:
    def __init__(self, address)->None:
        self.address = address
    
class School:
    def __init__(self,id,level)->None:
        self.id = id
        self.level = level
class Sports:
    def __init__(self, game)->None:
        self.game = game
#multi-level inheritance
class Student(Family, School, Sports):
    def __init__(self, address, id, level, game, name)->None:
        self.name = name
        Family.__init__(self, address)
        School.__init__(self, id, level)
        Sports.__init__(self, game)
        
    def __repr__(self)->str:
        return f'Student({self.address}, {self.id}, {self.level}, {self.game}, {self.name})'
student1 = Student('Dhaka', 100, 'Masters', 'Cricket', 'Shakib')
print(student1)