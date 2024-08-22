# poly --> many(multiple)
# morph --> shape

class Animal:
    def __init__(self, name) -> None:
        self.name = name
    def make_sound(self):
        print('animal is making sound')

class Dog(Animal):
    def __init__(self,name)->None:
        self.category = 'Dog'
        super().__init__(name)
    def make_sound(self):
        print('Dog is barking')
class Cat(Animal):
    def __init__(self,name)->None:
        self.category = 'Cat'
        super().__init__(name)
    def make_sound(self):
        print('Cat is meowing')
class Horse(Animal):
    def __init__(self,name)->None:
        self.category = 'Horse'
        super().__init__(name)
    def make_sound(self):
        print('Horse is neighing')
class Cow(Animal):
    def __init__(self,name)->None:
        self.category = 'Cow'
        super().__init__(name)
    def make_sound(self):
        print('Cow is mooing')

Animals = [Dog('Tommy'), Cat('Kitty'), Horse('Rider'), Cow('Moo')]
for animal in Animals:
    animal.make_sound()