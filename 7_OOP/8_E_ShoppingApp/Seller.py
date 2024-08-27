class Seller:
    def __init__(self, email, password):
        self.role = 'seller'
        self.email = email
        self.password = password
        self.published_products = []
        
    def publish_product(self, product):
        self.published_products.append(product)