class Customer:
    def __init__(self,email, password):
        self.role = 'customer'
        self.email = email
        self.password = password
        self.cart = []
        self.bill = 0
        self.orders =[]
        self.balance =0