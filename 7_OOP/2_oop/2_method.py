class Phone:
    # Constructor
    # __init__ is a special method in Python classes
    # that is called when a new object is created
    # __init__ is also called constructor
    # self is a reference to the current instance of the class
    def __init__(self, brand, model, price):
        self.brand = brand
        self.model = model
        self.price = price
    # Methods
    def phone_info(self):
        return f"{self.brand} {self.model} costs {self.price}"
    def call(self):
        return f"{self.brand} {self.model} is calling"
    def text(self):
        return f"{self.brand} {self.model} is texting"

# Create an instance of the Phone class
# and call the phone_info method
my_phone = Phone('Apple', 'iPhone 12', 1000)
print(my_phone.phone_info())
# Output: Apple iPhone 12 costs 1000
my_phone = Phone('Samsung', 'Galaxy S21', 800)
print(my_phone.phone_info())
# Output: Samsung Galaxy S21 costs 800
print(my_phone.call())
# Output: Samsung Galaxy S21 is calling
print(my_phone.text())
# Output: Samsung Galaxy S21 is texting