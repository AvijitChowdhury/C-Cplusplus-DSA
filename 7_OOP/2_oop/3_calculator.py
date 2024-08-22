from math import ceil
class Calculator:
    brand ='Casio'
    def __init__(self,num1, num2):
        self.num1 = num1
        self.num2= num2
    
    def add(self):
        return self.num1 + self.num2
    def subtract(self):
        return self.num1 - self.num2
    def multiply(self):
        return self.num1 * self.num2
    def divide(self):
        #using ceil to round up the division      
        return ceil(self.num1 / self.num2)

my_calculator = Calculator(10, 5)
print(my_calculator.add())
print(my_calculator.subtract())
print(my_calculator.multiply())
print(my_calculator.divide())
        
    