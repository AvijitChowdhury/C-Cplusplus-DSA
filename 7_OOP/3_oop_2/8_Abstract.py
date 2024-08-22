 #ABSRTACT CLASS
from abc import ABC, abstractmethod

# Abstract base class
class Animal(ABC): #ABC is used to make the class abstract, it is a module
    @abstractmethod #inforce all derived class 
    #to implement this method
    def eat(self):
        print('Animal is eating')
    
    def move(self):
        pass
    
    
class Monkey(Animal):
    def __init__(self, name) -> None:
        self.category = 'Monkey'
        self.name = name
        super().__init__()
    def eat(self):
        print('Monkey is eating') #overriding the eat method
    def move(self): #overriding the move method but it is not abstract method
        print('Monkey is jumping')
           
layka = Monkey('lucky')
layka.eat()
print(layka.name)
print(layka.category)

#interface
#interface is a class that contains only abstract methods
#interface is used to implement multiple inheritance
#interface is implemented using ABC module
#interface is implemented using abstract base class
#co