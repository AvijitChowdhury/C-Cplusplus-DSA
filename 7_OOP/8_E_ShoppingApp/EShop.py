"""
Create an e shopping app using OOP practices where -
Customer can create new account with email, password.
Sellers can create new account, publish products to sell.
Customers can see all products and place order.
If an order is placed monitor the stock, don’t show stock out products.

"""
""" classes are:
1. EShop
2. Product
3. Seller
4. Customer

"""
from Product import Product
from Seller import Seller
from Customer import Customer
from Order import Order
class EShop:
    def __init__(self,name ):
        self.name = name
        self.products = []
        self.sellers = []
        self.customers = []
        self.due_amount =0
        self.revenue = 0
    def add_seller(self, seller):
        self.sellers.append(seller) 
        
    def add_customer(self, customer):
        self.customers.append(customer)
        
    def create_account(self,person):
        if person.role =='seller':
            self.add_seller(person)
        if person.role == 'customer':
            self.add_customer(person)
               
    def add_product_seller(self, product,seller):
        if seller in self.sellers:
            self.products.append(product)
            seller.publish_product(product)
        else:
            print('Seller not found. Please register as seller')
            
    
        
    def add_product_customer(self, customer, product):
        if customer in self.customers:
            customer.cart.append(product)
        else:
            print('Customer not found. Please register as customer')
            
    def place_Order(self, customer):
        order = Order(customer,customer.cart)
        customer.orders.append(order)
        customer.balance -= order.bill
        
        self.revenue+= order.bill
        print(f'{customer.name} placed an order with bill {order.bill}')
        
    def show_products(self):
        print('------Showing Eshop Products-------- ')
        for product in self.products:
            if product.stock=='In Stock':
                print(f'Name: {product.name} Price: {product.price} Stock: {product.stock}')
        print('------End of Eshop Products-------- ')
        
        