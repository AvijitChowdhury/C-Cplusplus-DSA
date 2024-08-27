from EShop import EShop
from Seller import Seller
from Customer import Customer
from Product import Product
from Order import Order
def main():
    Aarong = EShop('Aarong')
    #add sellers 
    seller_1 = Seller('roni@gamil.com','roni123')
    
    seller_1.publish_product(Product('Saree', 5000))
    seller_1.publish_product(Product('Panjabi', 3000))
    seller_1.publish_product(Product('Salwar Kameez', 4000))
    Aarong.create_account(seller_1)
    
    #add customers
    customer_1 = Customer('asad@gmail.com','asad123')
    customer_1.add_to_cart(Product('Saree', 5000))
    customer_1.add_to_cart(Product('Panjabi', 3000))
    customer_1.add_to_cart(Product('Salwar Kameez', 4000))
    Aarong.create_account(customer_1)
    Aarong.place_Order(customer_1)
    
    
    


if __name__ == '__main__':
    main()