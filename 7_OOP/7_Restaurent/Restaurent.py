"""
1.Inheritance
2.encapsulation   
3.polymorphisom
4.abstraction
------------
use cases
1. User: base class(ABC)
2. Custer(User)
3. Employee(User)
4. Server(Employee)
5. Manager(Employee)
6. Cleaner(Employee)
7. Supplier(User)
8. Marketer(User)

1. FoodItem(ABC)
2. Pizza(FoodItem)
3. Burger(FoodItem)
4. Drinks(FoodItem)
5. Juice(FoodItem)
6. Salad(FoodItem)
"""
class Restaurant:
    def __init__(self, name, rent, menu = []) ->None:
        self.name = name
        self.chef = None
        self.server = None
        self.manager = None
        self.rent = rent
        self.orders = []
        self.menu = menu
        self.revenue = 0
        self.expense = 0
        self.balance = 0
        self. profit = 0
        
    def add_employee(self, employee_type, employee):
        if employee_type == 'chef':
            self.chef = employee
        elif employee_type == 'server':
            self.server = employee
        elif employee_type == 'manager':
            self.manager = employee
        else:
            print('Invalid employee type')
    def add_order(self, order):
        self.orders.append(order)       
    def receive_payment(self,order,  amount, customer):
        if amount>= order.bill:
            self.revenue += order.bill
            self.balance += order.bill
            customer.due_amount =0 
            return amount - order.bill
        else:
            print('Not enough money. Pay more')
            
        
    def pay_expense(self, amount, description):
        if amount < self.balance:
            self.expense += amount
            self.balance -= amount
            print(f'Expense {amount} for {description} paid')
        else:
            print(f'Not enough money to pay {amount}')
            
    def pay_salary(self, employee):
        print(f'Paying salary for {employee.name} Salary: {employee.salary}')
        if employee.salary < self.balance:
            self.balance -= employee.salary
            self.expense += employee.salary
            employee.receive_salary()
        
    def show_employee(self):
        print('------Showing Employees-------- ')
        if self.chef is not None:
            print(f'Chef: {self.chef.name} with salary {self.chef.salary}')
        if self.server is not None:
            print(f'Server: {self.server.name} with salary {self.server.salary}')
            