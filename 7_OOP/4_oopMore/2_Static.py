# static attribute (class attribute)
# static method @staticmethod
# class method @classmethod
# differences between static method and class method
class Shopping:
    cart = [] #class attribute #static attribute
    origin = 'India'
    
    def __init__(self,name, location)->None:
        self.name = 'Jamuna Future Park' # Instance attribute
        self.location = 'Dhaka' # Instance attribute
        
    def purchase(self, item, price, amount):
        remaining = amount 
        print(f'buying: {item} for price: {price} and remaining: {remaining}')
    @staticmethod
    def multiply(a,b):
        result = a*b
        print(result)
    
    @classmethod
    def hudai_dekhi(self, item):
        print('hudai dekhi kintu kinmu just ac er hawa khaite aschi',item)
          
        
        
basundhara = Shopping('Basundhara City', 'Dhaka')
#basundhara.purchase('lungi',500,1000)
basundhara.purchase('lungi', 500, 1000)
#Shopping.purchase('lungi', 500, 1000) #TypeError: purchase() missing 1 required positional argument: 'amount'
Shopping.hudai_dekhi('genji')

Shopping.multiply(5,6)#static method can be called by class name
# and you dont have to call it by instance name

basundhara.multiply(5,6) #TypeError: multiply() takes 2 positional arguments but 3 were given