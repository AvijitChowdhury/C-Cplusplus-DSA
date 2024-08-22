class Shop():
    # Class Attribute which can be accessed by all instances
    cart = []
    def __init__(self,buyer):
        self.buyer = buyer
    def add_to_cart(self,item):
        self.cart.append(item)
    def remove_from_cart(self,item):
        self.cart.remove(item)
    
mehzabin  = Shop('Mehzabin')
mehzabin.add_to_cart('Shirt')
mehzabin.add_to_cart('Shoes')
print(mehzabin.cart)
# Output: ['Shirt', 'Shoes']
nisho = Shop('Nisho')
nisho.add_to_cart('Pants')
nisho.add_to_cart('Hat')
# Output: ['Shirt', 'Shoes', 'Pants', 'Hat']
print(nisho.cart)

#second example 
class Shop():
    # Class Attribute which can be accessed by all instances
    Shopping_mall = 'Jamuna Future Park'
    def __init__(self,buyer):
        self.buyer = buyer
        self.cart = []
    def add_to_cart(self,item):
        self.cart.append(item)
    def remove_from_cart(self,item):
        self.cart.remove(item)

avijit  = Shop('Avijit')
avijit.add_to_cart('Shirt')
avijit.add_to_cart('Shoes')
print(avijit.cart)

# Output: ['Shirt', 'Shoes']
tirtho = Shop('Tirtho')
tirtho.add_to_cart('Pants')
tirtho.add_to_cart('Hat')
print(tirtho.cart)
# Output: ['Pants', 'Hat']
