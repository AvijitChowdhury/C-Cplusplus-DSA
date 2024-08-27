
class Order():
    def __init__(self, customer,products):
        self.customer = customer
        bill = 0
        for product in products:
            if product.stock == 'In Stock':
                self.products.append(product)
                bill += product.price
            else:
                product.stock = 'Out of Stock'
            
        self.customer.bill += bill
        
        
        
        