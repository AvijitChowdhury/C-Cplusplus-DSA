class Shopping:
    def __init__(self,name):
        self.name = name
        self.cart = []
        
    def add_to_cart(self,item, price, quantity):
        self.cart.append({'item':item,'price':price, 'quantity':quantity})
    
    def checkout(self, amount):
        total= 0
        for item in self.cart:
            #print(item)
            total += item['price']*item['quantity']
        print('total Price: ',total)
        if amount < total:
            print('Insufficient balance')
           
swapon = Shopping('Alan Swapon')
swapon.add_to_cart('potato', 10, 5)
print(swapon.cart)
swapon.add_to_cart('onion', 20, 10)
print(swapon.cart)
# Output: [{'item': 'potato', 'price': 10, 'quantity': 5}]
# [{'item': 'potato', 'price': 10, 'quantity': 5}, {'item': 'onion', 'price': 20, 'quantity': 10}]
# This is a simple shopping cart.
