from Menu import Pizza, Burger, Drinks, Menu
from Restaurent import Restaurant
from Users import Chef, Customer, Server, Manager
from Order import Order
def main():
    menu = Menu()
    pizza_1 = Pizza('Sutki pizza', 60, 'large',['cheese', 'tomato', 'mushroom'])
    menu.add_menu_item('pizza',pizza_1)
    pizza_2 = Pizza('Aloe vorta', 60, 'large',['potato','onion'])
    menu.add_menu_item('pizza',pizza_2)
    
    pizza_3 = Pizza('Sutki pizza', 60, 'large',['chicken','onion'])
    menu.add_menu_item('pizza',pizza_3)
    
    #add burger to the menu
    burger_1 = Burger('Naga Burger', 1000, 'Chicken',['cheese','onion'])
    menu.add_menu_item('burger',burger_1)
    burger_2 = Burger('Veg Burger', 1000, 'Beef',['cheese','onion'])
    menu.add_menu_item('burger',burger_2)
    
    #add drinks to the menu
    coke = Drinks('Coke', 50)
    menu.add_menu_item('drink',coke)
    coffe = Drinks('Coffe', 50)
    menu.add_menu_item('drink',coffe)
    
    #Show the menu
    #menu.show_menu()
    
    restaurent = Restaurant('Amk_Restaurent', 2000, menu)
    
    #add employees
    manager = Manager('Rustom manager', 6,'rustom@gmail.com','rustomnagar', 5000,'Feb 1 2020','Manager')
    restaurent.add_employee('manager', manager)
    
    chef = Chef('Rustom Baburchi', 6, 
                'chupa@rustom.com','rustomnagar',3500,
                'Feb 1 2020','Chef','everything')
    restaurent.add_employee('chef', chef)
    server = Server('Chotu server',6, 'nai@jai.com',
                    'restaurant',200, 'March 1 2020', 'server')
    restaurent.add_employee('server',server)
    restaurent.show_employee()
    
    
    #add customer
    #customer 1 placing an order
    customer_1 = Customer('Sakib Khan', 6, 
                          'king@khan', 'dhaka',
                          5000)
    order_1 = Order(customer_1, [pizza_1, burger_1, coke])
    customer_1.pay_for_order(order_1)
    restaurent.add_order(order_1)
    
    
    #customer one paying for order 1
    restaurent.receive_payment(order_1, 10000, customer_1)
    print('Revenue and balance after first customer: ',restaurent.revenue, restaurent.balance)
    
    #customer 2 placing an order
    customer_2 = Customer('Sakib Al Hasan', 6, 
                          'king@khan', 'dhaka',
                          5000)
    order_2 = Order(customer_2, [pizza_2, burger_2, coke])
    customer_2.pay_for_order(order_2)
    restaurent.add_order(order_1)
    restaurent.receive_payment(order_2, 10000, customer_2)
    print('Revenue and balance after second customer: ',restaurent.revenue, restaurent.balance)

    #pay rent
    restaurent.pay_expense(restaurent.rent, 'Rent')
    print('After paying rent: ',restaurent.revenue, restaurent.balance, restaurent.expense)
    
    restaurent.pay_salary(chef)
    print('After salary', restaurent.revenue, restaurent.balance, restaurent.expense)
    

#call the main fucn
if __name__ == '__main__':
    main()
    
    
    