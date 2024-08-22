class Vehicle:
    def __init__(self,name,price)-> None:
        self.name = name
        self.price = price
    def move(self):
        pass
class Bus(Vehicle):
    def __init__(self,name, price,seat)->None: 
        super().__init__(name, price)
        self.seat = seat
    def __repr__(self) -> str:
        return f'Bus({self.name}, {self.price}, {self.seat})'  
class Truck(Vehicle):
    def __init__(self,name, price,weight)->None:
        super().__init__(name, price)
        self.weight = weight
class PickUPTruck(Truck):
    def __init__(self, name, price, weight) -> None:
        super().__init__(name, price, weight)
        
class ACBus(Bus):
    def __init__(self,name, price, seat, temperature)->None:
        self.temperature = temperature
        super().__init__(name, price, seat)
    def __repr__(self) -> str:
        return f'ACBus({self.name}, {self.price}, {self.seat}, {self.temperature})'

green_line = ACBus('Green Line', 1000, 50, 20)  
print(green_line) 
        