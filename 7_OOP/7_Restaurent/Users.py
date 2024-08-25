from abc import ABC, abstractclassmethod
class User(ABC):
    def __init__(self,name, phone, email, address)-> None:
        self.name = name
        self.phone = phone
        self.email = email
        self.address = address
        
        
class Customer(User):
    def __init__(self,name,money) -> None:
        self.wallet = money
        self.__order = None
        super().__init__(name)
    @property        
    def order(self, order):
        self.__order = order
    @order.setter
    def order(self, order):
        self.__order = order
    def place_order(self,order):
        self.order = order
        print(f'{self.name} placed an order of {order.items}')
    def eat_food(self,order):
        print(f'{self.name} is eating {order.items}')     
    def pay_for_order(self, amount):
        #TODO: submit the money to the manager
        pass
    def give_tips(self,tips_amount):
        pass
    def write_review(self, stars):
        print(f'{self.name} gave {stars} stars')
        
class Employee(User):
    def __init__(self, name, salary, starting_date, department) -> None:
        super().__init__(name)
        self.salary = salary
        self.starting_date = starting_date
        