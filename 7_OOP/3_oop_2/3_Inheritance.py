#base class, parerntclass, common attribute + functionality class
# derived class, child class, uncommon attribute + functionality class
# Inheritance:
class Gadget:
    def __init__(self, brand, price, color, origin)->None:
        self.brand = brand
        self.price = price
        self.color = color
        self.origin = origin
    def run(self):
        return f"Running laptop: {self.brand}"


class Laptop:
    def __init__(self, memory, ssd)-> None:
        self.memory = memory
        self.ssd = ssd

    
    def coding(self):
        return f'learning python and practicing'
# Inheritance class Laptop(Gadget):
# class Laptop is derived class # class Gadget is base class
#
class Phone(Gadget):
    def __init__(self,brand, price, color,origin, dual_sim) -> None:  
        self.dual_sim = dual_sim
        super().__init__(brand,price, color,origin)
        
    def phone_cell(self,number, text):
        return f'Sending SMS to: {number} with: {text}'
    def __repr__(self)-> str:
        return f'Phone({self.brand}, {self.price}, {self.color}, {self.origin}, {self.dual_sim})'

class Camera:
    def __init__(self, brand, price, color, pixel) -> None:
        
        self.pixel = pixel
        
    def change_lens(self):
        pass

# Inheritance
my_phone = Phone('Samsung',1000, 'black','Chine',True)
print(my_phone)
