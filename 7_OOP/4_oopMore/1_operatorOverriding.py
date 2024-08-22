class Person:
    def __init__(self, name, age, height, weight)-> None:
        self.name = name 
        self.age = age
        self.height = height 
        self.weight = weight
    def eat(self):
        print('Person is eating body building food')
    def excercise(self):
        print('Person is doing excercise')
    
    
class Criketer(Person):
    def __init__(self,name, age, height, weight, team)->None:
        self.team = team
        super().__init__(name, age, height , weight)
    
    #overriding method
    def eat(self):
        print('Criketer is eating protein contained food')
    def excercise(self):
        print('Criket is doing excercise')
    #overriding operator
    def ___add__(self, other):
        return self.age + other.age
    def __multi__(self,other):
        return self.height*other.height
    #len overload
    def __len__(self):
        return self.height
    #greater than operator overload
    def __gt__(self,other):
        return self.age > other.age
    
sakib = Criketer("Sakib", 35, 6,91,'Bangladesh')
# sakib.eat()
# sakib.excercise()

tamim = Criketer("Tamim", 33, 5.7, 75, 'Bangladesh')